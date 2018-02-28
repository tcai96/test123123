#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <cstdio>

using std::vector;
using std::complex;

//typedef long double ld;
typedef double ld;

typedef complex<ld> Complex;

inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }

vector<Complex> FFT(vector<Complex> v, int dir=1) {
  Complex wm,w,u,t; int n = v.size(); vector<Complex> V(n);
  for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n))
    V[a] = v[k] / ld(dir>0 ? 1 : n);
  for (int m=2; m<=n; m<<=1) {
    wm = std::polar( (ld)1, (ld)(dir*2*M_PI/m));
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } return V; }

vector<vector<Complex>> rfft2(vector<vector<Complex>> a, int dir=1) {
    vector<vector<Complex>> t = a;

    // rows
    for(unsigned i = 0; i < t.size(); i ++) {
        t[i] = FFT(t[i], dir);
    }

    // cols
    for(unsigned i = 0; i < a.front().size(); i ++) {
        vector<Complex> col;
        for(unsigned j = 0; j < a.size(); j ++) col.push_back(t[j][i]);
        col = FFT(col, dir);
        for(unsigned j = 0; j < a.size(); j ++) t[j][i] = col[j];
    }
    return t;
}

std::vector<std::vector<bool>> parse() {
    std::vector<std::vector<bool>> result;
    int W, H;
    std::cin >> W >> H;
    for(int y = 0; y < H; y ++) {
        result.push_back(std::vector<bool>());
        for(int x = 0; x < W; x ++) {
            int v;
            std::cin >> v;
            result.back().push_back(v == 1);
        }
    }
    return result;
}

unsigned roundup(unsigned v){
    v --;
    v |= (v >> 1);
    v |= (v >> 2);
    v |= (v >> 4);
    v |= (v >> 8);
    v |= (v >> 16);
    return v + 1;
}

std::vector<std::vector<Complex>> transform(const std::vector<std::vector<bool>> &in) {
    std::vector<std::vector<Complex>> result;
    for(unsigned int i = 0; i < in.size(); i ++) {
        result.push_back(std::vector<Complex>());
        for(auto b : in[i]) result.back().push_back(b?Complex((ld)1,0):Complex((ld)-1,0));
    }
    return result;
}

void pad(std::vector<std::vector<Complex>> &m, int w, int h) {
    for(auto &row : m) {
        row.resize(w, Complex(0,0));
    }
    m.resize(h, std::vector<Complex>(w, Complex(0,0)));
}

int main() {
    auto needle = parse();
    auto haystack = parse();
    auto needle_t = transform(needle);
    auto haystack_t = transform(haystack);

    // pad up to power of two
    pad(needle_t, roundup(needle.front().size() + haystack.front().size() - 1),
        roundup(needle.size() + haystack.size() - 1));
    pad(haystack_t, roundup(needle.front().size() + haystack.front().size() - 1),
        roundup(needle.size() + haystack.size() - 1));

    // FFT
    auto needle_tf = rfft2(needle_t);
    needle_t.clear();
    auto haystack_tf = rfft2(haystack_t);
    haystack_t.clear();
    // element-wise multiplication by conjugate of needle_tf
    for(unsigned i = 0; i < needle_tf.size(); i ++) {
        for(unsigned j = 0; j < needle_tf.front().size(); j ++) {
            haystack_tf[i][j] *= std::conj(needle_tf[i][j]);
        }
    }
    needle_tf.clear();

    // inverse FFT
    auto result = rfft2(haystack_tf, -1);

    // find best coordinates
    std::vector<std::pair<int, int>> bestloc;
    ld bestval = -1e50;
    for(unsigned j = 0; j <= haystack.front().size() - needle.front().size(); j ++) {
        for(unsigned i = 0; i <= haystack.size() - needle.size(); i ++) {
            ld res = int(result[i][j].real()+0.5);
            if(res > bestval) {
                bestloc.clear();
                bestval = res;
                bestloc.push_back(std::make_pair(j,i));
            }
            else if(res == bestval) {
                bestloc.push_back(std::make_pair(j,i));
            }
        }
    }

    // print out coordinates
    for(auto e : bestloc) {
        std::cout << e.first << " " << e.second << std::endl;
    }

    return 0;
}
