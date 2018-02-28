#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

double mx=2.718281,minx=0.36788;
vi seeds={348345,10,1034,46,1945,1934,13061,3613,460134,896145,152,13945,9123,1923,2834,123161,1413241};
string name="tetration";

double lerp(double a, double b, double t){
	return (1-t)*a+t*b;
}

int main(){
	cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		double x=lerp(minx,mx,(double)rand()/RAND_MAX);
		cout<<fixed<<setprecision(6)<<x<<endl;
		file<<fixed<<setprecision(6)<<x<<endl;
		file.close();
	}
	{
		int i=seeds.size();
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		double x=mx;
		cout<<fixed<<setprecision(6)<<x<<endl;
		file<<fixed<<setprecision(6)<<x<<endl;
		file.close();
	}
	{
		int i=seeds.size()+1;
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		double x=minx;
		cout<<fixed<<setprecision(6)<<x<<endl;
		file<<fixed<<setprecision(6)<<x<<endl;
		file.close();
	}
		
}
