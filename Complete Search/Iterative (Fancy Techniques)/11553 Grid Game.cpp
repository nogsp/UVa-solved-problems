#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define Matrix vector <vector<ll>>

using namespace std;

vector <ll> col;
bool firstSol;
ll resp;

void back_track(ll k, ll sum, Matrix& mat) {
    if(k == mat.size()) {
        if(firstSol or sum < resp) {
            firstSol = false;
            resp = sum;
        }
    } else {
        for(ll i = 0; i < mat.size(); i++) {
            if(!col[i]) {
                col[i] = 1;
                back_track(k + 1, sum + mat[k][i], mat);
                col[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        Matrix mat(n, vector<ll>(n));
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        col.clear(), col.resize(n);
        firstSol = true;
        back_track(0, 0, mat);
        cout << resp << endl;
    }

}
