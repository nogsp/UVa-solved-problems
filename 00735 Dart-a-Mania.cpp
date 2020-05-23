#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> sete{0, 50};
    for(ll i = 1; i <= 20; i++) {
        sete.insert(i), sete.insert(i * 2), sete.insert(i * 3);
    }
    vector <ll> points;
    for(auto val : sete) points.pb(val);

    ll n;
    while(cin >> n, n > 0) {
        ll per = 0;
        set<vector<ll>> comb;
        for(ll i = 0; i < points.size(); i++) {
            for(ll j = 0; j < points.size(); j++) {
                for(ll k = 0; k < points.size(); k++) {
                    if(points[i] + points[j] + points[k] == n) {
                        per++;
                        vector <ll> aux{i, j, k};
                        sort(aux.begin(), aux.end());
                        comb.insert(aux);
                    }
                }
            }
        }
        if(per != 0){
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb.size() << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << per << "." << endl;  
        }
        else cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl; 
        cout << "**********************************************************************" << endl;
    }
    cout << "END OF OUTPUT" << endl;
}
