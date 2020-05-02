#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
 
using namespace std;

struct Sub {
    ll x1, y1, x2, y2;
    Sub(ll x1, ll y1, ll x2, ll y2) {
        this-> x1 = x1;
        this-> y1 = y1;
        this-> x2 = x2;
        this-> y2 = y2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll c, l, n;
    while(cin >> c >> l >> n, c || l || n){
        vector <Sub> subs;
        for(ll i = 0; i < n; i++) {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            subs.pb(Sub(min(x1,x2), min(y1,y2), max(x1,x2), max(y1,y2)));
        }
        ll sum = 0;
        for(ll y = 1; y <= l; y++) {
            for(ll x = 1; x <= c; x++) {
                bool key = true;
                for(auto sub : subs) {
                    if(sub.x1 <= x && sub.x2 >= x && sub.y1 <= y && sub.y2 >= y){
                        key = false;
                        break;
                    }
                }
                if(key) sum++;
            }
        }
        if(sum == 0) cout << "There is no empty spots." << endl;
        else if(sum == 1) cout << "There is one empty spot." << endl;
        else cout << "There are "<< sum <<" empty spots." << endl;
    }
}
