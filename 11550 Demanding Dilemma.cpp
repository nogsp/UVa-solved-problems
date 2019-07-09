#include <iostream> 
#include <cstdio>
#include <vector> 
#include <string>
#include <map>
#define pb push_back 
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, x;
		int mat[1010][1010];
		int grafo[1010][1010];
		map <int, int> mapa;
		scanf("%d %d", &n, &m);
		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				grafo[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d", &x);
				mapa[j]+=x;
				mat[i][j]=x;
			}
		}
		bool ok=true;
		for(auto it=mapa.begin();it!=mapa.end();it++){
			if(it->second!=2){
				ok=false;
			}
		}
		if(ok){
			for(int j=0;j<m;j++){
				bool first=false;
				int uni, duni;
				for(int i=0;i<n;i++){
					if(mat[i][j]==1 && first==false){
						first=true;
						uni=i;
					}
					else if(mat[i][j]==1){
						duni=i;
					}
				}
				if(grafo[uni][duni]==0){
					grafo[uni][duni]=1;
				}else{
					ok = false;
					break;
				}
			}
		}	
		if(ok) printf("Yes\n");
		else printf("No\n");
	}
}
