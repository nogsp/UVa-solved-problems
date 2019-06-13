#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)==1){
		int vet[101010];
		bool dp[101010];
		for(int i=0;i<n;i++){
			scanf("%d", &vet[i]);
			dp[i]=false;
		}
		for(int i=0;i<n-1;i++){
			int aux = abs(vet[i]-vet[i+1]);
			if(aux>3000) continue;
			dp[aux] = true;
		}
		bool key=true;
		for(int i=1;i<n;i++){
			if(!dp[i]){
				key=false;
				break;
			}
		}
		if(key) printf("Jolly\n");
		else printf("Not jolly\n");
	}	
	return 0;
}
