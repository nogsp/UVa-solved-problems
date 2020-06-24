#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	while(cin >> n >> m, n != 0 || m != 0) {
		vector <vector<ll>> mat(n, vector<ll>(m, 0));
		for(ll i = 0; i < n; i++) {
			for(ll j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		ll q;
		cin >> q;
		while(q--) {
			ll l, u;
			cin >> l >> u;
			ll resp = 0, pos;
			for(ll i = 0; i < n; i++) {
				pos=lower_bound(mat[i].begin(),mat[i].end(),l)-mat[i].begin();
				for(ll j = resp; j < n && j < m; j++) {
					if(i + j < n && pos + j < m && mat[i + j][pos + j] <= u) {
						resp = max(resp, j + 1);
					} else break;
				}
			}
			cout << resp << endl;
		}
		cout << "-" << endl;
	}
}
