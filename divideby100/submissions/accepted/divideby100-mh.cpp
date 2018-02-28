#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int l=0;
	cin>>s;
	{
		string x;cin>>x;l=x.size()-1;
	}
	if(s.size()>l){
		vector<char> v;
		for(int i=0;i<s.size()-l;i++){
			v.push_back(s[i]);
		}
		v.push_back('.');
		for(int i=s.size()-l;i<s.size();i++){
			v.push_back(s[i]);
		}
		while(1){
			if(v.back()=='0')v.pop_back();
			else if(v.back()=='.'){v.pop_back();break;}
			else break;
		}
		for(char c:v)cout<<c;cout<<endl;
	}else{
		vector<char> v;
		v.push_back('0');
		v.push_back('.');
		for(int i=0;i<l-s.size();i++){
			v.push_back('0');
		}
		for(int i=0;i<s.size();i++)v.push_back(s[i]);
		
		while(1){
			if(v.back()=='0')v.pop_back();
			else if(v.back()=='.'){v.pop_back();break;}
			else break;
		}
		for(char c:v)cout<<c;cout<<endl;
	}
}
