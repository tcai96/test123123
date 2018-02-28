#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int n,m,r;
    cin>>n>>m>>r;
    vvii v(n,vii());
    for(int i=0;i<m;i++){
        int idx,l,d;
        cin>>idx>>l>>d;
        v[idx].push_back(ii(d,d+l));
    }
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
    }
	for(int i=0;i<n;i++){
		for(int j=1;j<v[i].size();j++){
			if(v[i][j].first<v[i][j-1].second)return 0;
		}
	}
    return 42;
}
