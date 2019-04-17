#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){
    int n, m, num;
    while(cin >> n >> m, n && m){
        map<int, int> mapa;
        while(n--){
            cin >> num;
            mapa[num]=1; 
        }
        int cont=0;
        while(m--){
            cin >> num;
            if(mapa[num]) cont++;
        }
        cout << cont << endl;
    }
}
