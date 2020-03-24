#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int main(void){
	int casos=0, c;
	scanf("%d", &c);
	while(c--){
		int l, m;
		scanf("%d %d", &l, &m);
		l*=100;
		char s[1010];
		int tam;
		queue<int> left, right;
		while(m--){
			scanf("%d %s", &tam, s);
			if(s[0]=='l') left.push(tam);
			else right.push(tam);
		}
		int side=0, cont=0, resp=0;
		while(1){
			cont=0;
			if(left.empty() && right.empty()) break;
			if(!side){
				side=1;
				while(cont+left.front()<=l and !left.empty()){
					cont+=left.front();
					left.pop();
				}
			}else{
				side=0;
				while(cont+right.front()<=l and !right.empty()){
					cont+=right.front();
					right.pop();
				}
			}
			resp++;
		}
		printf("%d\n", resp);
	}
}
