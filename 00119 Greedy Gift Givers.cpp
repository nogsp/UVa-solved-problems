#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int n;
	int ajuda=0;
	while(cin >> n){
		if(ajuda) cout << endl;
		map <string, int> friends;
		string list[100];
		for(int i=0;i<n;i++){
			cin >> list[i];
			friends[list[i]]=0;
		}	
		string saux;
		int valor, nd, dvalor;
		for(int i=0;i<n;i++){
			cin >> saux >> valor >> nd;
			if(nd) dvalor = valor/nd;
			else dvalor = 0; 
			friends[saux]-= (dvalor*nd);
			for(int j=0;j<nd;j++){
				cin >> saux;
				friends[saux]+=dvalor;
			}
		}
		for(int i=0;i<n;i++){
			cout << list[i] << " " << friends[list[i]];
			cout << endl;
		}

	}
}
 
