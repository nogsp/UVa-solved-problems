#include<bits/stdc++.h>
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
        vector <ll> coins(n); 
        for(ll i = 0; i < n; i++) {
            cin >> coins[i];
        }
        ll sum = 0, it = 0;
        for(ll i = 0; i < n - 1; i++) {
            if(sum + coins[i] < coins[i + 1]) {
                sum += coins[i];
                it++;
            }
        }
        cout << it + 1 << endl;
    }
}
