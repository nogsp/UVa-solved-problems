#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
using namespace std;

map <string, int> mapa;
int id;
void back(){
	string s="";
	queue <string> fila;
	for(char c='a';c<='z';c++){
		fila.push(s+c);
		mapa[s+c] = id++;	
	} 
	while(!fila.empty()){
		s = fila.front();
		fila.pop();
		if(s.size()==5) continue;
		for(char c=s.back()+1;c<='z';c++){
			mapa[s+c] = id++;
			fila.push(s+c);
		}
	}
}

int main(){
	string s;
	id=1;
	back();
	while(cin >> s){
		cout << mapa[s] << endl;
	}
	return 0;
}
