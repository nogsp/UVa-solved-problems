#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define maxi 1000000000

using namespace std;

vector <ll> vec;

bool isOK(ll k){
	if(vec[0]>k) return false;
	else if (vec[0]==k) k--;
	for(int i=1;i<vec.size();i++){
		ll need = vec[i] - vec[i-1];
		if(need>k) return false;
		else if(need==k) k--;
	}
	return true;
}

ll binarySearch(ll ini, ll fin){
	ll l = ini, r=fin, resp, m;
	while(l<=r){
		m = (l+r)/2;
		if(isOK(m)){
			resp = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	return resp;
} 
 
int main(){ 
	ll t, casos=0;
	scanf("%lld", &t);
	while(t--){
		ll n, aux;
		scanf("%lld", &n);
		vec.clear(); 
		for(int i=0;i<n;i++){
			scanf("%lld", &aux);
			vec.pb(aux);
		}
		//printf("%d\n", isOK(5));
		printf("Case %lld: ", ++casos);
		printf("%lld\n", binarySearch(0, maxi));
	}
}
