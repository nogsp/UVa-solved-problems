#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <ctype.h>
#include <set>
#include <algorithm>
#define pb push_back
using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	string s1, s2;
	cin.ignore();
	map <string, string> dic;
	while(t--){
		getline(cin, s1);
		getline(cin, s2);
		dic[s1] = s2;
	}
	int n;
	scanf("%d", &n);
	cin.ignore();
	while(n--){
		getline(cin, s1);
		cout << dic[s1] << endl;
	}
	return 0;
}
