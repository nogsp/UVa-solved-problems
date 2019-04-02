#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(void){
	int t, casos=0;
	scanf("%d", &t);
	printf("Lumberjacks:\n");
	while(t--){
		int vet[101010], ordvet[101010];
		for(int i=0;i<10;i++){
			scanf("%d", &vet[i]);
			ordvet[i]=vet[i];
		}
		sort(ordvet, ordvet+10);
		bool key=true;
		for(int i=0;i<10;i++){
			if(vet[i]!=ordvet[i]) key = false;
		}
		if(key) printf("Ordered\n");
		else{
			key=true;
			for(int i=0, j=9;i<10;i++,j--){
				if(vet[i]!=ordvet[j]) key = false;
			}
			if(key) printf("Ordered\n");
			else printf("Unordered\n");
		}
	}
}
