#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define MOD 1000000

using namespace std;

ll n, k, memo[200][200];

ll solve(ll nx, ll kx) {
    if(kx == 1) return 1;
    if(memo[nx][kx] != -1) return memo[nx][kx];
    ll temp = 0;
    for(ll i = n; i >= 0; i--) {
        if(nx - i >= 0) temp = (temp + solve(nx - i, kx - 1)) % MOD;
    }
    return memo[nx][kx] = temp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i < 200; i++) {
        for(ll j = 0; j < 200; j++) {
            memo[i][j] = -1;
        }
    }
    while(cin >> n >> k, n || k) {
        cout << solve(n, k) % MOD << endl;
    }
}
