#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
#define pb push_back
using namespace std;

int main(){
	int n, casos=0;
	while(scanf("%d", &n),n){
		int vet[101010];
		int cont=0;
		for(int i=0;i<n;i++){
			scanf("%d",&vet[i]);
			cont+=vet[i];
		}
		int med=cont/n;
		cont=0;
		for(int i=0;i<n;i++){
			if(vet[i]>med) cont+= vet[i]-med;
		}
		printf("Set #%d\n", ++casos);
		printf("The minimum number of moves is %d.\n", cont);
		printf("\n");
	}
	return 0;
}
