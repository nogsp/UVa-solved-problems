#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
using namespace std;
pair <int,int> resp;

bool solve(vector<string>& words, int q, int nw){
    map <string, int> mapa;
    int sz = words.size();
    int aw=0, p=0;
    for(int i=p;i<=q;i++){
        mapa[words[i]]++;
        if(mapa[words[i]]==1) aw++;
    }
    for(;q<sz;p++,q++){	
	    if(aw==nw){
    		resp = {p+1,q+1};
    		return true;	
    	}
	    if(mapa[words[p]]==1) aw--;
	    mapa[words[p]]--;
	    if(q<sz-1){
	    	mapa[words[q+1]]++;
	    	if(mapa[words[q+1]]==1) aw++;
	    }	
    }
    return false;
}
int main(){
	int t, casos=0;
    cin >> t;
    cin.ignore();
    string s;
    while(t--){
        vector <string> words;
        set <string> myset;
        int nw=0;
        while(getline(cin,s), s!="END"){
           string buffer="";
            for(int i=0, sz=s.size();i<sz;i++){
                if(isalpha(s[i])) buffer+=s[i];
                if(!isalpha(s[i])||i==sz-1){
                    if(buffer!=""){
                        if(myset.count(buffer)==0){
                            myset.insert(buffer);
                            nw++;
                        }
                        words.pb(buffer);
                        buffer="";
                    }
                }
            }
       }
       int p, q, i=nw-1, r=words.size()-1, m;
       cout << "Document " << ++casos << ": ";
       while(i<=r){
			m = (i+r)/2;
			if(solve(words, m, nw)){
				r = m-1;
			}
			else{
				i = m+1;
			}
		}
       cout << resp.first << " " << resp.second << endl;
    }
	return 0;
}
