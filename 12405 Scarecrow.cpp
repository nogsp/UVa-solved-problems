#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, casos = 0;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cont = 0;
        ll resp = 0;
        for(ll i = 0; i < n; i++) {
            if(s[i] == '.') {
                resp++;
                if(i < n-2) {
                    s[i] = s[i+1] = s[i+2] = '#';
                } else if(i < n-1){
                    s[i] = s[i+1] = '#';
                    if(i > 0) s[i-1] = '#';
                } else {
                    s[i] = '#';
                }
            }
        }
        cout << "Case " << ++casos << ": " << resp << endl;
    }
}
