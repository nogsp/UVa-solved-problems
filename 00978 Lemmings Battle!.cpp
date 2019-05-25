#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define pb push_back
using namespace std;

int main(){
	int k, casos = 0;
	cin >> k;
	while(k--){
		int b, sg, sb, aux;
		cin >> b >> sg >> sb;
		priority_queue <int> bArmy, gArmy;
		for(int i=0;i<sg;i++){
			cin >> aux;
			gArmy.push(aux);
		}
		for(int i=0;i<sb;i++){
			cin >> aux;
			bArmy.push(aux);
		}
		bool gw=false, bw=false;
		while(1){
			vector <int> bBattle, gBattle;
			for(int bat=0;bat<b;bat++){
				if(bArmy.empty() && gArmy.empty()) break;
				if(bArmy.empty()){
					gBattle.pb(gArmy.top());
					gArmy.pop();
				}else if(gArmy.empty()){
					bBattle.pb(bArmy.top());
					bArmy.pop();
				}else{
					int blue = bArmy.top(), green = gArmy.top();
					bArmy.pop();
					gArmy.pop();
					if(blue > green) bBattle.pb(blue - green);
					else if(blue < green) gBattle.pb(green - blue);
				}	
			}
			for(int i=0, sz=bBattle.size();i<sz;i++){
				bArmy.push(bBattle[i]);
			}
			for(int i=0, sz=gBattle.size();i<sz;i++){
				gArmy.push(gBattle[i]);
			}
			if(bArmy.empty() && gArmy.empty()) break;
			if(bArmy.empty()){
				gw = true;
				break;
			}
			if(gArmy.empty()){
				bw = true;
				break;
			}			
		}
		if(casos++) printf("\n");
		if(gw == false && bw == false) cout << "green and blue died" << endl;
		else if (gw == true){
			cout << "green wins" << endl;
			while(!gArmy.empty()){
				cout << gArmy.top() << endl;
				gArmy.pop();
			}
		}else{
			cout << "blue wins" << endl;
			while(!bArmy.empty()){
				cout << bArmy.top() << endl;
				bArmy.pop();
			}
		}
	}
	return 0;
}
