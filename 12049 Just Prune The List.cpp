#include <iostream>
#include <set>
using namespace std;

int main(){
	int t, n, m, aux;
	scanf("%d", &t);
	while(t--){
		multiset <int> myset;
		multiset <int> :: iterator it;
		int removed = 0;
		scanf("%d %d", &n, &m);
		while(n--){
			scanf("%d", &aux);
			myset.insert(aux);
		}
		while(m--){
			scanf("%d", &aux);
			it = myset.find(aux);
			if(it == myset.end()) removed++;
			else myset.erase(it);
		}
		removed += myset.size();
		printf("%d\n", removed);
	}
	return 0;
}
