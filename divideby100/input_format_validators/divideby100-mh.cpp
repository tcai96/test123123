#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int main(){
	string a,b;cin>>a>>b;
	if(!cin)return 0;
	if(cin.fail())return 0;
	string bad;
	if(cin>>bad)return 0;
	if(a.size()>N)return 0;
	if(b.size()>N)return 0;
	if(a[0]<'1'||a[0]>'9')return 0;
	for(int i=1;i<a.size();i++)if(a[i]<'0'||a[i]>'9')return 0;
	if(b[0]!='1')return 0;
	for(int i=1;i<b.size();i++)if(b[i]!='0')return 0;
	return 42;
}
