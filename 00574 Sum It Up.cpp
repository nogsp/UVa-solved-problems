#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

vector <ll> in, resp;
set <vector <ll>> solutions;
vector <vector<ll>> table;


bool cmp(ll a, ll b) {
    return b < a;
}

void back_track(ll k, ll t, ll n) {
    if(k == n) {
        ll soma = 0;
        for(ll i = 0; i < resp.size(); i++) soma += resp[i];
        if(soma != t) return;
        sort(resp.begin(), resp.end(), cmp);
        solutions.insert(resp);
    } else {
        resp.pb(in[k]);
        back_track(k + 1, t, n);
        resp.pop_back();
        back_track(k + 1, t, n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t, n;
    while(cin >> t >> n) {
        if(n == 0) break;
        cout << "Sums of " << t << ":" << endl;
        in.clear(), in.resize(n);
        solutions.clear(), table.clear();
        for(ll i = 0; i < n; i++) {
            cin >> in[i];
        }
        back_track(0, t, n);
        if(solutions.size() == 0) {
            cout << "NONE" << endl;
            continue;
        }
        for(auto vec : solutions) {
            table.pb(vec);
        }
        for(ll i = table.size() -1; i >= 0; i--) {
            for(ll j = 0; j < table[i].size(); j++) {
                if(j == 0) cout << table[i][j];
                else cout << "+" << table[i][j];
            }
            cout << endl;
        }
    }   
}
