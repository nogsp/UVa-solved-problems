#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(void){
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		int tam1=s1.size(), tam2=s2.size();
		int tam = max(tam1,tam2);
		for(int i=0;i<tam;i++){
			if(i<tam1){
				if(s1[i]>=65 && s1[i]<=90) s1[i]+=32;
			}
			if(i<tam2){
				if(s2[i]>=65 && s2[i]<=90) s2[i]+=32;	
			}
		}
		int cont1=0, cont2=0;
		for(int i=0;i<tam1;i++){
			if(s1[i]>=97 && s1[i]<=122){
				cont1+= s1[i]-'a'+1;
			}
		}
		for(int i=0;i<tam2;i++){
			if(s2[i]>=97 && s2[i]<=122){
				cont2+= s2[i]-'a'+1;
			}
		}
		//printf("cont1=%d   cont2=%d\n", cont1, cont2);
		int numero=cont1;
		int soma=0;
		int divi=1;
		while(numero>=10){
			divi=1;
			soma=0;
			while(numero>divi){
				soma += (numero/divi)%10;
				//printf("%d\n", soma);
				divi*=10;
			}
			numero = soma;
			if(numero==10){
				numero=1;
				break;
			}
		}	
		double num1 = numero;	
		numero = cont2;
		//printf("\n");
		while(numero>=10){
			divi=1;
			soma=0;
			while(numero>divi){
				soma += (numero/divi)%10;
				//printf("%d\n", soma);
				divi*=10;
			}
			numero = soma;
			if(numero==10){
				numero=1;
				break;
			}
		}
		double num2 = numero;
		//printf("num1 %.2lf   num2 %.2lf\n",num1,num2);
		printf("%.2lf %%\n",(min(num1,num2)/max(num1,num2))*100 );

	}
}
