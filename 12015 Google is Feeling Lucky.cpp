#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct banco{
	int rank;
	string url;
};

int main(void){
	int t, casos=0;
	scanf("%d", &t);
	while(t--){
		int max=0;
		banco site[10000];
		for(int i=0;i<10;i++){
			cin >> site[i].url >> site[i].rank;
			if(site[i].rank>max) max = site[i].rank;
		}
		printf("Case #%d:\n", ++casos);
		for(int i=0;i<10;i++){
			if(site[i].rank>=max) cout << site[i].url << endl;
		}
	}
}
