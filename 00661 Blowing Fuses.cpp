#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int n, m, pot;
	int casos=0;
	int ajuda=0;
	while(scanf("%d %d %d", &n, &m, &pot),n!=0||m!=0||pot!=0){
		int devices[101010], devpot[101010];
		for(int i=0;i<101010;i++) devices[i]=0;

		for(int i=1;i<=n;i++){
			scanf("%d", &devpot[i]);
		}
		int cont=0, aux, maximo=0, key=0;
		while(m--){
			scanf("%d",&aux);
			if(devices[aux]==0){
				devices[aux]=1;
				cont+=devpot[aux];

			}
			else{
				devices[aux]=0;
				cont-=devpot[aux];
			}
			if(cont>maximo) maximo = cont;
			if(cont>pot){
				key=1;
			}	
		}
		printf("Sequence %d\n", ++casos);
		if(key){
			printf("Fuse was blown.\n");
		} 
		else{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", maximo);
		}
		printf("\n");
	}
}
