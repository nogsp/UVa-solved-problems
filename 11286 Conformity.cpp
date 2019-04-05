#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, aux, MAX=0, t=5, tot=0;
	cin >> n;
	map <int, int> mapa;
	vector<int> v;
	while(n!=0){
		while(n--){	
			t = 5;
			while(t--){
				cin >> aux;
				v.push_back(aux);
			}
			sort(v.begin(), v.end());
			tot = 0;
			for(int i=0;i<5;i++){
				tot = (tot * 1000) +v[i];
				v.pop_back();
			}
			if(mapa.find(tot)==mapa.end()){
				mapa[tot]=1;
			}
			else{
				mapa[tot]++;
			}
			MAX = max(MAX, mapa[tot]);
		}
		tot=0;
		for(map<int,int>::iterator it=mapa.begin();it!=mapa.end();it++){
			if(it->second==MAX){
				tot+=it->second;
			}
		}
		mapa.clear();
		MAX=0;	
		cout << tot << endl;
		cin >> n;
	}

    return 0;
}                                 
