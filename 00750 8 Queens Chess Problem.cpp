#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll mat[101][101], fl, fc;

bool isOk(ll l, ll c){
    ll n = 8;
    for(ll j=0;j<n;j++){ //confere linha
        if(mat[l][j]!=0) return false;
    }
    for(ll i=l, j=c;i>=0 && j>=0;i--,j--){ //dp-
        if(mat[i][j]==1) return false;
    }
    for(ll i=l, j=c;i<n && j<n;i++,j++){ //dp+
        if(mat[i][j]==1) return false;
    }
    for(ll i=l, j=c;i>=0 && j<n;i--,j++){ //ds-
        if(mat[i][j]==1) return false;
    }
    for(ll i=l, j=c;i<n && j>=0;i++,j--){ //ds+
        if(mat[i][j]==1) return false;
    }
    return true;
}
ll casos;
void backTrack(ll k, ll n){
    if(k==n){
        casos++;
        if(casos<10)printf(" %lld      ", casos);
        else if(casos<100)printf("%lld      ", casos);
        else printf("%lld     ", casos);
        for(ll j=0;j<n;j++){
            for(ll i=0;i<n;i++){
                if(mat[i][j]==1){
                    if(j==0) printf("%lld", i+1);
                    else printf("% lld", i+1);
                }
            }
        }
        printf("\n");
    }else if(k==fl){
        backTrack(k+1, n);
    } 
    else{
        for(ll i=0;i<n;i++){
            if(isOk(i, k)){
                mat[i][k] = 1;
                backTrack(k+1, n);
                mat[i][k] = 0;
            }
        }
    }
} 
 
int main(){ 
    ll t, n = 8;
    scanf("%lld", &t);
    while(t--){
        printf("SOLN       COLUMN\n"); 
        printf(" #      1 2 3 4 5 6 7 8\n\n"); 
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                mat[i][j] = 0;
            }
        }
        ll a, b;
        scanf("%lld %lld", &a, &b);
        mat[a-1][b-1] = 1;
        fl = b-1;
        casos = 0;
        backTrack(0,8);
        if(t) printf("\n");
    }
}
