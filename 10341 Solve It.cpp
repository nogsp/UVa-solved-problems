#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define epsilon 0.0000001
double p, q, r, s, t, u, x;

double f(double x) {
    return (p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*x*x)+u;
}

double bs() {
    double lef = 0.0;
    double rig = 1.0;
    double resp = -1.0;
    while(lef + epsilon <= rig) {
        double m = (lef + rig) / 2.0;
        if(f(m) > 0) {
            lef = m;
        } else {
            rig = m;
        }
    }    
    return lef;
}
int main() {
    while(scanf("%lf", &p)==1){
        scanf("%lf %lf %lf %lf %lf",&q, &r, &s, &t, &u);
        if(f(0.0) * f(1.0) > 0) printf("No solution\n");
        else {
            double resp = bs();
            printf("%.4lf\n", resp);    
        }
    }
}
