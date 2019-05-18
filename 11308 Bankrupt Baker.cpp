#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
using namespace std;

int main(){
	int t, m, n, b, cost, num, k;
	cin >> t;
	// cout << t << endl;
	string binder, ing, recipe;
	while(t--){
		cin.ignore();
		map <string, int> mapa;
		vector <pair<int, string>> resp;
		getline(cin,binder);
		// cout << binder << endl;
		cin >> m >> n >> b;
		//printf("%d %d %d\n", m , n,b);
		for(int i=0;i<m;i++){
			cin >> ing >> cost;
			// cout << ing << " " << cost << endl;
			mapa[ing] = cost;
		}
		while(n--){
			int cont = 0;
			cin.ignore();
			getline(cin,recipe);
			// cout << recipe << endl;
			cin >> k;
			// cout << k << endl;
			while(k--){
				cin >> ing >> num;
				// cout << ing << " " << num << endl;
				cont += mapa[ing] * num;
			}
			if(cont <= b){
				resp.pb({cont, recipe});
			}
		}
		for(int i=0, sz=binder.size();i<sz;i++){
			if(binder[i]>='a' && binder[i]<='z') binder[i] -= 32;
		}	
		cout << binder << endl;
		sort(resp.begin(), resp.end());
		for(int i=0, sz=resp.size();i<sz;i++){
			cout << resp[i].second << endl;
		}
		if(!resp.size()) printf("Too expensive!\n");
		printf("\n");	
	}
	return 0;
}
