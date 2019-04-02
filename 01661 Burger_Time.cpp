#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int n;
	string s;
	while(scanf("%d", &n),n!=0){
		cin >> s;
		int dist=9999999, aux;
		int local=-1, pos;
		for(int i=0;i<n;i++){
			if(s[i]=='Z'){
				dist=0;
				break;
			}
			if(s[i]=='R' && (local==-1 || local==0)){
				pos=i;
				local=0;
			}
			if(s[i]=='D' && (local==-1 || local==1)){
				pos=i;
				local=1;
			}
			if(s[i]=='R' && local==1){
				dist = min(dist,i-pos);
				local=0;
				pos=i;
			}
			if(s[i]=='D' && local==0){
				dist = min(dist,i-pos);
				local=1;
				pos=i;
			}
		}
		printf("%d\n", dist);
	}
	return 0;
}
