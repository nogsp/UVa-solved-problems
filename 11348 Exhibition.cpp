#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
    int casos=0, k;
    scanf("%d", &k);
    while(k--){
        int n, i, j, m, aux;
        scanf("%d", &n);
        vector<int> vec[n];
        map <int,int> mapa;
        for(i=0;i<n;i++){
            scanf("%d", &m);
            map <int,int> mapa2;
            for(j=0;j<m;j++){
                scanf("%d", &aux);
                if(mapa2[aux]<1){
                    vec[i].pb(aux);
                    mapa[aux]++;
                }
                mapa2[aux]++;    
            }
        }
        double cont=0, contf=0, vet[101010];
        for(i=0;i<n;i++){
            cont=0;
            for(j=0;j<vec[i].size();j++){
                if(mapa[vec[i][j]]<=1){
                    cont++;
                    contf++;
                }
            }
            vet[i]=cont;
        }
        printf("Case %d:", ++casos);
        for(i=0;i<n;i++){
            printf(" %.6lf%%", (((double)vet[i]/(double)contf)*(double)100.0));
        }
        printf("\n");
    }
}
