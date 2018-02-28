#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>

#define MAXN (1<<17)

using namespace std;

typedef unordered_set<int> usi;

int a[MAXN], n;
usi s[2*MAXN];

void build() {
    for (int i = MAXN-1; i < 2*MAXN-1; ++i) s[i].insert(a[i-(MAXN-1)]);
    for (int i = MAXN-2; i >= 0; --i) {
        s[i] = s[2*i+1];
        for (auto x : s[2*i+2]) s[i].insert(x); // merge not supported until C++17???
    }
}

// what is the solution for the intersection of the ranges [lo, hi)
// and [i, n)?
// assumes hi > i (i.e. range is not empty)
int query(int at, int lo, int hi, int i, const usi& b) {
    bool ok = true;
    for (auto x : s[at])
        if (!(ok &= b.find(x) != b.end()))
            break;
    if (ok) return hi - max(i,lo);
    if (hi == lo+1) return 0;

    int left = (at<<1)+1, mid = lo + ((hi-lo)>>1);

    if (mid <= i) return query(left+1, mid, hi, i, b);

    int len = query(left, lo, mid, i, b);
    if (len < mid-max(i,lo)) return len;
    return len + query(left+1, mid, hi, i, b);
}

int solve() {
    int i, m;
    cin >> i >> m;

    usi b;
    while (m--) {
        int x;
        cin >> x;
        b.insert(x);
    }

    return query(0, 0, MAXN, i-1, b);
}

int main() {
    memset(a, -1, sizeof(a));
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    build();

    int q;
    cin >> q;
    while (q--) cout << solve() << endl;

    return 0;
}
