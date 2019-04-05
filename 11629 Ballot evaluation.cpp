#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(void){
    int n, m, casos=0;
    map <string, int> mapa;
    string s;
    scanf("%d %d", &n , &m);
    while(n--){
        int aux1,aux2;
        cin >> s;
        scanf("%d.%d",&aux1,&aux2);
        mapa[s]=((aux1*10)+aux2);
    }
    int op=0;    
    while(m--){
    	int cont=0;
	    cin >> s;
    	cont = mapa[s];
	    while(1){
	        cin >> s;
	        if(s=="<"){
	            op=0;
	            break;
	        }
	        if(s=="<="){
	            op=1;
	            break;
	        }
	        if(s==">"){
	            op=2;
	            break;
	        }
	        if(s==">="){
	            op=3;
	            break;
	        }
	        if(s=="="){
	            op=4;
	            break;
	        }
	        if(s=="+"){
	            cin >> s;
	            cont += mapa[s];
	        }
	    }    
	    int fin;
	    cin >> fin;
	    fin*=10;
	    cout << "Guess #" << ++casos << " ";
	    if(op==0){
	        if(cont<fin) cout << "was correct." << endl;
	        else cout << "was incorrect." << endl;
	    }
	    if(op==1){
	        if(cont<=fin) cout << "was correct." << endl;
	        else cout << "was incorrect." << endl;
	    }
	    if(op==2){
	        if(cont>fin) cout << "was correct." << endl;
	        else cout << "was incorrect." << endl;
	    }
	    if(op==3){
	        if(cont>=fin) cout << "was correct." << endl;
	        else cout << "was incorrect." << endl;
	    }
	    if(op==4){
	        if(cont==fin) cout << "was correct." << endl;
	        else cout << "was incorrect." << endl;
	    }
	}
}
