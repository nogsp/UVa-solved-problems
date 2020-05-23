#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin >> n) {
        vector<pair<ll, ll>> one, three;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                char aux;
                cin >> aux;
                if(aux == '1') one.pb({i, j});
                else if (aux == '3') three.pb({i, j});
            }
        }
        ll resp = 0;
        for(ll i = 0; i < one.size(); i++) {
            ll mini = -1;
            for(ll j = 0; j < three.size(); j++) {
                ll dist = labs(one[i].first - three[j].first) + labs(one[i].second - three[j].second);
                if(dist < mini or mini == -1) {
                    mini = dist;
                }
            }
            if(mini > resp) resp = mini;
        }
        cout << resp << endl;
    }
}
