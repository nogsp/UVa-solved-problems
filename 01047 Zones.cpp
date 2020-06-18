#include <bits/stdc++.h>
#define ll long long
#define Matrix vector<vector<ll>>
using namespace std;

Matrix comonTowers;
vector <ll> towers, comonTowersCont;
vector <ll> resp, usedTowers;
ll maxi;

ll getPopulation(ll n, ll m) {
    ll tot = 0;
    for(ll i = 0; i < n; i++) {
        if(usedTowers[i] == 1) {
            tot += towers[i];
        }
    }
    for(ll i = 0; i < m; i++) {
        ll cont = 0;
        for(auto cTower : comonTowers[i]) {
            ll tower = cTower - 1;
            if(usedTowers[tower] == 1) {
                cont++;
            }
        }
        if(cont > 0) {
            tot -= (comonTowersCont[i] * (cont - 1));
        }
    }
    return tot;
}

void backTrack(ll k, ll cont, ll nx, ll n) {
    if(k == n) {
        ll val = getPopulation(n, comonTowers.size());
        if(val > maxi) {
            maxi = val;
            resp.clear();
            for(ll i = 0; i < n; i++) {
                if(usedTowers[i] == 1) resp.push_back(i + 1);
            }
        }
    } else {
        if(cont < nx) {
            usedTowers[k] = 1;
            backTrack(k + 1, cont + 1, nx, n);
            usedTowers[k] = 0;
        }
        backTrack(k + 1, cont, nx, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, nx, casos = 0;
    while(cin >> n >> nx, n != 0 or nx != 0) {
        towers.clear(), towers.resize(n);
        for(ll i = 0; i < n; i++) {
            cin >> towers[i];
        }
        ll m;
        cin >> m;
        comonTowers.clear(), comonTowers.resize(m);
        comonTowersCont.clear(), comonTowersCont.resize(m);
        for(ll i = 0; i < m; i++) {
            ll t;
            cin >> t;
            while(t--) {
                ll aux;
                cin >> aux;
                comonTowers[i].push_back(aux);
            }
            cin >> comonTowersCont[i];
        }
        maxi = -1;
        usedTowers.clear(), usedTowers.resize(n);
        backTrack(0, 0, nx, n);
        cout << "Case Number  " << ++casos << endl;
        cout << "Number of Customers: " << maxi << endl;
        cout << "Locations recommended:";
        for(auto val : resp) cout << " " << val;
        cout << endl << endl;
    }
}
