#include <bits/stdc++.h>
using namespace std;

double n,a;
double pi=3.141593;

int main(){
	cin>>a>>n;
	// pi r r = a
	double r=sqrt(a/pi);
	// pi 2 r = c
	double c=pi*r*2;
	cout<<(c>n?"Need more materials!":"Diablo is happy!")<<endl;
}
