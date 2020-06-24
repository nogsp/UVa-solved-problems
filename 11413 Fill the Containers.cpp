#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector <ll> vec;
ll n, m;

bool is_sol(ll top) {
	ll left = m, sum = 0;
	for(ll i = 0; i < n; i++) {
		if(vec[i] > top) {
			return false;
		}
		if(sum + vec[i] > top) {
			if(left) {
				left--;
				sum = vec[i];
			} else {
				return false;
			}
		} else {
			if(sum == 0)left--;
			sum += vec[i];
		}
	}
	return true;
}

ll bs() {
	ll l = 0, r = LLONG_MAX;
	ll resp = 0;
	while(l <= r) {
		ll m = ( l + r) >> 1;
		if(is_sol(m)) {
			resp = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return resp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n >> m) {
		vec.clear(), vec.resize(n);
		ll maxi = 0;
		for(ll i = 0; i < n; i++) {
			cin >> vec[i];
			if(vec[i] > maxi) maxi = vec[i];
		}
		if(m >= n) cout << maxi << endl;
		else cout << bs() << endl;
	}
}
