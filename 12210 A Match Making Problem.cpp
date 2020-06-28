#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, casos = 0;
	while(cin >> n >> m, n != 0 or m != 0) {
		ll mini = -1, aux;
		for(ll i = 0; i < n; i++) {
			cin >> aux;
			if(mini == -1 or aux < mini) mini = aux;
		}
		for(ll i = 0; i < m; i++) cin >> aux;
		cout << "Case " << ++casos << ": ";
		if(n <= m) cout << 0 << endl;
		else cout << n - m << " " << mini << endl;
	}
}
