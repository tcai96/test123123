#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,set<int>> dpt;

set<int> f(vvi& g, dpt& a, int v){
	if(v==0){set<int> s;s.insert(0);return s;}
	if(a.count(v))return a[v];
	set<int> ans;
	for(int i:g[v]){
		auto pset=f(g,a,i);
		for(auto a:pset)
			ans.insert(a+1);
	}
	a[v]=ans;
	return ans;
}

int n1,n2,m1,m2,q;
vvi g1,g2;
dpt a1,a2;

int main(){
	cin>>n1>>n2>>m1>>m2;
	g1.assign(n1,vi());
	g2.assign(n2,vi());
	for(int i=0;i<m1;i++){
		int a,b;cin>>a>>b;a--;b--;
		g1[b].push_back(a);
	}
	for(int i=0;i<m2;i++){
		int a,b;cin>>a>>b;a--;b--;
		g2[b].push_back(a);
	}
	auto ans1=f(g1,a1,n1-1);
	auto ans2=f(g2,a2,n2-1);
	cin>>q;
	for(int i=0;i<q;i++){
		int x;cin>>x;
		for(auto k:ans1){
			if(ans2.count(x-k)){
				cout<<"Yes\n";
				goto next;
			}
		}
		cout<<"No\n";
		next:;
	}
}
