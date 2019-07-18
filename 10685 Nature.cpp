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
	int n, m;
	while(scanf("%d %d", &n, &m), n){
		int maxi=-1;
		pai.resize(n);
		string as, bs;
		map <string, int> dic;
		for(int i=0;i<n;i++) pai[i] = i;
		for(int i=0;i<n;i++){
			cin >> as;
			dic[as]=i;
		}
		while(m--){
			int a, b;
			cin >> as >> bs;
			join(dic[as], dic[bs]);
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
