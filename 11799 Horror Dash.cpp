#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main(void){
	int t, casos=0;
	scanf("%d", &t);
	while(t--){
		priority_queue<int> fila;
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int aux;
			scanf("%d", &aux);
			fila.push(aux);
		}
		printf("Case %d: %d\n",++casos, fila.top());
	}
}
