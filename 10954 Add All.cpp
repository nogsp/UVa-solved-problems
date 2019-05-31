#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		long long int cont1, cont2, resp=0, aux, dale=0;
		priority_queue <long long int, vector<long long int>, greater<long long int>> heap;
		while(n--){
			scanf("%lld", &aux);
			heap.push(aux);
		}
		while(1){
			cont1 = heap.top();
			heap.pop();
			cont1 += heap.top();
			heap.pop();
			resp+=cont1;
			if(heap.empty()) break;
			heap.push(cont1);

		}
		cout << resp << endl; 
	}
	return 0;
}
