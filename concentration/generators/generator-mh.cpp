#include <bits/stdc++.h>
using namespace std;

int maxn=100000;
string name="concentration";

typedef vector<int> vi;

// first 2 cases are small
vi seeds={49501,17252,1354734,23425,58212,37,134447,23415,1392345,1312312,5273124,5212063,4253,10124,5314,4521};

int main(){
	cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		int n=rand()%maxn;
		n*=2;
		vi v(n,0),w(n,0);
		for(int j=0;j<n;j++)v[j]=j;
		for(int j=0;j<n;j++)w[j]=j;
		random_shuffle(v.begin(),v.end());
		random_shuffle(w.begin(),w.end());
		file<<(n>>1)<<endl;
		for(auto a:v)file<<a<<" ";file<<endl;
		for(auto a:w)file<<a<<" ";file<<endl;
		file.close();
	}
}
