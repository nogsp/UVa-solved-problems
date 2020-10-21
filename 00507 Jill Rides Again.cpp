#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t, casos = 0;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll sum = 0, resp = -1;
		ll ini = 1, fin = 1, it = 1; 
		for(ll i = 1; i <= n - 1; i++) {
			ll val;
			cin >> val;
			sum += val;
			if(sum > resp || sum == resp && (i + 1 - it > fin - ini)) {
				resp = sum;
				ini = it;
				fin = i + 1;
			}
			if(sum < 0) {
				it = i + 1;
				sum = 0;
			}
		}
		if(resp < 0) cout << "Route " << ++casos << " has no nice parts" << endl;
		else cout << "The nicest part of route " << ++casos << " is between stops " << ini << " and " << fin << endl;
	}
}
