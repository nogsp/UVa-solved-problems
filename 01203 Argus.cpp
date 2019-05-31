#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#define pii pair<int, int>
#define pb push_back
using namespace std;
map <int, int> freqn;
priority_queue<pii,vector<pii>,greater<pii>> argus;
bool cmp(pii a, pii b){ return a.second<b.second; }

int main(){
	string s;
	int qnum, freq,k, kn=0;
	while(cin >> s, s!="#"){
		scanf("%d %d", &qnum, &freq);
		freqn[qnum] = freq;
		argus.push({freq, qnum});
	}
	scanf("%d", &k);
	while(1){
		vector<pii> vec;
		vec.pb(argus.top());
		argus.pop();
		while(vec[0].first==argus.top().first){
			vec.pb(argus.top());
			argus.pop();
		}
		sort(vec.begin(), vec.end(), cmp);
		int i, sz;
		for(i=0, sz=vec.size();i<sz;i++){
			cout << vec[i].second << endl;
			vec[i].first += freqn[vec[i].second];
			argus.push(vec[i]);
			kn++;
			if(k==kn) break;
		}
		if(kn==k) break;
	}
	return 0;
}
