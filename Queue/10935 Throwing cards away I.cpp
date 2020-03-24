#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n),n){
		vector<int> vec;
		for(int i=n;i>=1;i--){
			vec.pb(i);
		}
		vector<int> resp;
		while(vec.size()>1){
			int aux = vec[vec.size()-1];
			resp.pb(aux);
			vec.pop_back();
			vec.insert(vec.begin(),vec[vec.size()-1]);
			vec.pop_back();
		}
		printf("Discarded cards:");
		for(int i=0;i<resp.size();i++){
			if(!i) printf(" %d", resp[i]);
			else printf(", %d", resp[i]);
		}
		printf("\n");
		printf("Remaining card: %d\n", vec[0]);
	}
}
