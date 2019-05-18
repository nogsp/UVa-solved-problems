#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)==1){
		vector <int> pilha;
		queue <int> fila;
		priority_queue <int> heap;
		int p=1,f=1,h=1;
		while(n--){
			int op, num;
			scanf("%d %d", &op, &num);
			if(op==1){
				pilha.push_back(num);
				fila.push(num);
				heap.push(num);
			}else{
				int get;
				if(!pilha.empty()){
					get = pilha.back();
					pilha.pop_back();
					if(get!=num) p = 0;
				}else p = 0;
				if(!fila.empty()){
					get = fila.front();
					fila.pop();
					if(get!=num) f = 0;
				}else f = 0;
				if(!heap.empty()){
					get = heap.top();
					heap.pop();
					if(get!=num) h = 0;
				}else h = 0;	
			}
		}
		int counter = h + f + p;
		if(counter==0) cout << "impossible" << endl;
		else if(counter > 1) cout << "not sure" << endl;
		else{
			if(h) cout << "priority queue" << endl;
			else if(f) cout << "queue" << endl;
			else cout << "stack" << endl;
		}
	}
	return 0;
}
