#include <bits/stdc++.h>
using namespace std;

typedef vector<unsigned int> vi;
vi seeds={56403,687623,87984,65750,1357,793,678006,120,3429};
//vi seeds={2};

string name="sequence";

int maxn=10000;

int main(){
		cout<<"running this will generate all test case files, type 1 if you are sure to continue"<<endl;
	int asdf;cin>>asdf;
	if(asdf==1)
	
	for(int i=0;i<seeds.size();i++){
		ofstream file;
		file.open(name+"-"+(i+1<10?"0":"")+to_string(i+1)+".in");
		srand(seeds[i]);
		
		int n=rand()%maxn+1;
		
		//set of all number in the sequence
		vi ss;
		int ssn=rand()%n+1;
		for(int i=0;i<ssn;i++)ss.push_back(rand()%2147483647);
		
		vi seq(n,0);
		for(int i=0;i<n;i++)seq[i]=ss[rand()%ssn];
		
		file<<n<<endl;
		for(int i:seq)file<<i<<' ';file<<endl;
		
		int mq=rand()%maxn+1;
		int tq=maxn;
		int cq=0;
		vi is;vector<set<unsigned int>> sets;
		while(1){
			if(cq>=mq)break;
			cq++;
			int i=rand()%n;
			int ans=rand()%(n-i)+1;
			set<unsigned int> s;
			for(int j=i;j<i+ans;j++){s.insert(seq[j]);
		//	cout<<i<<'\t'<<ans<<'\t'<<j<<endl;
			}
			
			int m=s.size();
			
			is.push_back(i);
			sets.push_back(s);
			tq-=m;
			if(tq<=0)break;
		}
		file<<is.size()<<endl;
		for(int i=0;i<is.size();i++){
			file<<is[i]+1<<' '<<sets[i].size();
			for(int j:sets[i])file<<' '<<j;
			file<<endl;
		}
		
		file.close();
	}

}
