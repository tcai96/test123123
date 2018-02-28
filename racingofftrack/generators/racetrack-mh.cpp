#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef complex<double> dd;
typedef vector<dd> vdd;

int maxxy=100000;

vi seeds={34656,7187,57189,78137,893765,7269,782075,324908,
98702313,30454,35408,6879320,546,687065,68706,32178,6871};

//vi seeds={1};

string name="racetrack";


int main(){
	cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		int n=rand()%100000;
		int q=rand()%100;
		file<<n<<' '<<q<<'\n';
		vector<double> l(n,0);
		vdd v(n,dd(0,0));
		for(int i=0;i<n;i++){
			double x=(double)rand()/RAND_MAX*maxxy;
			double y=(double)rand()/RAND_MAX*maxxy;
			if(rand()&1)x=-x;
			if(rand()&1)y=-y;
			file<<fixed<<setprecision(6)<<x;
			file<<' ';
			file<<fixed<<setprecision(6)<<y;
			file<<'\n';
			v[i]=dd(x,y);
		}
		for(int i=0;i<n;i++){
			l[i]=abs(v[i]-v[(i+1)%n]);
		}
		for(int i=0;i<n;i++){
			double d=(double)rand()/RAND_MAX;
			d*=max(l[i],l[(i+n-1)%n]);
			l[i]-=d;
			l[(i+n-1)%n]-=d;
			file<<fixed<<setprecision(6)<<d;
			file<<'\n';
		}
		for(int i=0;i<q;i++){
			double x=(double)rand()/RAND_MAX*maxxy;
			double y=(double)rand()/RAND_MAX*maxxy;
			if(rand()&1)x=-x;
			if(rand()&1)y=-y;
			file<<fixed<<setprecision(6)<<x;
			file<<' ';
			file<<fixed<<setprecision(6)<<y;
			file<<'\n';
			v[i]=dd(x,y);
		}
		file.close();
	}

		
}
