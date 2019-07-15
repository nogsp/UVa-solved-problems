#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define pb push_back
using namespace std;

vector <int> pai, hated;

int find(int a){
	if(a==pai[a]) return a;
	return pai[a] = find(pai[a]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return; 
	pai[b] = a;
}

bool areEnemies(int a, int b){
	int ax = find(a), bx = find(b), ae, be;
	  
	if(hated[ax]==-1 || hated[bx]==-1) return false;
	 
	if(find(hated[ax])==bx || find(hated[bx])==ax) return true;
	else return false;
}

bool areFriends(int a, int b){
	if(find(a)==find(b)) return true;
	else return false;
}

void setFriends(int a, int b){
	int ax = find(a), bx = find(b), ae, be;
	if(!areEnemies(ax, bx)){	
		join(ax, bx);
		if(hated[ax]==-1 && hated[bx]==-1) return;
		else if(hated[bx]==-1) return;
		else if(hated[ax]==-1){
			hated[ax] = find(hated[bx]);
			hated[hated[ax]] = ax;	
		}
		else{
			ae = find(hated[ax]);
			be = find(hated[bx]);
			join(ae, be);
		}
			
	}else printf("-1\n");
}

void setEnemies(int a, int b){
	int ax, bx, ae, be;
    if(!areFriends(a, b)){
    	ax = find(a);
    	be = find(b);
    	if(hated[ax]==-1 && hated[be]==-1){
    		hated[ax] = be;
    		hated[be] = ax;
    	}else if(hated[ax]==-1){
    		bx = find(hated[be]);
    		join(ax, bx);
    		hated[ax] = be;
    		hated[be] = ax;
    	}else if(hated[be]==-1){
    		ae = find(hated[ax]);
    		join(ae, be);
    		hated[be] = ax;
    		hated[ax] = ae;
    	}
    	else{
    		ae = find(hated[ax]);
    		bx = find(hated[be]);	
    		join(ax, bx);
    		join(ae, be);
    	}
    }	
}

int main(){
    int n, op, a, b;
    scanf("%d", &n);
    pai.resize(n);
    for(int i=0;i<n;i++){
        hated.pb(-1);
        pai[i]=i;
    } 
    while(scanf("%d %d %d", &op, &a, &b), op!=0){
    	if(op==1) setFriends(a, b);
    	else if(op==2) setEnemies(a, b);
    	else if(op==3){
    		if(areFriends(a, b)) printf("1\n");
    		else printf("0\n");
    	} 
    	else{
    		if(areEnemies(a, b)) printf("1\n");
    		else printf("0\n");
    	}
    }
    return 0;
}
