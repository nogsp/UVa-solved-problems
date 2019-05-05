#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <ctype.h>
#include <set>
#include <algorithm>
#define pb push_back
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
	if(a.first!=b.first) return a.first > b.first;
	return a.second < b.second; 
}

int main(void){
	string line;
	while(1){
		string empresa, userid;
		map <string, string> dic;
		map <string, int> counter;
		set <string> myset;
		vector <pair<int, string>> resp;
		while(getline(cin, line)){
			if(line[0]=='0') goto end;
			if(line[0]=='1') break;
			if(line[0]>='A' && line[0]<='Z'){
				empresa = line;
				resp.pb({0,empresa});
				myset.clear();
			}else{
				userid = line;
				if(dic.count(userid)==0){
					counter[empresa]++;
					dic[userid] = empresa;
					myset.insert(userid);
				}else if(myset.count(line)!=0) continue;
				else{
					if(dic[userid]=="SalgadosDoWash") continue;
					else{
						counter[dic[userid]]--;
						dic[userid] = "SalgadosDoWash";
					}
				}
			}	
		}
		for(int i=0, tam = resp.size();i<tam;i++){
			resp[i].first = counter[resp[i].second];
		}
		sort(resp.begin(), resp.end(), cmp);
		for(int i=0, tam = resp.size();i<tam;i++){
			cout << resp[i].second << " " << resp[i].first << endl;
		}
	}
	end:
	return 0;
}
