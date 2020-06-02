#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

bool key;
vector <pair<ll, ll>> pieces;
vector <ll> used_pieces;

void back_track(ll last, ll k, ll fim, ll n) {
    if(k == n) {
        if(last != fim) return;
        key = true;
    } else {
        for(ll i = 0; i < pieces.size(); i++) {
            if(used_pieces[i] == 1) continue;
            if(pieces[i].first == last) {
                used_pieces[i] = 1;
                back_track(pieces[i].second, k + 1, fim, n);
                used_pieces[i] = 0;
            }
            if(pieces[i].second == last) {
                used_pieces[i] = 1;
                back_track(pieces[i].first, k + 1, fim, n);
                used_pieces[i] = 0;
            }
        }
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n;
    while(cin >> n, n != 0) {
        ll m;
        cin >> m;
        pair <ll, ll> Lpiece, Rpiece;
        cin >> Lpiece.first >> Lpiece.second >> Rpiece.first >> Rpiece.second;
        pieces.clear(), used_pieces.clear();
        for(ll i = 0; i < m; i++) {
            pair <ll, ll> piece;
            cin >> piece.first >> piece.second;
            pieces.pb(piece);
            used_pieces.pb(0);
        }
        key = false;
        back_track(Lpiece.second, 0, Rpiece.first, n);
        if(key) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}
