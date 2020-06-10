#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

ll mat[5][5];
// num / == line
// num % == column

ll compute_sum(ll offices[]) {
    ll resp = 0;
    for(ll i = 0; i < 5; i++) {
        for(ll j = 0; j < 5; j++) {
            if(mat[i][j] != 0) {
                ll mini = -1;
                for(ll k = 0; k < 5; k++) {
                    ll i_office = offices[k] / 5;
                    ll j_office = offices[k] % 5;
                    ll dist = labs(i - i_office) + labs(j - j_office);
                    if(dist < mini or mini == -1) {
                        mini = dist;
                    }
                }
                resp += (mini * mat[i][j]);
            }
        }
    }
    return resp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; 
    cin >> t;
    while(t--) {
        for(ll i = 0; i < 5; i++) {
            for(ll j = 0; j < 5; j++) {
                mat[i][j] = 0;
            }
        }
        ll n;
        cin >> n;
        for(ll i = 0; i < n; i++) {
            ll x, y, p;
            cin >> x >> y >> p;            
            mat[x][y] = p;
        }
        ll resp[5];
        ll mini = -1;
        for(ll a = 0; a <= 20; a++) {
            for(ll b = a + 1; b <= 21; b++) {
                for(ll c = b + 1; c <= 22; c++) {
                    for(ll d = c + 1; d <= 23; d++) {
                        for(ll e = d + 1; e <= 24; e++) {
                            ll offices[] = {a, b, c, d, e};
                            ll sum = compute_sum(offices);
                            if(mini == -1 or sum < mini) {
                                mini = sum;
                                for(ll i = 0; i < 5; i++) resp[i] = offices[i];
                            }
                        }
                    }
                }
            }
        }
        for(ll i = 0; i < 5; i++) {
            if(i == 0) cout << resp[i];
            else cout << " " << resp[i];
        } cout << endl;
    }
}
