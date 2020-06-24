#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while(cin >> n) {
		vector <ll> vec(n);
		for(ll i = 0; i < n; i++) {
			cin >> vec[i];
		}
		sort(vec.begin(), vec.end());
		ll m;
		cin >> m;
		ll resp_i = -1, resp_j = -1;
		for(ll i = 0, j = n - 1; i < j;) {
			if(vec[i] + vec[j] == m) {
				resp_i = i;
				resp_j = j;
				if(i + 1 < j && vec[i] == vec[i + 1]) i++;
				else j--;
			} else if(vec[i] + vec[j] < m) {
				i++;
			} else {
				j--;
			}
		}
		cout << "Peter should buy books whose prices are " << vec[resp_i] << " and " << vec[resp_j] << "." << endl << endl;
	}
}
