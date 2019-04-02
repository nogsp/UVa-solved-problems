#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	int nb, n;
	while(scanf("%d %d", &nb, &n), nb!=0 && n!=0){
		int bancos[101010];
		for(int i=1;i<=nb;i++){
			scanf("%d", &bancos[i]);
		}
		while(n--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			bancos[a]-=c;
			bancos[b]+=c;
		}
		bool key=true;
		for(int i=1;i<=nb;i++){
			if(bancos[i]<0) key=false;
		}
		if(key) printf("S\n");
		else printf("N\n");
	}
}
