#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t, casos = 0;
    cin >> t;
    while(t--) {
        cin.ignore();
        string s;
        getline(cin, s);
        ll n = s.back() - '0';
        vector<vector<ll>> mat(n, vector<ll>(n, 0));
        bool key = true;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                cin >> mat[i][j];
                if(mat[i][j] < 0) key = false;
            }
        }
        
        for(ll i = 0; i < n; i++) {
            if(!key) break;
            for(ll j = 0; j < n; j++) {
                if(mat[i][j] != mat[n - i - 1][n - j - 1]) {
                    key = false;
                    break;
                }
            }
        }
        cout << "Test #" << ++casos << ": ";
        if(key) cout << "Symmetric." << endl;
        else cout << "Non-symmetric." << endl;
        
    }
}
