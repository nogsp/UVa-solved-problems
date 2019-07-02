#include <iostream>
#include <vector>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define pb push_back 
using namespace std;

int mark[101010], counter;
vector<vii> grafo;
vi vec;


int main(){
    int l, c;
    while(scanf("%d %d", &l, &c)==2){    
        grafo.clear();
        printf("%d %d\n", c, l);
        grafo.resize(c);
        for(int i=1;i<=l; i++){
            int n, x;
            vector <int> vec;
            scanf("%d", &n);
            for(int j=0;j<n;j++){
                scanf("%d" ,&x);
                vec.pb(x-1);
            }
            for(int j=0;j<n;j++){
                scanf("%d", &x);
                grafo[vec[j]].pb({x,i});
            }
        }
        for(int i=0;i<c;i++){
            int sz=grafo[i].size();
            printf("%d", sz); 
            for(int j=0;j<sz;j++){
                printf(" %d", grafo[i][j].second);
            }printf("\n");
            for(int j=0;j<sz;j++){
                if(j) printf(" ");
                printf("%d", grafo[i][j].first);
            }
            printf("\n");
        }
    }                                                                                                                                                                                                
	return 0;
}
