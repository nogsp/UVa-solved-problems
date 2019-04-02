#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int h,l;
	while(scanf("%d %d", &h, &l), h){
		int cont=0, vet[101010];
		for(int i=0;i<l;i++){
			scanf("%d", &vet[i]);
			if(!i){
				cont+=h-vet[i];
			}else{
				if(vet[i]!=h && vet[i-1]-vet[i]>0){
					cont += vet[i-1]-vet[i];
				}
			}
		}
		printf("%d\n", cont);
	}
	return 0;
}
