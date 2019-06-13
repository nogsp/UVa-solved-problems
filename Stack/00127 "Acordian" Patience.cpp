#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
#define vvp vector<vector<pair<char,char>>>
#define vp vector<pair<char,char>>
using namespace std;

bool isOK(pair<char,char> a, pair<char,char> b){
	if(a.first==b.first || a.second==b.second) return true;
	return false;
}

int main(void){
	string s;
	int end=1;	
	while(1){
		vvp pilhas;
		for(int k=0;k<52;k++){
			cin >> s;
			if(s=="#"){
				end=0;
				break;
			}
			pilhas.pb(vp (1,{s[0], s[1]}) );
			while(1){	
				int cont=0;
				for(int i=0;i<pilhas.size();i++){
					if(i>=3 && isOK(pilhas[i-3].back(),pilhas[i].back())){
						pair<char,char> aux=pilhas[i].back();
						pilhas[i].pop_back();
						pilhas[i-3].pb(aux);
						if(pilhas[i].empty()) pilhas.erase(pilhas.begin()+i);
						cont++;
						break;
					}
					else if(i>=1&&isOK(pilhas[i-1].back(),pilhas[i].back())){
						pair<char,char> aux=pilhas[i].back();
						pilhas[i].pop_back();
						pilhas[i-1].pb(aux);
						if(pilhas[i].empty()) pilhas.erase(pilhas.begin()+i);
						cont++;
						break;
					}
				}
				if(!cont) break;
			}	
		}
		if(!end) break;
		printf("%d ", pilhas.size());
		if(pilhas.size()>1) printf("piles remaining:");
		else printf("pile remaining:");
		for(int i=0;i<pilhas.size();i++){
			printf(" %d", pilhas[i].size());
		}
		printf("\n");
	}	
}
