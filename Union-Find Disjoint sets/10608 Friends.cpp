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
		int n, m, maxi=-1;
		scanf("%d %d", &n, &m);
		pai.resize(n);
		for(int i=0;i<n;i++) pai[i] = i;
		while(m--){
			int a, b;
			scanf("%d %d", &a, &b);
			join(a-1, b-1);
		}
		vector <int> counter(n);
		for(int i=0;i<n;i++) counter[i] = 0;
		for(int i=0;i<n;i++){
			counter[find(pai[i])]++;
		}
		for(int i=0;i<n;i++){
			if(counter[i]>maxi){
				maxi = counter[i];
			}
		}
		printf("%d\n", maxi);
	}
    return 0; 
} 
