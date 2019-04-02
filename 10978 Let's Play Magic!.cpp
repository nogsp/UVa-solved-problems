
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int modcursor(int c, int num, string resp[],int n){
	while(num--){
		c++;
		while(resp[c%n].size()>=1) c++;
	}
	return c;
}

int main(){
	int n;
	while(scanf("%d", &n),n){
		string nipe,name;
		int cursor=-1;
		string resp[1010];
		for(int i=0;i<n;i++){
			cin >> nipe >> name;
			cursor = modcursor(cursor,name.size(),resp,n);
			resp[cursor%n]=nipe;
		}
		for(int i=0;i<n;i++){
			cout << resp[i];
			if(i<n-1) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
