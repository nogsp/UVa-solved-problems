#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>      
#define pb push_back
#define vvi vector<vector<int>>

using namespace std;
int dale;
bool fi(vvi& mat, int it, int k){
	//if(it==5)printf("dale %d\n", dale);
	int sz=mat[it].size();
	for(int i=0;i<sz;i++){
		//if(it==5) printf("%d\n", mat[it][i]);
		if(mat[it][i]==k){
			mat[it][i]=-1;
	//		if(it==5)printf("true\n");
			return true;
		}
	}
	//if(it==5)printf("false\n");
	return false;
}

int main() {
	int n;
	while(scanf("%d", &n)==1){
		int m, appeared=3, it=0;
		string s;
		scanf("%d", &m);
		cin >> s;
		map <int, int> spotted, awake;
		vector <int> awaken;
		vvi mat(26);
		for(int i=0;i<3;i++){
			awake[s[i]-'A']=1;
			awaken.pb(s[i]-'A');
		} 
		for(int k=0;k<m;k++){
			cin >> s;
			int a = (s[0]-'A'), b = (s[1]-'A');
			spotted[a] = 1;
			spotted[b] = 1;
			mat[a].pb(b);
			mat[b].pb(a);
		}
		n = n - 3;
		map <int, int> counter;
		int key=1, sz;
		dale=0;
		while(n!=0){
			dale++;
			sz=awaken.size();
			vector <int> awakenx;
			//printf("%d\n", sz);
			for(;it<sz;it++){
				for(int i=0;i<26;i++){
					if(awake[i] || !spotted[i]){
						continue;
					}else{
						//printf("%d\n", i);
						if(fi(mat,i,awaken[it])){
							counter[i]++;
							if(counter[i]>=3){
								//printf("%d\n", i);
								awaken.pb(i);
								awake[i]=1;
								n--;
							}
						}

					}
				}
				if(n==0) break;
			}
			if(n==0) break;
			else if(it>=awaken.size()) break;
		}	
		if(n==0)printf("WAKE UP IN, %d, YEARS\n",dale);	
	    else printf("THIS BRAIN NEVER WAKES UP\n");
	    cin.ignore();
	}    
    return 0;
}
