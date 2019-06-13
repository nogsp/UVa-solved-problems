#include <iostream>
#include <vector>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define pb push_back 
using namespace std;

int mark[101010], counter;
vector<vii> grafo;
vi vec;

void dfs(int u){
	counter++;
	mark[u] = 1;
	for(int j=0, sz=grafo[u].size();j<sz;j++){
		ii x = grafo[u][j];
		if(mark[x.first]!=1) dfs(x.first);
	}
}

int main(){
	int k;
	char f,s;
	int fx,sx;
	string str;
	scanf("%d", &k);
    while(k--){
		grafo.clear();
		vec.clear();
		int acorn=0, tree=0, maximo=-1;
		while(cin >> str, str[0]!='*'){
			f = str[1];
			fx = f - 'A';
			s = str[3];
			sx = s -'A';
			if(sx>=grafo.size() || fx>=grafo.size()){
			    grafo.resize(max(fx,sx)+1);
			}
			grafo[fx].pb({sx,1});
			grafo[sx].pb({fx,1});
		}
		cin >> str;
		for(int i=0, sz=str.size();i<sz;i+=2){
			fx = str[i] - 'A';
			vec.pb(fx);
			if(fx>maximo) maximo = fx;
		}
		if(maximo>=grafo.size()) grafo.resize(maximo+1);
		for(int i=0, sz=vec.size();i<sz;i++){
			mark[vec[i]] = -1;
		}
		for(int i=0,sz=vec.size();i<sz;i++){
			if(mark[vec[i]]==-1){
				counter = 0;
				dfs(vec[i]);
				if(counter==1) acorn++;
				else tree++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
		
	}
	return 0;
}
