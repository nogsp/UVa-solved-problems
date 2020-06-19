#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> vec(n + 1);
        for(ll i = 0; i < n + 1; i++) {
            cin >> vec[i];
        }
        ll d, k;
        cin >> d >> k;
        ll it = 0, itx = 0;
        while(it < k){
            it += (d * (++itx));
        }
        ll resp = vec[0];
        for(ll i = 1; i < n + 1; i++) {
            resp += (vec[i] * pow(itx, i));
        } 
        cout << resp << endl;
    }
}
