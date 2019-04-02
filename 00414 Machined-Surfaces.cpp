#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main(void){
	int n;
	while(scanf("%d", &n), n){
		cin.ignore(1);
		int min=-1;
		vector<int> row(n);
		for(int i=0;i<n;i++){
			int cont=0;
			string s;
			getline(cin,s);
			for(int j=0;j<s.size();j++){
				if(s[j]!='X') cont++;
			}
			if(min>cont||min==-1) min=cont;
			row[i]=cont;
		}
		int tot=0;
		for(int i=0;i<n;i++){
			tot+= row[i]-min;
		}
		printf("%d\n", tot);
	}

}
