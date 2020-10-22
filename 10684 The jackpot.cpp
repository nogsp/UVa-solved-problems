#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	while(cin >> t, t != 0) {
		ll n = t;
		ll sum = 0, resp = -1;
		for(ll i = 1; i <= n; i++) {
			ll val;
			cin >> val;
			sum += val;
			resp = max(resp, sum);
			if(sum < 0) sum = 0;
		}
		if(resp <= 0) cout << "Losing streak." << endl;
		else cout << "The maximum winning streak is " << resp << "." << endl;
	}
}
