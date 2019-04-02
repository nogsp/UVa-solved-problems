#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int n, p;
	int casos=0;
	int ajuda=0;
	while(scanf("%d %d",&n,&p),n!=0||p!=0){
		cin.ignore();
		string saux;
		for(int i=0;i<n;i++){
			getline(cin,saux);
		}
		
		string bestMark, mark;
		double bestValue=0, value, np, bestCompliance=0;
		bool key=true;
		for(int i=0;i<p;i++){
			getline(cin,mark);
			cin >> value >> np;
			cin.ignore();
			for(double j=0;j<np;j++){
				getline(cin,saux); 
			}
			if(np==bestCompliance){
				if(value<bestValue || key==true){
					bestMark.clear();
					bestMark = mark;
					bestCompliance = np;
					bestValue = value; 
					key=false;
				}
			}
			else if(np>bestCompliance){
				bestMark.clear();
				bestMark = mark;
				bestCompliance = np;
				bestValue = value;
				key=false;
			}
		}
		if(ajuda) printf("\n");
		printf("RFP #%d\n",++casos);
		cout << bestMark << endl;
		ajuda++;

	}
}
