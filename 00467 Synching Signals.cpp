#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;

bool allGreen(int cont,vector<int>& vec){
	int n=vec.size();
	for(int i=0;i<n;i++){
		int aux=cont%(vec[i]*2);
		if(aux>=(vec[i])-5) return false;
	}
	return true;
}


int main(void){
	string line;
	int casos=0;
	while(getline(cin,line)){
		vector<int> vec;
		stringstream s1(line);
		int min=-1;
		int aux;
		while(s1>>aux){
			vec.push_back(aux);
			if(aux<min || min==-1) min = aux;
		}
		int n=vec.size();
		int cont;
		int i, j;
		bool key=false;
		for(cont=(min*2);cont<=3600;cont++){
			if(allGreen(cont,vec)) break;
		}
		if(cont<=3600)printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",++casos,cont/60,cont%60);
		else printf("Set %d is unable to synch after one hour.\n",++casos );
	}
}
