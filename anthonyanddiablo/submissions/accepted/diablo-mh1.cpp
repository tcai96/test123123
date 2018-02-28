#include <bits/stdc++.h>
using namespace std;

double n,a;
double pi=3.141593;

int main(){
	cin>>a>>n;
	// 2 pi r=n
	double r=n/pi/2;
	double x=pi*r*r;
	cout<<(x<a?"Need more materials!":"Diablo is happy!")<<endl;
}
