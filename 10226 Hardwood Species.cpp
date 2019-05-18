#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
using namespace std;

int main(){
	int t, casos=0;
	scanf("%d", &t);
	cin.ignore(2);
	string line;
	while(t--){
		if(casos++) printf("\n");
		map <string, long double> mapa;
		long double cont = 0.0000;
		while(getline(cin,line) && line!=""){
			mapa[line] += 1.0000;
			cont += 1.0000;
		}
		for(auto it=mapa.begin();it!=mapa.end();it++){
			cout << it->first << " ";
			long double num = (double) it->second;
			printf("%.4llf\n", ((double)(100.0000*num)/cont));
		}
	}
	return 0;
}
