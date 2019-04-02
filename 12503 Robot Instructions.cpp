#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		string s;
		vector<int> actions;
		for(int i=0;i<n;i++){
			cin >> s;
			for(int i=0;i<s.size();i++) if(s[i]>=97&& s[i]<=122) s[i]-=32;
			if(s=="RIGHT") actions.push_back(1);
			else if(s=="LEFT") actions.push_back(-1);
			else{
				int aux;
				cin >> s >> aux;
				aux--;
				actions.push_back(actions[aux]);
			}
		}
		int cont=0;
		for(int i=0;i<n;i++) cont+=actions[i];
		printf("%d\n", cont);
	}
}
