#include<iostream>
#include<cstdio>
using namespace std;

int g(long long int super){
	if(super<10) return super;
	else{
		long long int cont=0, divi=1, final;
		while(super>=divi){
			final = super/divi;
			divi*=10;
			cont+=final%10;
		}
		return g(cont);
	}
}

int main(void){
	long long int super;
	while(scanf("%lld", &super), super){
		printf("%d\n", g(super));
	}
}
