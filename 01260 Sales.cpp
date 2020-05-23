#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for(ll i = 0; i < n; i++) {
            cin >> vec[i];
        }
        ll resp = 0;
        for(ll i = 1; i < n; i++) {
            for(ll j = 0; j < i; j++) {
                if(vec[j] <= vec[i]) resp++;
            }
        }
        cout << resp << endl;
    }
}
