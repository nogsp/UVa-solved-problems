#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define Grafo vector<vector<ll>>

using namespace std;

Grafo grafo;
vector <ll> color;
vector <ll> resp;

bool is_ok(ll k) {
    for(auto v : grafo[k]) {
        if(color[v] == 1) return false;
    }
    return true;
}

void back_track(ll k, ll n) {
    if(k == n) {
        vector <ll> solu;
        for(ll i = 0; i < n; i++) {
            if(color[i] == 1) solu.pb(i);
        }
        if(resp.size() < solu.size()) {
            resp.clear();
            for(ll i = 0; i < solu.size(); i++) resp.pb(solu[i]);
        }
    } else{
        back_track(k + 1, n);
        if(is_ok(k)) {
            color[k] = 1;
            back_track(k + 1, n);
            color[k] = 0;
        }
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        resp.clear();
        grafo.clear(), grafo.resize(n);
        color.clear(), color.resize(n);
        while(m--) {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            grafo[a].pb(b);
            grafo[b].pb(a);
        }
        back_track(0, n);
        cout << resp.size() << endl;
        for(ll i = 0; i < resp.size(); i++) {
            if(i == 0) cout << resp.at(i) + 1;
            else cout << " " << resp.at(i) + 1;
        } cout << endl;
    }
}
