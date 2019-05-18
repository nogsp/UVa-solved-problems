#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mss map <string, string>
#define msvs map <string, vector<string>>
using namespace std;

void getGenes(mss& tipo, msvs& pai, string& son){
	if(!tipo.count(son)){
		string first = pai[son][0];
		string second = pai[son][1];
		getGenes(tipo,pai,first);
		getGenes(tipo,pai,second);
		first = tipo[first];
		second = tipo[second];
		if((first=="dominant" && (second!="non-existent")) ||
			(second=="dominant" && (first!="non-existent"))){
			tipo[son] = "dominant";
		}else if((first=="dominant" || second=="dominant") ||
		 (first!="non-existent" && second!="non-existent")){
			tipo[son] = "recessive";
		}else tipo[son] = "non-existent";
	}	
}

int main(){
	int n;
	scanf("%d", &n);
	string first, second;
	vector <string> undone;
	mss tipo;
	msvs pai;
	while(n--){
		cin >> first >> second;
		if(second == "dominant" || second == "recessive" || second == "non-existent"){
			tipo[first] = second;
		}
		else{
			pai[second].pb(first);
			undone.pb(second);
		}
	}
	for(int i=0, sz=undone.size();i<sz;i++){
		if(tipo.count(undone[i])) continue;
		getGenes(tipo,pai,undone[i]);
	}
	for(auto it=tipo.begin();it!=tipo.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
