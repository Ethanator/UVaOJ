#include<iostream>
#include<string>
using namespace std;

string alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string rev="A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";

int isPal(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])return false;
	}
	return true;
}

int isMir(string s){
	for(int i=0;i<s.size()/2;i++){
		if(rev[alp.find(s[i])]!=s[s.size()-i-1])return false;
	}
	if(s.size()%2==1&&rev[alp.find(s[s.size()/2])]!=s[s.size()/2])return false;
	return true;
}

int main(){
	string s;
	while(cin>>s){
		if(isPal(s)){
			if(isMir(s)){
				cout<<s<<" -- is a mirrored palindrome."<<endl;
			}else{
				cout<<s<<" -- is a regular palindrome."<<endl;
			}
		}else{
			if(isMir(s)){
				cout<<s<<" -- is a mirrored string."<<endl;
			}else{
				cout<<s<<" -- is not a palindrome."<<endl;
			}
		}
		cout<<endl;
	}
}
