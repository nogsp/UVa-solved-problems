#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		set <long long int> myset;
		vector <long long int> vec;
		for(int i=0;i<n;i++){
			long long int snow;
			scanf("%lld", &snow);
			vec.pb(snow);
		}
		long long int resp=0, cont=0, p=0, q=0;
		while(q<n){
			if(!myset.count(vec[q])) myset.insert(vec[q++]);
			else{
				myset.erase(vec[p++]);
			}
			resp = max(resp, q-p);
		}
		cout << resp << endl;
			
	}
	return 0;
}
