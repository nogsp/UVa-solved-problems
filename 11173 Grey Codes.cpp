#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        cout << (k & (k >> 1)) << endl;
    }
}
