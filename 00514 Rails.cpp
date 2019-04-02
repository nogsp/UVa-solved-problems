#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n), n){
		int B[101010], A[101010];
		while(scanf("%d", &B[0]), B[0]){
			for(int i=1;i<n;i++){
				scanf("%d", &B[i]);
			}
			for(int i=0;i<n;i++){
				A[i]=i+1;
			}
			vector<int> pilha;
			int a=0, b=0;
			bool key;
			while(1){
				if(b>=n){
					key=true;
					break;
				}else{
					if(!pilha.empty()){
						if((pilha.back()!=B[b]) && (a==n)){
							key=false;
							break;
						}
					}
				}
				while(A[a]==B[b]){
					a++;
					b++;
				}
				if(b==n) continue;
				while(!pilha.empty()){
					if(pilha.back()==B[b]){
						pilha.pop_back();
						b++;
					}else{
						break;
					}
				}
				while((A[a]!=B[b]) and (a<n)){
					pilha.pb(A[a++]);
				}
			}
			if(key)printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
}
