#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int k, m;
	while(scanf("%d %d", &k, &m), k!=0){
		int cursos[101010];
		for(int i=0;i<101010;i++) cursos[i]=0;
		for(int i=0;i<k;i++){
			int aux;
			scanf("%d", &aux);
			cursos[aux]=1;
		}
		bool key=true;
		while(m--){
			int cn, ok, cont=0;
			scanf("%d %d", &cn, &ok);
			for(int i=0;i<cn;i++){
				int aux;
				scanf("%d", &aux);
				if(cursos[aux]==1)cont++;
			}
			if(cont<ok) key=false;
		}
		if(key) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
