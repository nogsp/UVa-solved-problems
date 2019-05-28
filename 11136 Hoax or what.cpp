#include <iostream>
#include <set>
#define pb push_back
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		multiset <int> myset;
		multiset <int>:: iterator it1, it2;
		long long int cont = 0;
		for(int days = 0;days<n;days++){
			int k;
			scanf("%d", &k);
			for(int i=0;i<k;i++){
				int aux;
				scanf("%d", &aux);
				myset.insert(aux);
			}
			it1 = myset.begin();
			it2 = myset.end();
			it2--;
			cont += (*it2 - *it1);
			myset.erase(it1);
			myset.erase(it2);
		}
		printf("%lld\n", cont);
	}
	return 0;
}
