#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define pb push_back
using namespace std;

string cheek(string& s, int i, int n){
	map <char, int> mapa;
	int cont=0;
	for(i=i-1;i<n;i++){
		mapa[s[i]]++;
		cont++;
	}
	int impares=0;
	for(auto it:mapa){
		if(it.second%2!=0) impares++;
	}
	if(impares and cont%2==0) return "no";
	if(cont%2!=0 and impares!=1) return "no";
	else return "yes";
	


}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, opn;
	string s;
	cin >> n >> opn;
	cin.ignore(1);
	getline(cin, s);
	int op, l, r;
	char x;
	while(opn--){
		cin >> op >> l;
		if(op==1){
			cin >> x;
			s[l-1]=x;
			continue;
		}
		cin >> r;
		cout << cheek(s, l, r) << endl;
	}

}
