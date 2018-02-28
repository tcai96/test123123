#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<string> scales={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
vector<int> p={0,2,4,5,7,9,11};

vi seeds={23894,10932,865,7,68706,655,9138240,103894,9172,986,12384};
string name="scales";

int main(){
	cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	
	
	if(asdf==1)
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		int n=1+rand()%100;
		file<<n<<endl;
		int x=rand()%12+1;
		cout<<x<<endl;
		vector<int> ss(x,-1);
		for(int i=0;i<x;i++){
			ss[i]=rand()%12;
		}
		for(int i=0;i<n;i++){
			file<<scales[ss[rand()%x]]<<' ';
		}
		file<<endl;
		file.close();
	}
}
