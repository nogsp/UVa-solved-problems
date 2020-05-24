#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
vector<string> mat1, mat2;
int key, kn;

bool isIn(vector<string>& mat, char c, ll coluna){
    for(int i=0;i<mat.size();i++){
        if(mat[i][coluna]==c) return true;
    }
    return false;
}

void backTrack(ll k, string &resp, ll goal){
    if(k==5){
        kn++;
        if(kn==goal){
            cout << resp << endl;
            key = true;
        }
    }
    else{
        if(key) return;
        for(char l='A';l<='Z'&&!key;l++){
            if(isIn(mat1,l,k) && isIn(mat2,l,k)){
                resp += l;
                backTrack(k+1, resp, goal);
                resp.pop_back();
            }
        }
    }
}
int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        key = false;
        kn = 0;
        mat1.clear();
        mat2.clear();
        ll k;
        scanf("%lld", &k);
        for(int i=0;i<6;i++){
            string s;
            cin >> s;
            mat1.pb(s);
        }
        for(int i=0;i<6;i++){
            string s;
            cin >> s;
            mat2.pb(s);
        }
        string resp = "";
        backTrack(0, resp, k);
        if(!key){
            cout << "NO" << endl;
        }
    }
}
