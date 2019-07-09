#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int find(int a, vector<int>& pai){
	if(a==pai[a]) return a;
	return pai[a] = find(pai[a],pai);
}

void join(int a, int b, vector<int>& pai, vector<int>& peso){
	a = find(a, pai);
	b = find(b, pai);
	if(a==b) return;
	if(peso[a]>peso[b]){
		pai[b] = a;
	}
	else if(peso[a]<peso[b]){
		pai[a] = b;
	}
	else{
		pai[a] = b;
		peso[b]++;
	}
}
int getnumber(string& s, int& i){
	int num = 0, sz = s.size();
	i++;
	for(;i<sz;i++){
		if(s[i]>='0' && s[i]<='9'){
			num = (num*10) + (s[i]-'0');
		}else break;
	}
	num--;
	return num;
		
}
int main(){
    int t;
    scanf("%d", &t);	
    while(t--){
    	int n;
    	scanf("%d", &n);
    	vector <int> pai, peso;
    	pai.resize(n);
    	peso.resize(n);
    	for(int i=0;i<n;i++){
    		peso[i]=0;
    		pai[i]=i;
    	}
    	int a, b;
    	string s;
    	cin.ignore();
    	int hit=0, miss=0;
    	while(getline(cin,s)){
    	    if(s=="") break;
    	    int k=1;
    		a = getnumber(s,k);
    		b = getnumber(s,k);
    		//printf("%d %d\n", a, b);
    		if(s[0]=='c')join(a, b, pai, peso);
    		else{
    			if(find(a,pai)==find(b,pai)) hit++;
    			else miss++;
    		}
    	}
    	printf("%d,%d\n", hit, miss);
    	if(t) printf("\n");
    }
    return 0;
}
