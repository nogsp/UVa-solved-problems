#include <iostream>
#include <set>
#define pb push_back
using namespace std;

int main(){
	string line;
	set <string> myset;
	while(getline(cin, line)){
		string buffer="";
		for(int i=0, sz=line.size();i<sz;i++){
			if(isalpha(line[i])){
				buffer += line[i];
				if(i<sz-1) continue;
			}	
			if(buffer!=""){
				for(int j=0;j<buffer.size();j++) 
					if(buffer[j]>='A' && buffer[j]<='Z') buffer[j] += 32;
				if(myset.count(buffer)==0) myset.insert(buffer);	
				buffer = "";
			}
		}
	}
	for(auto it = myset.begin();it != myset.end();it++) cout << *it << endl;
	return 0;
}
