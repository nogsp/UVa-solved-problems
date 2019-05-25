#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define pb push_back
using namespace std;

int main(){
	int k, m, n, aux, casos=0;
	scanf("%d", &k);
	while(k--){
		scanf("%d %d", &m, &n);
		multiset <int> blackBox;
		multiset <int> :: iterator it, end;
		vector <int> A, u;
		for(int i=0;i<m;i++){
			scanf("%d", &aux);
			A.pb(aux);
		}
		for(int i=0;i<n;i++){
			scanf("%d", &aux);
			u.pb(aux);
		}
		int tam=0, a=0, dale=0;
		if(casos++>0) printf("\n");
		for(int i=0;i<n;i++){
			while(tam<u[i]){
				blackBox.insert(A[a++]);
				tam++;
				if((i>0) && A[a-1]<*it)	it = prev(it);
			}
			if(i==0) it = blackBox.begin();	
			else{
				end = blackBox.end();
				if(it!=end) advance(it,1);
			}
			cout << *it << endl; 
		}
	}
	return 0;
}
