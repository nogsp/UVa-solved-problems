#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		int wave[101010],ini,fin;
		for(int i=1;i<=n;i++){
			scanf("%d", &wave[i]);
			if(i==1) ini=wave[i];
			else if(i<=n) fin=wave[i];
		}
		wave[0]=fin;
		wave[n+1]=ini;
		int cont=0;
		for(int i=1;i<=n;i++){
			if((wave[i]>wave[i+1] and wave[i]>wave[i-1])or
				(wave[i]<wave[i+1] and wave[i]<wave[i-1])){
				cont++;
			}
		}
		printf("%d\n", cont);
	}	
	return 0;
}
