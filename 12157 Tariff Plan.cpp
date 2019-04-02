#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int mile(int vet[], int n){
	int cont=0;
	for(int i=0;i<n;i++){
		int aux = vet[i];
		while(aux>=0){
			aux-=30;
			cont+=10;
		}
	}
	return cont;
}

int juice(int vet[], int n){
	int cont=0;
	for(int i=0;i<n;i++){
		int aux = vet[i];
		while(aux>=0){
			aux-=60;
			cont+=15;
		}
	}
	return cont;
}

int main(void){
	int t, casos=0;
	scanf("%d", &t);
	while(t--){
		int n, m, j, vet[101010];
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%d", &vet[i]);
		m = mile(vet, n);
		j = juice(vet, n);
		printf("Case %d: ", ++casos);
		if(m<j) printf("Mile %d\n", m);
		else if(m>j) printf("Juice %d\n", j);
		else printf("Mile Juice %d\n", m);
	}
}
