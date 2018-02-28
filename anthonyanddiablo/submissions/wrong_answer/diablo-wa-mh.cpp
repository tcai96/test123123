#include <bits/stdc++.h>
using namespace std;
double n,a;
double pi=3.141593;

int main(){
	cin>>a>>n;
	n/=4;
	n*=n;
	cout<<(n<a?"Need more materials!":"Diablo is happy!")<<endl;
}
