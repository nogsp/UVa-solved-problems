#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
    int casos=0, k;
    scanf("%d", &k);
    while(k--){
        int n, aux;
        map<string,int> mapa;
        string s;
        scanf("%d" ,&n);
        while(n--){
            cin >> s >> aux;
            mapa[s]=aux;
        }
        int d;
        scanf("%d", &d);
        cin >> s;
        cout << "Case " << ++casos << ": ";
        if(mapa[s]==0) cout << "Do your own homework!" << endl;
        else if(mapa[s]<=d) cout << "Yesss" << endl;
        else if(mapa[s]<=d+5) cout << "Late" << endl;
        else cout << "Do your own homework!" << endl;

    }
}
