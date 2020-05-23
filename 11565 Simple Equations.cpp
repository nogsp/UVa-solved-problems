#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        bool key = false;
        ll rx, ry, rz;
        ll z;
        for(ll x = -100; x <= 100 && !key; x++) {
            for(ll y = -100; y <= 100; y++) {
                z = a - x - y;
                if(x == y or y == z or z == x) continue;
                if((x + y + z == a) && (x * y * z == b) && ((x * x) + (y * y) + (z * z)) == c){
                    key = true;
                    rx = x, ry = y, rz = z;
                    break;
                }
            }
        }
        if(key) cout << rx << ' ' << ry << ' ' << rz << endl;
        else cout << "No solution." << endl;
    }
}
