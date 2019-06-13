#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define pb push_back
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, casos=0;
	cin >> t;
	while(t--){
		cout << "Case " << ++casos << ": ";
		int f[101010], c[101010], n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> f[i];
		}
		for(int i=0;i<n;i++){
			cin >> c[i];
		}
		int it=1, min, soma=0;
		for(int i=0;i<n;i++){
			soma += f[i]-c[i];
			if(soma<min || !i){
				min = soma;
				it=i;
			}	
		}
		if(soma<0){
			cout << "Not possible" << endl;
			continue;
		}
		if(min>=0) cout << "Possible from station 1" << endl;
		else cout << "Possible from station " << it+2 << endl;
	}
	cout << flush;
	return 0;
}
