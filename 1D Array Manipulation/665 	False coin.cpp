#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t, help = 0;
    cin >> t;
    while(t--) {
        if(help) cout << endl;
        help = 1;
        ll n, k;
        cin >> n >> k;        
        vector <ll> coins(n+1);
        while(k--){
            ll pi, aux;
            cin >> pi;
            vector <ll> s1, s2;
            for(ll i = 0; i < pi; i++) {
                cin >> aux;
                s1.pb(aux);
            }
            for(ll i = 0; i < pi; i++) {
                cin >> aux;
                s2.pb(aux);
            }
            string s;
            cin >> s;
            if(s == "=") {
                for(ll val : s1) coins[val] = 1;
                for(ll val : s2) coins[val] = 1;                
            }
            else {
                for(ll val : s1) if(coins[val]!=1)coins[val] = -1;
                for(ll val : s2) if(coins[val]!=1)coins[val] = -1;
                for(ll i = 1; i <= n; i++) {
                    if(coins[i] != -1) {
                        coins[i] = 1;
                    }
                    else{
                        coins[i] = 0;
                    }
                }
            }
        }
        ll cont = 0, pos = 0;
        for(ll i = 1; i <= n; i++) {
            if(coins[i] == 0){
                pos = i;
                cont++;
            }
            if(cont == 2) break;
        }
        if(cont > 1) cout << 0 << endl;
        else cout << pos << endl;
    }
}
