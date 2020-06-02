#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

map <ll, string> dic{
                    {0, "YYYYYYN"}, {1, "NYYNNNN"}, {2, "YYNYYNY"},
                    {3, "YYYYNNY"}, {4, "NYYNNYY"}, {5, "YNYYNYY"},
                    {6, "YNYYYYY"}, {7, "YYYNNNN"}, {8, "YYYYYYY"},
                    {9, "YYYYNYY"}
                };

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n;
    while(cin >> n) {
        if(n == 0) break;
        vector <string> entry(n);
        for(ll i = 0; i < n; i++) {
            cin >> entry[i];
        }
        bool masterKey = false;
        for(ll i = 9; i >= n - 1; i--) {
            vector <ll> burned(7);
            string s;
            ll it = 0;
            bool key = true;
            for(ll j = i; j >= 0; j--) {
                string led = dic[j];
                string in = entry[it++];
                for(ll k = 0; k < 7; k++) {
                    if((in[k] == 'Y') && (burned[k] == 1)) {
                        key = false;
                        break;
                    }
                    if(led[k] != in[k]) {
                        if(led[k] == 'N') {
                            key = false;
                            break;
                        }
                        else if(led[k] == 'Y') {
                            burned[k] = 1;
                        }
                    }
                }
                if(key == false) break;
                if(it == n) break;
            }
            if(key == true) {
                masterKey = true;
                cout << "MATCH" << endl;
                break;
            }
        }
        if(masterKey == false) {
            cout << "MISMATCH" << endl;
        }
    }
}
