#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define pb push_back
using namespace std;
vector<vector<int>> mat;
int linha[101010];
void output(int n){
	for(int i=0;i<n;i++){
		cout << i <<":";
		for(int j=0;j<mat[i].size();j++){
			cout << " " << mat[i][j];
		}
		cout << endl;
	}
}
int find(int num, int line){
	for(int i=0;i<mat[line].size();i++){
		if(mat[line][i]==num) return i;
	}
}

vector<int> ini(string s1, int a){
	vector<int> tempv;
	int it=find(a,linha[a]);
	if(s1=="move"){
			tempv.pb(mat[linha[a]][it]);
			//retornando eles para a pilha original
			for(int i=it+1;i<mat[linha[a]].size();i++){
				int aux = mat[linha[a]][i];
				linha[aux]=aux;
				mat[aux].pb(aux);
			}
			
	}
	else{
		for(int i=it;i<mat[linha[a]].size();i++){
			int aux = mat[linha[a]][i];
			tempv.pb(aux);
		}
	}
	//tirando da primeira pilha
	mat[linha[a]].erase(mat[linha[a]].begin()+it,
						mat[linha[a]].end());
	return tempv;
}

void fin(string s2, int b, vector<int>& tempv){
	if(s2=="onto"){
		int it = find(b, linha[b]);
		for(int i=it+1;i<mat[linha[b]].size();i++){
			int aux = mat[linha[b]][i];
				linha[aux]=aux;
				mat[aux].pb(aux);
		}
		mat[linha[b]].erase(mat[linha[b]].begin()+it+1,
								mat[linha[b]].end());		
	}
	for(int i=0;i<tempv.size();i++){
		linha[tempv[i]] = linha[b];
		mat[linha[b]].pb(tempv[i]);
	}	
}

int main(void){
	int n, a, b;
	cin >> n;
	string s1, s2;
	mat.resize(n);
	for(int i=0;i<n;i++) mat[i].pb(i);
	for(int i=0;i<n;i++) linha[i] = i;	
	while(cin >> s1 >> a >> s2 >> b,s1!="quit"){
		if(linha[a]==linha[b]) continue;
		vector <int> tempv=ini(s1,a);
		fin(s2, b, tempv);
	}
