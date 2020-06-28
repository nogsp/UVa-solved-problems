#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, casos = 0;
	while(cin >> n >> m, n != 0 or m != 0) {
		vector <ll> heads(n), knights(m);
		for(ll i = 0; i < n; i++) {
			cin >> heads[i];
		}
		for(ll i = 0; i < m; i++) {
			cin >> knights[i];
		}
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());
		ll cut = 0;
		ll sum = 0;
		for(ll i = 0; i < m; i++) {
			if(cut >= n) break;
			if(knights[i] >= heads[cut]) {
				sum += knights[i];
				cut++;
			}
		}
		if(cut < n) cout << "Loowater is doomed!" << endl;
		else cout << sum << endl;
	}
}
