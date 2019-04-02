#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int n;
	scanf("%d", &n);
	cin.ignore();
	while(n--){
		string s;
		getline(cin,s);
		int male=0, female=0, size=s.size();
		for(int i=0;i<size;i++){
			if(s[i]=='M') male++;
			else if(s[i]=='F') female++;
		}
		if(male==female && (male+female>2)) printf("LOOP\n");
		else printf("NO LOOP\n");
	}
	return 0;
}
