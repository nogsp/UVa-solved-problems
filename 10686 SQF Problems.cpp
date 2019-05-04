#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <ctype.h>
#include <set>
#define pb push_back
using namespace std;

string getWord(string& s){
	int tam = s.size();
	string resp="";
	for(int i=0;i<tam;i++){
		if(isalpha(s[i])) resp+=s[i];
	}
	return resp;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int c;
		scanf("%d", &c);
		if(c==0) cin.ignore(1);
		vector <pair <string,int>> entrada;
		map <string, vector<string>> finder;
		map <string, int> counter;
		map <string, int> found;
		for(int k=0;k<c;k++){
			string s;
			int w, p;
			cin >> s >> w >> p;
			cin.ignore();
			entrada.pb({s, p});
			set <string> myset;
			for(int i=0;i<w;i++){
				string sAux;
				getline(cin, sAux);
				sAux = getWord(sAux);
				if(myset.count(sAux)==0)finder[sAux].pb(s);
				myset.insert(sAux);
			}	
		}
		string line;
		while(getline(cin,line)){
			int tam = line.size();
			if(tam<1) break;
			string buffer="";
			for(int i=0;i<tam;i++){
				if(!isalpha(line[i])){
    				if(buffer!=""){
    					dale:
    					if(found[buffer]!=1){
        					int tamx = finder[buffer].size();
        					for(int it=0;it<tamx;it++){
        						string counterAux = finder[buffer][it];
        						counter[counterAux]++; 
        					}
        					found[buffer]=1;
    					}
    					buffer = "";
				    }	
				}else{
					buffer += line[i];
					if(i==tam-1) goto dale;
				}
			}
		}
		int tamEnt = entrada.size();
		int printado=0;
		for(int i=0;i<tamEnt;i++){
			if(entrada[i].second<=counter[entrada[i].first]){
				if(printado++) cout << ",";
				cout << entrada[i].first;
			}
		}
		if(printado==0) cout << "SQF Problem.";
		cout << endl;
	}
	return 0;
}
