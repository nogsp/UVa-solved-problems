#include <iostream>
#include<algorithm>

int main(void){
	string s;
	while(cin >> s, s!="#"){
		if(next_permutation(s.begin(), s.end())){
			cout << s << endl;
		}else cout << "No Successor" << endl;
	}
    return 0;
}
