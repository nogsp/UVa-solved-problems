#include <bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;

int main(){
    ll t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        map <char, ll> mapa;
        for(ll i = 0; i < n; i++) {
            ll num;
            char c;
            cin >> c >> num;
            mapa.emplace(c, num);
            //cout << (char) c << " " << num << endl;
        }
        ll m;
        cin >> m;
        cin.ignore();
        double resp = 0;
        while(m--){
            string s;
            getline(cin, s);
            for(auto c : s) {
                if(mapa.count(c)) resp += (double)mapa.at(c);
            }
        }
        cout << fixed << setprecision(2) << (double)resp/100.0 << "$" << endl;
    }
    
}
