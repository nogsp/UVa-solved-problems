#include <bits/stdc++.h>
#define pb push_back
#define ll long long
 
using namespace std;
 
int main(){
    string s;
    map <char, vector<ll>> mapa;
    cin >> s;
    for(int i=0;i<s.size();i++){
        mapa[s[i]].pb(i);
    }
    ll n;
    scanf("%lld", &n);
    while(n--){
        string s2;
        cin >> s2;
        bool key = true;
        vector<ll>::iterator it = lower_bound(mapa[s2[0]].begin(), mapa[s2[0]].end(), 0);
        vector<ll>::iterator ini = it;
        for(int i=1;i<s2.size();i++){
            it = upper_bound(mapa[s2[i]].begin(), mapa[s2[i]].end(), *it);
            if(it==mapa[s2[i]].end()){
                key = false;
                break;
            }
        }
        if(key==true){
            printf("Matched %lld %lld\n", *ini, *it);
        }else{
            printf("Not matched\n");
        }
    }
}
