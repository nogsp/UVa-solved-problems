#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back

using namespace std;

vector <ll> vec;

ll solve(ll goal) {
    ll mini = -1, i = 0, j = vec.size() - 1;
    ll resp;
    while(i < j) {
        ll sum = vec[i] + vec[j];
        //cout << i << ' ' << j << endl; 
        //cout << sum << endl;
        if(labs(sum - goal) < mini or mini == -1) {
            mini = labs(sum - goal);
            resp = sum
        }
        if(sum == goal) return break;
        else if(sum > goal) j--;
        else i++;
    }
    return resp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, casos = 0;
    while(cin >> n, n != 0) {
        cout << "Case " << ++casos << ":" << endl;
        vec.clear(), vec.resize(n);
        for(ll i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        ll m;
        cin >> m;
        for(ll i = 0; i < m; i++) {
            ll q;
            cin >> q;
            cout << "Closest sum to " << q << " is " << solve(q) << "." << endl;
        }
    }
}
