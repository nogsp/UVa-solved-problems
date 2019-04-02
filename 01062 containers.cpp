#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;

void find_cont(vector<vector<char>>& pilhas, char c){
	for(int i=0;i<pilhas.size();i++){
		for(int j=0;j<pilhas[i].size();j++){
			if(pilhas[i].back()>=c){
				pilhas[i].pb(c);
				return;
			}
		}
	}
	pilhas.pb(vector<char>(1,c));
}

int main(void){
  	string s;
  	int casos=0;
  	while(cin >> s, s!="end"){
  		int tam=s.size();
  		vector<vector<char>> pilhas;
  		for(int i=0;i<tam;i++){
  			if(pilhas.empty()){
  				pilhas.pb(vector<char>(1,s[i]));
  				continue;
  			}
  			find_cont(pilhas, s[i]);
  		}
  		cout << "Case " << ++casos << ": ";
  		cout << pilhas.size() << endl;
  	}
    return 0;
}
