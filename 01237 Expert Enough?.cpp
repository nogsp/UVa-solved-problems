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
    ll t;
    cin >> t;
    while(t--) { 
        ll d;
        cin >> d;
        vector<Acm> vec;
        for(ll i = 0; i < d; i++) {
            string m;
            ll l, h;
            cin >> m >> l >> h;
            vec.pb(Acm(m, l, h));
        }
        ll key = -1;
        string nome;
        ll q;
        cin >> q;
        while(q--) {
            ll p;
            cin >> p;
            for(ll i = 0; i < d; i++) {
                if(p >= vec[i].l && p <= vec[i].h) {
                    if(key != -1) {
                        key = -1;
                        break;
                    }
                    key = 1;
                    nome = vec[i].m;
                }
            }
            if(key == -1) cout << "UNDETERMINED" << endl;
            else cout << nome << endl;
        }
    }
}
