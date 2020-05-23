#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n;
    while(cin >> m, m != 0) {
        cin >> n;
        vector <ll> front(m), rear(n);
        for(ll i = 0; i < m; i++) {
            cin >> front[i];
        }
        for(ll i = 0; i < n; i++) {
            cin >> rear[i];
        }
        vector <double> ds;
        for(ll i = 0; i < m; i++) {
            for(ll j = 0; j < n; j++) {
                double aux = (double)rear[j] / (double)front[i];
                ds.pb(aux);
            }
        }
        sort(ds.begin(), ds.end());
        double mspread = 0.0;
        for(ll i = 0; i < ds.size() - 1; i++) {
            double spread = (double)ds[i + 1] / (double)ds[i];
            if(spread > mspread) {
                mspread = spread;
            }
        }
        cout << fixed << setprecision(2);
        cout << mspread << endl;
    }
}
