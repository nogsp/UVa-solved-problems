#include <bits/stdc++.h>
#define ll long long

/*d = (a + b + c) * 10^6
      ------------------
      (a * b * c) - 10^6
*/
bool condition(ll a, ll b, ll c, ll d) {
    return (a + b + c + d <= 2000 && a * b * c * d <= 2000000000);
}

int main() {
    ll cont = 0;
    for(ll a = 1; condition(a, a, a, a); a++) {
        for(ll b = a; condition(a, b, b, b); b++) {
            for(ll c = b; condition(a, b, c, c); c++) {
                if((a * b * c) <= 1000000) continue;
                ll up = 1000000*(a + b + c);
                ll dw = a * b * c - 1000000;
                if(up % dw != 0) continue;
                ll d = up / dw;
                if(d < c) continue;
                if(!condition(a, b, c, d)) continue;
                printf("%.2lf %.2lf %.2lf %.2lf\n",(a/100.00),(b/100.00),(c/100.00),(d/100.00));
            }
        }
    }
}
