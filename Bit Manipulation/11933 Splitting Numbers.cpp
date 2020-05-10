#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int num;
    while(cin >> num, num) {
        int a = 0, b = 0;
        int lado = 0, it = 0;
        while(1) {
            int aux = (num & 1);
            num = num >> 1;
            if(aux == 0) continue;
            if(lado == 0) {
                lado = 1;
                a += pow(2, it);
            } else {
                lado = 0;
                b += pow(2, it);
            }
            it++;
        }
        cout << a << ' ' << b << endl;
    }
}
