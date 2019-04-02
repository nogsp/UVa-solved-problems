#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	int a, b;
	while(scanf("%d %d", &a, &b),a!=-1 || b!=-1){
		int cont=0;
		for(int i=a;i!=b;i++){
			if(i==99) i=-1;
			cont++;
		}
		int cont2=0;
		for(int i=a;i!=b;i--){
			if(i==0) i=100;
			cont2++;
		}
		printf("%d\n", min(cont,cont2));
	}
}
