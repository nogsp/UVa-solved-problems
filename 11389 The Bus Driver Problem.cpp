#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, d, r;
    while(cin >> n >> d >> r, n != 0 or d != 0 or r != 0) {
        vector <ll> a(n), b(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        ll resp = 0;
        for(ll i = 0; i < n; i++) {
            resp += (a[i] + b[i] >= d) ? (a[i]+b[i]-d) * r : 0;
        }
        cout << resp << endl;
    }
}
