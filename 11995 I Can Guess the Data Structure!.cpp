#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    
    while(cin >> n){
        int op, num;
        vector<int> pilha;
        queue<int> fila;
        priority_queue<int> heap;
        bool p=1,f=1,h=1;
        while(n--){    
            cin >> op >> num;
            if(op==1){
                pilha.push_back(num);
                fila.push(num);
                heap.push(num);
            }
            else{
                int aux;
                if(p){    
                    if(pilha.empty()){
                        p=0;
                    }
                    else{ 
                    aux = pilha.back();
                    pilha.pop_back();
                    if(aux!=num) p=0;
                    }
                }
                if(f){
                    if(fila.empty()){
                        f=0;
                    }
                    else{
                    aux = fila.front();
                    fila.pop();
                    if(aux!=num) f=0;
                    }
                }
                if(h){
                    if(heap.empty()){
                        h=0;
                    }
                    else{
                    aux = heap.top();
                    heap.pop();
                    if(aux!=num) h=0;
                    }
                }
            }
        }
        if(p+h+f>1) cout << "not sure" << endl;
        else if(p+h+f==0) cout << "impossible" << endl;
        else{
            if(p) cout << "stack" << endl;
            else if(f) cout << "queue" << endl;
            else cout << "priority queue" << endl;
        }
    }
}
