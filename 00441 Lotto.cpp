#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k, dale = 0;
    while(cin >> k, k != 0) {
        if(dale) cout << endl;
        dale = 1;
        vector <ll> s(k);
        for(ll i = 0; i < k; i++) {
            cin >> s[i];            
        }
        ll cont = 0;
        for(ll a = 0; a < k; a++) {
            for(ll b = a + 1; b < k; b++) {
                for(ll c = b + 1; c < k; c++) {
                    for(ll d = c + 1; d < k; d++) {
                        for(ll e = d + 1; e < k; e++) {
                            for(ll f = e + 1; f < k; f++) {
                                cout << s[a] << ' ' << s[b] << ' ' << s[c] << ' ' << s[d] << ' ' << s[e] << ' ' << s[f] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
