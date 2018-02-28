#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi seeds={29460,34281,548023,2450,680,32403,83,98320,69};

string name="diablo";

int main(){
		cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		double x=(double)rand()/RAND_MAX*99+1;
		double r=sqrt(x/3.141593);
		double y=-1;
		if(rand()%2){
			y=x+(double)rand()/RAND_MAX*(1000-x);
			// ugh.. just to be sure?
			if(y>1000)y=1000;
		}else{
			y=(double)rand()/RAND_MAX*x;
		}
		file<<fixed<<setprecision(6)<<x;
		file<<' ';
		file<<fixed<<setprecision(6)<<y;
		file<<endl;
		file.close();
	}

}
