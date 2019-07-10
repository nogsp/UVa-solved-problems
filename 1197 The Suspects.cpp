#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int find(int a, vector<int>& pai){
	if(a==pai[a]) return a;
	return pai[a] = find(pai[a],pai);
}

void join(int a, int b, vector<int>& pai, vector<int>& peso){
	a = find(a, pai);
	b = find(b, pai);
	if(a==b) return;
	if(peso[a]>peso[b]){
		pai[b] = a;
	}
	else if(peso[a]<peso[b]){
		pai[a] = b;
	}
	else{
		pai[a] = b;
		peso[b]++;
	}
}

int main(){
    int n, m;	
    while(scanf("%d %d", &n, &m), n!=0 || m!=0){
    	vector <int> pai, peso;
    	pai.resize(n+1000);
    	peso.resize(n+1000);
    	for(int i=0;i<n;i++){
    		peso[i]=0;
    		pai[i]=i;
    	}
	    while(m--){
	    	int a, b, k;
	    	scanf("%d", &k);
	    	if(k>0){
	    		scanf("%d", &a);
	    		k--;	
	    	}
	    	while(k--){
	    		scanf("%d", &b);
	    		join(b,a,pai,peso);	    		
	    	}
	    }	
    	int sick, sn=1;
    	sick = find(0,pai);
    	for(int i=1;i<n;i++){
    		if(find(i,pai)==sick) sn++;
    	}
    	printf("%d\n", sn);
    }
    return 0;
}
