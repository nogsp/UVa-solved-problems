#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	string s;
	int casos=0;
	while(cin >> s){
		int n;
		cin >> n;
		int ini, fin;
		cout << "Case " << ++casos << ":" << endl;
		while(n--){
			cin >> ini >> fin;
			if(ini>fin){
				int aux = ini;
				ini = fin;
				fin = aux;
			}
			char c=s[ini];
			bool key=true;;
			for(int i=ini;i<=fin;i++){
				if(s[i]!=c) key=false;
				if(!key) break;
			}
			if(key) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}
