#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	double topo, sob, desc, fat;
	while(scanf("%lf %lf %lf %lf", &topo,&sob,&desc,&fat),topo!=0){
		fat = (fat*0.01) * sob;
		double pos=0;
		int fim, day=1;
		while(1){
			//printf("%d  %.2lf  %.2lf  ", day, pos, sob);
			pos += sob;
			//printf("%.2lf  ", pos);
			sob -= fat;
			if(sob<0) sob = 0;
			
			if(pos>topo){
				fim=0;
				break;	
			}
			
			pos-=desc;
			//printf("%.2lf\n", pos);
			if(pos<0){
				fim=1;
				break;
			}
			//printf("\n");
			day++;
		}
		if(!fim) printf("success on day %d\n", day);
		else printf("failure on day %d\n", day);
	}
}
 
