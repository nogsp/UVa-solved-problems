#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

vector <vector<ll>> solutions;
vector <vector<ll>> mat(8, vector<ll>(8, 0));

bool is_ok(ll l, ll c, ll n) {
    for(ll i = 0; i < n; i++) {
        if(mat[l][i] == 1) return false;
    }
    for(ll i = l, j = c; i < n && j < n; i++, j++) {
        if(mat[i][j] == 1) return false;
    }
    for(ll i = l, j = c; i >= 0 && j >= 0; i--, j--) {
        if(mat[i][j] == 1) return false;
    }
    for(ll i = l, j = c; i >= 0 && j < n; i--, j++) {
        if(mat[i][j] == 1) return false;
    }
    for(ll i = l, j = c; i < n && j >= 0; i++, j--) {
        if(mat[i][j] == 1) return false;
    }
    return true;
}

void back_track(ll k, vector<ll>& resp, ll n) {
    if(k == n) {
        solutions.pb(resp);
        //for(ll i = 0; i < 8; i++) cout << resp[i] << " ";
        //cout << endl;
    } else {
        for(ll i = 0; i < n; i++) {
            if(is_ok(i, k, n)) {
                mat[i][k] = 1;
                resp.pb(i);
                back_track(k + 1, resp, n);
                resp.pop_back();
                mat[i][k] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector <ll> resp;
    back_track(0, resp, 8);
    vector <ll> in(8);
    ll casos = 0;
    while(cin >> in[0]) {
        in[0]--;
        for(ll i = 1; i < 8; i++) {
            cin >> in[i];
            in[i]--;
        }
        ll mini = -1;
        for(auto resp : solutions) {
            ll cont = 0;
            for(ll i = 0; i < 8; i++) {
                if(in[i] != resp[i]) cont++;
            }
            if(cont < mini or mini == -1) mini = cont;
        }
        cout << "Case " << ++casos << ": " << mini << endl;
    }
}
