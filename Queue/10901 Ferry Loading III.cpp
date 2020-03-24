#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

struct carro{
	int tempo;
	int resp;
	int index;
};

bool cmp(carro a, carro b){
	return a.index<b.index;
} 

int main(void){
	int casos=0, c;
	scanf("%d", &c);
	while(c--){
		if(casos++) printf("\n");
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		int side=0;
		queue <carro> left, right;
		int mx=m;
		int i=0;
		while(mx--){
			carro aux;
			string s;
			cin >> aux.tempo >> s;
			aux.index=i;
			if(s=="left") left.push(aux);
			else right.push(aux);
			i++;
		}
		int time=0, cont=0;
		vector<carro> resposta;
		while(1){
			if(left.empty() and right.empty()) break;
			cont=0;
			if((left.front().tempo<=time && !left.empty()) ||
						(right.front().tempo<=time && !right.empty())){
				if(side==0){
					while(left.front().tempo<=time && !left.empty()){
						cont++;
						carro aux=left.front();
						aux.resp=time+t;
						resposta.pb(aux);
						left.pop();
						if(cont==n) break;
					}
					side=1;
				}else{
					while(right.front().tempo<=time && !right.empty()){
						cont++;
						carro aux=right.front();
						aux.resp=time+t;
						resposta.pb(aux);
						right.pop();
						if(cont==n) break;
					}
					side=0;
				}
				time+=t;
			}else time++;
		}
		sort(resposta.begin(), resposta.end(), cmp);
		for(int i=0;i<resposta.size();i++){
			cout << resposta[i].resp << endl;
		}
	}
}
