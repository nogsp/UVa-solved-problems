#include <iostream> 
#include <cstdio>
#include <vector> 
#include <string>
#define pb push_back 
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int p, min=-1, tam;
		scanf("%d", &p);
		string s;
		vector<int> vec;
		cin.ignore();
		int dale;
		for(int i=0;i<p;i++){
			getline(cin,s);
			dale=1;
			for(int j=0,sz=s.size();j<sz;j++){
				if(s[j]==' ') dale++;
			}
			vec.pb(dale);
			tam = dale;
			if(tam<min || min==-1){
				min = tam;
			}
		}
		int gold=0;
		for(int i=0;i<p;i++){
			if(vec[i]==min){
				if(gold!=0) printf(" ");
				printf("%d", i+1);
				gold=1;
			}

		}
		printf("\n");
	}
}
