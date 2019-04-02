#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	int l;
	while(scanf("%d", &l), l!=0){
		l--;
		int dir=0;
		while(l--){
			string s;
			//printf("dir antes = %d\n", dir);
			cin >> s;
			// +x=0, -x=1, +y=2, -y=3, +z=4, -z=5
			if(s=="+z"){
				//printf("entrei z\n");
				if(dir==0) dir=4;
				else if(dir==1) dir=5;
				else if(dir==2) dir=2;
				else if(dir==3) dir=3;
				else if(dir==4) dir=1;
				else if(dir==5) dir=0;
			}else if(s=="-z"){
				if(dir==0) dir=5;
				else if(dir==1) dir=4;
				else if(dir==2) dir=2;
				else if(dir==3) dir=3;
				else if(dir==4) dir=0;
				else if(dir==5) dir=1;
			}else if(s=="+y"){
				if(dir==0) dir=2;
				else if(dir==1) dir=3;
				else if(dir==2) dir=1;
				else if(dir==3) dir=0;
				else if(dir==4) dir=4;
				else if(dir==5) dir=5;
			}else if(s=="-y"){
				if(dir==0) dir=3;
				else if(dir==1) dir=2;
				else if(dir==2) dir=0;
				else if(dir==3) dir=1;
				else if(dir==4) dir=4;
				else if(dir==5) dir=5;
			}
			//printf("dir depois = %d\n", dir); 
		}
		if(dir==0) printf("+x\n");
		else if(dir==1) printf("-x\n");
		else if(dir==2) printf("+y\n");
		else if(dir==3) printf("-y\n");
		else if(dir==4) printf("+z\n");
		else printf("-z\n");
	}
	return 0;
}
