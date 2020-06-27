#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
 
ll bitmap[1010][1010];
ll it, cont;
string in;
char nextChar(string s) {
    ll pos = 0;
    while(s[pos] == ' ') continue;
    return s[pos];
}
 
ll nextLong(string s, ll &pos) {
    while(pos < s.size() && (s[pos] <'0' || s[pos] > '9')) pos++;
    ll num = 0;
    while(s[pos] >= '0' && s[pos] <= '9' && pos < s.size()) {
        num *= 10;
        num += (s[pos++] - '0');
    }
    return num;
}
 
void findBit(ll inil, ll inic, ll l, ll c){
    ll i, j, zero=0, one=0;
    for(i=inil;i<=l;i++){
        for(j=inic;j<=c;j++){
            if(bitmap[i][j]==1) one++;
            else zero++;
        }
    }
    if(zero && one){
        cout << "D";
        cont++;
        if(cont == 50) {
            cout << endl;
            cont = 0;
        }
        ll lm = (inil+l)>>1;
        ll cm = (inic+c)>>1;
        findBit(inil, inic,lm, cm);
        findBit(inil, cm+1,lm, c);
        findBit(lm+1, inic,l, cm);
        findBit(lm+1, cm+1, l, c);
        return;
    }else if(one){
        cout << "1";
        cont++;
        if(cont == 50) {
            cout << endl;
            cont = 0;
        }
        return;
    }else if(zero){
        cout << "0";
        cont++;
        if(cont == 50) {
            cout << endl;
            cont = 0;
        }
        return;
    }else{
        return;
    }
}
 
void findMap(ll inil, ll inic, ll l, ll c){
    if(inil > l || inic > c) return;
    if(in[it] == 'D'){
        it++;
        ll lm = (inil+l)>>1;
        ll cm = (inic+c)>>1;
        findMap(inil, inic,lm, cm);
        findMap(inil, cm+1,lm, c);
        findMap(lm+1, inic,l, cm);
        findMap(lm+1, cm+1, l, c);
        return;
    }else if(in[it] == '1' || in[it] == '0'){
        ll val = in[it++] - '0';
        ll i, j;
        for(i=inil;i<=l;i++){
            for(j=inic;j<=c;j++){
                bitmap[i][j] = val;
            }
        }
        return;
    }else{
        return;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    ll l = -1, c;
    char op;
    while(1) {
        bool initLine = false;
        cont = 0;
        getline(cin, line);
        if(line == "#") {
            initLine = true;
            goto dale;
        }
        if(line.size() == 0) continue;
        for(ll i = 0; i < line.size() - 1; i++) {
            if(i > 0 && line[i-1] != ' ' && line[i] != ' ') {
                initLine = false;
                break;
            }
            else if(line[i] == ' ') {
                initLine = true;
                break;
            }
        }
        dale:
        if(initLine) {
            if(l != -1) {
                it = 0;
                if(op == 'B') {
                    for(ll i = 0; i < l; i++) {
                        for(ll j = 0; j < c; j++) {
                            bitmap[i][j] = (in[it++] - '0');
                        }
                    }
                    cont = 0;
                    findBit(0, 0, l - 1, c - 1);
                    if(cont != 0) cout << endl;
                } else {
                    cont = 0;
                    findMap(0, 0, l - 1, c - 1);
                    for(ll i = 0; i < l; i++) {
                        for(ll j = 0; j < c; j++) {
                            cout << bitmap[i][j];
                            cont++;
                            if(cont == 50) {
                                cout << endl;
                                cont = 0;
                            }
                        }
                    }
                    if(cont != 0) cout << endl;
                }
            }
            in.clear();
            op = nextChar(line);
            if(op == '#') break;
            ll itl = 0;
            l = nextLong(line, itl);
            c = nextLong(line, itl);
            if(op == 'D') cout << 'B';
            else cout << 'D';
            cout << right << setw(4) << l << right << setw(4) << c << endl;
        } else {
            in += line;
        }
    }
}
