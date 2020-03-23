#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n';

using namespace std;

ll mat[33][33];
ll cnt;
void findBit(ll l, ll c, ll n, ll m) {

	char word;
	cin >> word;
	if(word == 'p') {
		ll lm = (l + n) >> 1;
		ll cm = (c + m) >> 1;
		findBit(l, c, lm, cm);
		findBit(lm+1, c, n, cm);
		findBit(l, cm+1, lm, m);
		findBit(lm+1, cm+1, n, m);
	} else if(word == 'f') {
		for(ll i = l; i <= n; i++) {
			for(ll j = c; j <= m; j++) {
				if(mat[i][j] == 0) {
					mat[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	cin.ignore();
	
	while(t--) {
	    for(ll i = 0; i <= 32; i++) {
		    for(ll j = 0; j <= 32; j++) {
			    mat[i][j] = 0;
	    	}
    	}
		cnt = 0;
		findBit(1, 1, 32, 32);
		findBit(1, 1, 32, 32);
		cout << "There are " << cnt << " black pixels." << endl;
	}	
}
//297
