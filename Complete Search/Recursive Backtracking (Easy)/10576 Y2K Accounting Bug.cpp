#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll s, d, mini;
ll month[12];

void back(ll k, ll n) {
    if(k == n) {
        for(ll i = 0; i < 8; i++) {
            ll it = 0;
            ll sum = 0;
            for(ll j = i; it < 5; j++, it++) {
                sum += month[j];
            }
            if(sum > 0) return;
        }
        ll resp = 0;
        for(ll i = 0; i < n; i++) resp += month[i];
        if(resp > mini) mini = resp;
    } else {
        month[k] = s;
        back(k + 1, n);
        month[k] = -d;
        back(k + 1, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> s >> d) {
        mini = -1;
        back(0, 12);
        if(mini < 0) cout << "Deficit" << endl;
        else cout << mini << endl;
    }    
}
