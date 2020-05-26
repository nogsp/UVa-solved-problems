#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll vet[10101010], vetResp[10101010], found;
vector <ll> vec, vecResp;

ll maxi; 
void backTrack(ll i, ll sum, ll k, ll n){
	if(i==n){
		if(found==1) return;
		if(sum == k) found = 1;
		if(sum<=k && sum>maxi){
			maxi = sum;
			for(ll i=0;i<n;i++){
				vetResp[i] = vet[i];
			}
		}
	}else{
		vet[i] = 1;
		sum += vec[i];
		if(sum<=k) backTrack(i+1, sum, k, n);
		vet[i] = 0;
		sum -= vec[i];
		backTrack(i+1, sum, k, n);
	}
}

int main(){
	ll n;
	while(scanf("%lld", &n)==1){
		//globais para o backtrack
		vec.clear();
		for(int i=0;i<50;i++) vet[i] = vetResp[i] = 0;
		maxi = 0;
		found = 0;
		//
		ll tam;
		scanf("%lld", &tam);
		while(tam--){
			ll aux;
			scanf("%lld", &aux);
			vec.pb(aux);
		}
		backTrack(0, 0, n, vec.size());
		for(ll i=0;i<vec.size();i++){
			if(vetResp[i]==1) printf("%lld ", vec[i]);
		}
		printf("sum:%lld\n", maxi);
	}
}
