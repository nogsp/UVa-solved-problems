#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	string music[20]={"Happy","birthday","to","you","Happy",
				"birthday","to","you","Happy","birthday",
				"to","Rujia","Happy","birthday","to","you"};
	
	int t, n=1;
	scanf("%d", &t);
	int aux=t, times=0;
	while(aux>16){
		aux-=16;
		n++;
	}
	string s[1010];
	for(int i=0;i<t;i++){
		cin >> s[i];
	}
	int pos=0;
	while(n--){
		for(int i=0;i<16;i++){
			cout << s[pos] <<": " << music[i] << endl;
			pos = (pos+1)%t;
		}
	}
}
