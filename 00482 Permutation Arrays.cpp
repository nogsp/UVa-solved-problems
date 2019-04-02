#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
#define pb push_back
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	cin.ignore();
	while(t--){
		cin.ignore();
		string line, aux;
		getline(cin,line);
		stringstream s1(line);
		data dic[1010];
		int tam=0;
		while(s1 >> dic[tam].id) tam++;
		getline(cin,line);
		stringstream s2(line);
		//cout << line << endl;
		tam=0;
		while(s2 >> dic[tam].num){
			tam++;
		}	
		sort(dic, dic+tam,cmp);
		//cout << tam << endl << endl;
		for(int i=0;i<tam;i++){
			cout << dic[i].num << endl;
		}
		if(t) cout << endl;
	}
	return 0;
}
