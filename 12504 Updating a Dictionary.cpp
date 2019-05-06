#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <ctype.h>
#define pb push_back
using namespace std;

string getWord(string& s, int& i){
	string word="";
	int tam = s.size();
	for(;i<tam;i++){
		if(isalpha(s[i])) word +=s [i];
		else{
			i++;
			return word;	
		} 
	}
}

string getVal(string& s, int& i){
	int tam = s.size();
	string val="";
	for(;i<i<tam;i++){
		if(s[i]>='0' && s[i]<='9') val += s[i];
		else{
			i--;
			return val;
		}
	}
}

void updateDic(map<string,string>& dic){
	string s, word, val;
	cin >> s;
	int op=0;
	for(int i=1,sz=s.size();i<sz;i++){
		if(s[i]=='}') return;
		if(s[i]==',') continue;
		word = getWord(s, i);
		val = getVal(s, i);
		dic[word] = val;
	}
}
int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		map <string, string> oldDic, newDic;
		updateDic(oldDic);
		updateDic(newDic);
		vector<string> changed;
		bool f=false,s=false,l=false;
		for(auto it=newDic.begin();it!=newDic.end();it++){
			if(oldDic.count(it->first)==0){
				if(!f){
					cout << "+" << it->first;
					f=true;
				}else{
					cout << "," << it->first;
				}
			}else{
				changed.pb(it->first);
			}
		}
		if(f) cout << endl;
		for(auto it=oldDic.begin();it!=oldDic.end();it++){
			if(newDic.count(it->first)==0){
				if(!s){
					cout << "-" << it->first;
					s=true;
				}else{
					cout << "," << it->first;
				}
			}
		}
		if(s) cout << endl;
		for(int i=0,sz=changed.size();i<sz;i++){
			string aux = changed[i];
			if(newDic[aux]!=oldDic[aux]){
				if(!l){
					cout << "*" << aux;
					l = true;
				}else{
					cout << "," << aux;
				}
			}
		}
		if(l) cout << endl;
		if(!f && !s && !l) cout << "No changes" << endl;
		cout << endl;
	}
	return 0;
}
