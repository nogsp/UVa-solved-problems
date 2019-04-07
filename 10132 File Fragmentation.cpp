#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
	int n, ajuda=0;
	string s;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	while(n--){
		if(ajuda) cout << endl;
		vector<string> ves;
		int b=0, n=0;
		while(getline(cin, s)){
			if(s==""){
				//cout << "rola";
				break;
			} 
			//cout << s << endl;
			ves.pb(s);
			n++;
			b+=s.size();
		}
		
		b = (b/(n/2));
		//cout << "pnc" << endl;
		map <string, int> mapa;
		for(int it=0;it<n;it++){
			int bt=ves[it].size();
			for(int i=0;i<n;i++){
				if(i==it) continue;
				if(bt+ves[i].size()==b){
					string auxs=ves[it];
					auxs+=ves[i];
					mapa[auxs]++;
				}
			}
		}
		int maxi=-1;
		string segFile;
		for(auto it=mapa.begin();it!=mapa.end();it++){
			if(it->second>maxi){
				maxi = it->second;
				segFile = it->first;
			}
		}
		ajuda=1;
		cout << segFile << endl;
		

	}
}
