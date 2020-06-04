#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll p;
        cin >> p;
        vector <ll> vec;
        for(ll i = 0; i < p; i++) {
            ll aux;
            cin >> aux;
            vec.pb(aux);
            ll tam = vec.size() - 1;
            for(ll j = 0; j < tam; j++) {
                vec.pb(aux + vec[j]);
            }
        }
        vec.pb(0);
        bool key = false;
        for(ll i = 0; i < vec.size(); i++) {
            if(vec[i] == n) {
                key = true;
                break;
            }
        }
        if(key == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
