#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin >> n, n != 0) {
        vector <ll> resp;
        for(ll i = 0; i < n; i++) {
            ll aux;
            cin >> aux;
            if(aux > 0) resp.pb(aux);
        }
        if(resp.size() == 0) cout << 0 << endl;
        else {
            for(ll i = 0; i < resp.size(); i++) {
                if(i == 0) cout << resp[i];
                else cout << " " << resp[i];
            }
            cout << endl;
        }
    }
}
