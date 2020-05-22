#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

struct Quirk {
    vector <string> out;
    Quirk(ll n) {
        ll maxi = 0, aux = 1;
        for(ll i = 0; i < n; i++) {
            maxi += (9*aux);
            aux *= 10;
        }
        maxi = sqrt(maxi);
        //cout << maxi << endl;
        for(ll num = 0; num <= maxi; num++) {
            ll i = num * num;
            ll a = 0, b = 0;
            aux = 1;
            string resp = "", trueResp = "";
            for(ll j = 0; j < (n/2); j++) {
                if(i == 0) break;
                a += (i % 10) * aux;
                resp += (char)('0' + (i % 10));
                aux *= 10;
                i /= 10;
            }
            aux = 1;
            for(ll j = 0; j < (n/2); j++) {
                if(i == 0) break;
                b += (i % 10) * aux;
                resp += (char)('0' + (i % 10));
                aux *= 10;
                i /= 10;
            }
            if((a + b) == num) {
                
                while(resp.size() < n) resp += '0';
                for(ll i = n - 1; i >= 0; i--) trueResp += resp[i];
                out.pb(trueResp);
            }
        }
    }
    void show() {
        for(auto val : out) {
            cout << val << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Quirk> table{Quirk(2), Quirk(4), Quirk(6), Quirk(8)};
    ll n;
    while(cin >> n) {
        table[(n/2)-1].show();
    }
}// 00256 Quirksome Squares.cpp
