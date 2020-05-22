#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

int main() {
    vector<ll> bin1(3), bin2(3), bin3(3);
    map <ll, char> dale{{0,'B'},{1,'C'},{2,'G'}};
    while(cin >> bin1[0]) {
        cin >> bin1[2] >> bin1[1];
        cin >> bin2[0] >> bin2[2] >> bin2[1];
        cin >> bin3[0] >> bin3[2] >> bin3[1];
        ll mini = -1;
        string resp = "";
        for(ll i = 0; i < 3; i++) {
            for(ll j = 0; j < 3; j++) {
                if(j == i) continue;
                ll k = 0; if(k == i or k == j) k++; if(k == i or k == j) k++;
                ll cost = 0;
                cost+= bin2[i] + bin3[i] + bin1[j] + bin3[j] + bin1[k] + bin2[k];
                if(cost < mini or mini == -1) {
                    mini = cost;
                    resp.clear();
                    resp += dale[i];
                    resp += dale[j];
                    resp += dale[k];
                }
            }
        }
        cout << resp << ' ' << mini << endl;
    } 
}
