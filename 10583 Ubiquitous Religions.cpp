#include <cstdio> 
#include <iostream> 
#include <vector> 
#include <map> 
#define pb push_back 
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
	int n, m, casos=0;
	while(scanf("%d %d", &n, &m),n || m){
		pai.resize(n);
		for(int i=0;i<n;i++) pai[i] = i;
		int a, b;
		while(m--){
			scanf("%d %d", &a, &b);
			join(a-1, b-1);
		}
		map <int, int> dic;
		int rc=0;
		for(int i=0;i<n;i++){
			if(dic[find(pai[i])]!=1){
				dic[find(pai[i])] = 1;
				rc++;
			}
		}
		printf("Case %d: %d\n", ++casos, rc);
	}	 
    return 0; 
} 
