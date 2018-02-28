#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<int(b);i++)
#define FIL(a,b) memset((a),(b),sizeof(a))
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a),end(a)
#define PB push_back
#define FI first
#define SE second
typedef long long LL;
typedef pair<int,int> PT;
typedef complex<double> PX;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PT> VPT;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; FOR(i,0,v.size()) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T> const& p)
{ return s << '(' << p.first << ',' << p.second << ')'; }

double cp(PX a, PX b) {return (conj(a)*b).imag();}
double dp(PX a, PX b) {return (conj(a)*b).real();}
double lsp_dist(PX a, PX b, PX p) {
	return dp(b-a, p-a) > 0 && dp(a-b, p-b) > 0 ?
	       abs(cp(b-a, p-a) / abs(b-a)) :
	       min(abs(a-p), abs(b-p));
}

struct Corner {
	PX P;
	double L;
};

struct Arc {
	PX C;
	double r, theta0, theta2;
};

int N, Q;
vector<Corner> pts;
vector<PX> lpts;
vector<Arc> arcs;

double sv(double x, double y) {
	PX px(x, y);
	double ans = INFINITY;
	for (int i = 1; i < SZ(lpts); i += 2) {
		ans = fmin(ans, lsp_dist(lpts[i], lpts[(i+1)%SZ(lpts)], px));
	}
	for (Arc const& a : arcs) {
		double gt = arg(px - a.C);
		if ((a.theta2 > a.theta0 && a.theta0 < gt && gt < a.theta2) ||
				(a.theta2 < a.theta0 && (gt > a.theta0 || gt < a.theta2))) {
			ans = fmin(ans, abs(px - (a.C + polar(a.r, gt))));
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &Q);
	pts.resize(N);
	FOR(n,0,N) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		pts[n].P = PX(x,y);
	}
	FOR(n,0,N) {
		scanf("%lf", &pts[n].L);
	}
	FOR(n,0,N) {
		Corner& c0 = pts[(n-1+N)%N];
		Corner& c1 = pts[n];
		Corner& c2 = pts[(n+1)%N];
		PX v0 = c0.P - c1.P, v2 = c2.P - c1.P;
		PX q0 = c1.P + (v0/abs(v0)) * c1.L;
		PX q2 = c1.P + (v2/abs(v2)) * c1.L;
		lpts.push_back(q0);
		lpts.push_back(q2);
		double theta = fabs(arg(v0/v2));
		double x = c1.L / cos(0.5*theta);
		Arc a;
		a.r = c1.L * tan(0.5*theta);
		a.C = c1.P + x*((v0/abs(v0))*polar(1.0, 0.5*arg(v2/v0)));
		a.theta0 = arg(q0-a.C);
		a.theta2 = arg(q2-a.C);
		if (fmod(a.theta2-a.theta0+4.0*M_PI, 2.0*M_PI) > M_PI) swap(a.theta0, a.theta2);
		arcs.push_back(a);
		//cout << "Got " << c1.P << " center " << a.C << " r " << a.r << " q0 " << q0 << " q2 " << q2 << endl;
	}
	FOR(q,0,Q) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		printf("%.10f\n", sv(x, y));
	}
}
