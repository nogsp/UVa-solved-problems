#include<bits/stdc++.h>
#define pb push_back
using namespace std;
map <string,int> mapa;
int contw;
string prepareString(string& s, int tam){
	for(int i=0;i<tam;i++){
		if(s[i]>=65 && s[i]<=90){
			s[i]+=32;
		}
		if(s[i]==','||s[i]=='.'||s[i]==':'||s[i]==';'||
		s[i]=='!'||s[i]=='?'||s[i]=='"'||s[i]=='('||s[i]==')'){
			s[i]=' ';
		}
	}
	return s;
}

void insertMap(string& s, int tam){
	string auxs;
	stringstream ss(s);
	while(ss >> auxs){
		mapa[auxs]++;
		contw++;
	}

}

double calcEt(){
	double soma=0;
	for(auto it=mapa.begin();it!=mapa.end();it++){
		soma+=(it->second*(log10(contw)-log10(it->second)));
	}
	return soma = (double)soma/contw;
}

double calcEmax(){
	return log10(contw);
}

int main(void){
	string s;
	while(getline(cin,s),s!="****END_OF_INPUT****"){
		mapa.clear();
		contw=0;
		s = prepareString(s,s.size());
		insertMap(s,s.size());
		while(getline(cin,s),s!="****END_OF_TEXT****"){
			s = prepareString(s,s.size());
			insertMap(s,s.size());
		}
		double Et = calcEt();
		double Emax = calcEmax();
		double Erel = ((double)((double)Et/(double)Emax)*100);
		int c=ceil(((double)((double)Et/(double)Emax)*100));
		int f=floor(((double)((double)Et/(double)Emax)*100));
		if((double)c-Erel<=Erel-(double)f) printf("%d %.1lf %d\n", contw, Et, c);
		else printf("%d %.1lf %d\n", contw, Et, f);
		 
	}
}
