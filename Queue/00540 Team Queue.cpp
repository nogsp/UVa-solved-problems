#include<iostream>
#include<cstdio>
#include<queue>
#define pb push_back
using namespace std;

int main(void){
	int casos=0;
	int tnumber;
	while(scanf("%d", &tnumber), tnumber){
		queue <int> teams[tnumber];
		int time[1000001];
		for(int t=0;t<tnumber;t++){	
			int tmembers;
			scanf("%d", &tmembers);
			while(tmembers--){
				int member;
				scanf("%d", &member);
				time[member]=t;
			}
		}
		printf("Scenario #%d\n", ++casos);
		queue <int> teamqueue;
		char op[101010];
		while(scanf("%s", op), op[0]!='S'){
			if(op[0]=='E'){
				int num;
				scanf("%d", &num);
				int t=time[num];
				if(teams[t].empty()) teamqueue.push(t);
				teams[t].push(num);
			}
			else{
				int t=teamqueue.front();
				int num=teams[t].front();
				teams[t].pop();
				printf("%d\n", num);
				if(teams[t].empty()) teamqueue.pop();
			}

		}
		printf("\n");
	}
}
