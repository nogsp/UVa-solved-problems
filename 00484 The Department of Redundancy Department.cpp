#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
    int aux;
    vector <int> vec;
    map <int,int> mapa;
    while(cin >> aux){
        if(mapa[aux]<1) vec.pb(aux);
        mapa[aux]++;
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " " << mapa[vec[i]] << endl;
    }
}
