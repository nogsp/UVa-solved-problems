#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>      

using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	while(c--){
		int p, t, a, b;
		scanf("%d %d", &p, &t);
		vector<vector<int>> mat(p);
		for(int i=0;i<p;i++) mat[i].resize(t);
		cin.ignore();
		string s;
		while(getline(cin,s)){
			if(s=="") break;
			sscanf(s.c_str(), "%d %d", &a, &b);
			a--;
			b--;
			mat[a][b]=1;
		}
		sort(mat.begin(), mat.end());
		int resp=1;
		for(int i=0;j=1;j<p;i++,j++){
			for(int k=0;k<t;k++){
				if(mat[i][k]!=mat[j][k]){
					resp++;
					break;
				}
			}
		}
		printf("%d", resp);
	}
    return 0;
}
