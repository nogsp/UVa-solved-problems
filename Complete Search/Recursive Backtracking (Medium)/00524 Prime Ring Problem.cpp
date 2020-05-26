#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

vector <ll> prime(101010, 1);
vector <ll> resp, used;

bool is_ok(ll k, ll i, ll n) {
    if(k == 0) return true;
    if(used[i]) return false;
    if((k == n - 1) && (!prime[resp[0] + i] or !prime[resp[k-1] + i])) return false;
    if(!prime[i + resp[k - 1]]) return false;
    return true;
}

void back_track(ll k, ll n) {
    if(k == n) {
        for(ll i = 0; i < n; i++) {
            if(i == 0) cout << resp[i];
            else cout << " " << resp[i];
        }
        cout << endl;
    } else {
        for(ll i = 1; i <= n; i++) {
            if(is_ok(k, i, n)) {
                resp.pb(i);
                used[i] = 1;
                back_track(k + 1, n);
                resp.pop_back();
                used[i] = 0;
            }
            if(k == 0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    prime[0] = 0;
    for(ll i = 2; i * i <= 31; i++) {
        for(ll j = 2; j * i <= 31; j++) {
            prime[i * j] = 0;
        }
    }
    ll n, casos = 0;
    while(cin >> n) {
        if(casos) cout << endl;
        cout << "Case " << ++casos << ":" << endl;
        used.clear(), used.resize(n + 1);
        back_track(0, n);
    }   
}
