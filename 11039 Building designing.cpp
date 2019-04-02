#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	while(n--){
		int p, red[101010], blue[101010], rsize=0,bsize=0;
		int lado, aux, topo;
		scanf("%d", &p);
		for(int i=0;i<p;i++){
			scanf("%d", &aux);
			if(aux>0){
				blue[bsize++]=aux;
			}else{
				red[rsize++]=((-1)*aux);
			}
		}
		int r=0,b=0, cont=0;
		sort(red, red+rsize);
		sort(blue, blue+bsize);
		if(red[0]<blue[0]){
			lado=1;
			topo=red[r++];
		}else{
			lado=0;
			topo=blue[b++];
		}
		cont++;
		while(true){
			if(!lado){
				lado=1;
				while(red[r]<topo && r<rsize) r++;
				if(r==rsize) break;
				if(red[r]>topo){
					topo = red[r++];
					cont++;
				}else break;
			}else{
				lado=0;
				while(blue[b]<topo && b<bsize) b++;
				if(b==bsize) break;
				if(blue[b]>topo){
					topo = blue[b++];
					cont++;
				}else break;
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
