#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Matrix vector<vector<ll>>

using namespace std;

Matrix mat;
ll dp[201][21];
ll m, c;
ll solve(ll money, ll garment) {
	if(money > m) {
		return -1;
	}	
	if(garment == c) {
		return money;
	}	
	if(dp[money][garment] != -1) return dp[money][garment];
	ll ans = -1;
	for(auto costs : mat[garment]) {
		ans = max(ans, solve(money + costs, garment + 1));
	}
	return dp[money][garment] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		for(ll i=0;i<201;i++) for(ll j=0;j<21;j++) dp[i][j]=-1;
		cin >> m >> c;
		mat.clear();
		for(ll i = 0; i < c; i++) {
			ll k;
			cin >> k;
			vector <ll> line(k);
			for(ll j = 0; j < k; j++) {
				cin >> line[j];
			}
			mat.push_back(line);
		}
		ll val = solve(0, 0);
		if(val == -1) {
			cout << "no solution" << endl;
		} else cout << val << endl;
	}
}
