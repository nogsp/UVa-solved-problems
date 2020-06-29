#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, casos;
    while(cin >> n, n) {
        if(casos) cout << endl;
        casos++;
        vector <ll> bags(n);
        vector <ll> nBags(1000001);
        ll maxi = 0;
        for(ll i = 0; i < n; i++) {
            cin >> bags[i];
            nBags[bags[i]]++;
            if(nBags[bags[i]] > maxi) maxi = nBags[bags[i]];
        }
        cout << maxi << endl;
        sort(bags.begin(), bags.end());
        for(ll i = 0; i < maxi; i++) {
            for(ll j = i; j < n; j += maxi) {
                if(i == j) cout << bags[j];
                else cout << ' ' << bags[j];
            }
            cout << endl;
        }
    }
}
