#include <cstdio> 
#include <iostream> 
#include <vector> 
#include <map> 
#define pb push_back 
#define vvi vector<vector<int>> 
using namespace std; 
vector<int> pai;

int find(int x){
	if(x==pai[x]) return x;
	else return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	pai[b] = a;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, aux;
		scanf("%d %d", &n, &m);
		pai.resize(n);
		vector <int> point(n);
		for(int i=0;i<n;i++){
			pai[i] = i;
			scanf("%d", &aux);
			point[i] = aux;
		}
		while(m--){
			int a, b;
			scanf("%d %d", &a, &b);
			if(find(a)==find(b)) continue;
			point[find(a)] += point[find(b)];
			join(a, b);
		}
		bool key=true;
		for(int i=0;i<n;i++){
			if(point[find(i)]!=0) key=false;
		}
		if(key) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
    return 0; 
} 
