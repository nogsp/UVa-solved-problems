#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
vector<pair<string, string>> books, taken, returned;
void estoque(){
	string s;
	while(getline(cin,s),s!="END"){
		int cont=0, i=0;
		string title, name;
		for(i=0;i<s.size();i++){
			if(s[i]=='"') cont++;
			name+=s[i];
			if(cont>=2){
				i+=5;
				break;
			}
		}
		for(;i<s.size();i++){
			title+=s[i];
		}
		books.push_back({title,name});
	}
		
}

void BORROW(string title){
	int it;
	pair<string, string> aux;
	for(int i=0;i<books.size();i++){
		if(books[i].second==title){
			it=i;
			aux = books[i];
			break;	
		} 
	}
	taken.push_back(aux);
	books.erase(books.begin()+it); 
}

void RETURN(string title){
	int it;
	pair<string, string> aux;
	for(int i=0;i<taken.size();i++){
		if(title==taken[i].second){
			aux = taken[i];
			it = i;
			break;
		}
	}
	returned.push_back(aux);
	taken.erase(taken.begin()+it);
	sort(returned.begin(), returned.end());
}

void SHELVE(){
	int it;
	for(int i=0;i<returned.size();i++){
		books.push_back(returned[i]);
		sort(books.begin(), books.end());
		for(int j=0;i<books.size();j++){
			if(books[j].second==returned[i].second){
				it = j;
				break;
			}
		}
		//cout << it << endl;
		cout << "Put " << books[it].second;
		if(it) cout << " after " << books[it-1].second << endl;
		else cout << " first" << endl;
	}
	cout << "END" << endl;
	returned.clear();
}

int main(void){
	estoque();	
	sort(books.begin(), books.end());
	while(1){
		string op, title, temp;
		cin >> op;
		if(op=="END") break;
		if(op=="SHELVE") SHELVE();
		else{
			getline(cin,temp);	
			for(int i=1;i<temp.size();i++){
				title+=temp[i];
			}
			//cout << title << endl;	
			if(op=="BORROW"){ 
				BORROW(title);
			}
			else if(op=="RETURN"){
			 	RETURN(title);	
			}
			
		}
	} 	
}
