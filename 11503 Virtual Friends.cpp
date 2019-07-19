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
		pai.clear();
		int m, posi=0;
		scanf("%d", &m);
		map <string, int> appe, dic;
		string as, bs;
		int cont[1010100];
		for(int i=0;i<1010100;i++)cont[i]=1;
		while(m--){
			cin >> as >> bs;
			if(appe[as]!=1){
				dic[as] = posi;
				appe[as] = 1;
				pai.pb(posi++);
			}
			if(appe[bs]!=1){
				dic[bs] = posi;
				appe[bs] = 1;
				pai.pb(posi++);
			}
			int a = dic[as], b = dic[bs];
			if(find(a)==find(b)){
				printf("%d\n", cont[find(a)]);
				continue;
			}
			cont[find(a)] += cont[find(b)];
			join(a, b);
			printf("%d\n", cont[find(a)]);
		}
	}
    return 0; 
} 
