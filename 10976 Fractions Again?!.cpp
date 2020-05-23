#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

struct Acm {
    string m;
    ll l, h;
    Acm(string m, ll l, ll h) {
        this->m = m;
        this->l = l;
        this->h = h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    while(cin >> k) { 
        ll y = k + 1;
        vector<pair<ll,ll>> resp;
        while(1) {
            if((k * y) % (y - k) == 0) {
                ll x = (k * y) / (y - k);
                if(x < y) break;
                resp.pb({x, y});
                if(x == y) break;
            }
            y++;
        }
        cout << resp.size() << endl;
        for(auto u : resp) {
            cout << "1/" << k << " = 1/" << u.first << " + 1/" << u.second << endl;
        }
    }
}
