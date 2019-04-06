#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
    string s;
    int i;
    map <string, string> mapa;
    while(getline(cin,s), s!=""){
        int tam = s.size(), op=0;
        string s1,s2;
        for(i=0;i<tam;i++){
            if(s[i]==' '){
                op=1;
                continue;
            }
            if(!op) s1+=s[i];
            else s2+=s[i];
        }
        mapa[s2]=s1;
        
    }
    while(cin >> s){
        if(mapa.count(s)<=0) cout << "eh" << endl;
        else cout << mapa[s] << endl;
    }
}
