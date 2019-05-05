#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <ctype.h>
#include <set>
#define pb push_back
using namespace std;

int main(void){
	int n, tam;
	scanf("%d %d", &tam, &n);
	map <string, int> dic;
	string s;
	while(tam--){
		int dolar;
		cin >> s >> dolar;
		dic[s] = dolar;
	}
	while(n--){
		int counter = 0;
		while(cin >> s, s!=".") counter += dic[s];
		cout << counter << endl;
	}
	return 0;
}
