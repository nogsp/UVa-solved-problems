#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int ndays, pn, h;
		scanf("%d %d", &ndays, &pn);
		vector<int> days(ndays);
		for(int i=0;i<pn;i++){
			scanf("%d", &h);
			for(int j=h-1;j<ndays;j+=h){
				days[j]=1;
			}
		}
		int cont=0;
		for(int i=0;i<ndays;i++){
			if(i%7==5 or i%7==6) continue;
			if(days[i]) cont++;
		}
		printf("%d\n", cont);

	}
	return 0;
}
