#include <iostream> 
#include <cstdio>
#include <vector> 
#include <string>
#include <map>
#define pb push_back 
using namespace std;

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m)==2){
		int x;
		vector<vector<int>> grafo;
		grafo.resize(1000010);
		for(int i=0;i<n;i++){
			scanf("%d", &x);
			grafo[x].pb(i+1);
		}
		int k, v;
		for(int i=0;i<m;i++){
			scanf("%d %d", &k, &v);
			if(k<=grafo[v].size()){
				printf("%d\n", grafo[v][k-1]);
			}else printf("0\n");
		}
	}	
}
