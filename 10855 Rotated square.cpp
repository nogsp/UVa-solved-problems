#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define Matrix vector<vector<char>>
 
using namespace std;

Matrix rotate(Matrix& mat, ll n) {
    Matrix newMat(n, vector<char>(n,0));
    for(ll j = 0, c = 0; j < n; j++, c++) {
        for(ll i = n - 1, l = 0; i >= 0; i--,l++) {
            newMat[c][l] = mat[i][j];
        }
    }
    return newMat;   
}

ll solve(Matrix& mat1, ll tam1, Matrix& mat2, ll tam2) {
    ll sum = 0;
    for(ll i = 0; i < tam1 - tam2 + 1; i++) {
        for(ll j = 0; j < tam1 - tam2 + 1; j++) {
            bool key = true;
            for(ll l = 0, l2 = i; l < tam2; l++, l2++) {
                for(ll c = 0, c2 = j; c < tam2; c++, c2++) {
                    if(mat1[l2][c2] != mat2[l][c]) {
                        key = false;
                        break;
                    }
                }
                if(key == false) break;
            }
            if(key) sum++;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll N, n;
    while(cin >> N >> n) {
        if(n == 0 && N == 0) break;
        Matrix mat1(N,vector<char>(N,0)), mat2(n,vector<char>(n,0));
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                cin >> mat1[i][j];
            }
        }
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                cin >> mat2[i][j];
            }
        }
        for(ll i = 0; i < 4; i++) {
            if(i > 0) cout << ' ';
            cout << solve(mat1, N, mat2, n);
            mat2 = rotate(mat2, n);
        }
        cout << endl;
    }    
}
