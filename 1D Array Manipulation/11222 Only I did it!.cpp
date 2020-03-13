#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t, casos = 0;
    cin >> t;
    while(t--) {
        vector <vector <ll> > mat(3, vector <ll> (20000, 0));
        vector <vector <ll> > unique(3);
        vector <ll> friends(3);
        for(ll i = 0; i < 3; i++) {
            ll s;
            cin >> s;
            for(ll j = 0; j < s; j++) {
                ll aux;
                cin >> aux;
                mat[i][aux] = 1;
            }
        }
        for(ll i = 0; i <= 10000; i++) {
            if(mat[0][i] == 1 && mat[1][i] == 0 && mat[2][i] == 0) {
                friends[0]++;
                unique[0].pb(i);
            }
            if(mat[0][i] == 0 && mat[1][i] == 1 && mat[2][i] == 0) {
                friends[1]++;
                unique[1].pb(i);
            }
            if(mat[0][i] == 0 && mat[1][i] == 0 && mat[2][i] == 1) {
                friends[2]++;
                unique[2].pb(i);
            }
        }
        cout << "Case #" << ++casos << ":" << endl;
        ll maxi = max(max(friends[0], friends[1]),friends[2]);
        //cout << maxi << endl;
        for(ll i = 0; i < 3; i++) {
            if(unique[i].size() == maxi){
                cout << i+1 << ' ' << friends[i];
                for(ll val : unique[i]) {
                    cout << ' ' << val;
                }
                cout << endl;
            }
        }
    }
}
