#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;

set<int> ab,ba;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='B')ab.insert(i);
		if(s[i]=='B'&&s[i+1]=='A')ba.insert(i);
	}
	if(ab.size()==0||ba.size()==0)cout<<"NO"<<endl;
	else if(abs(*ab.rbegin()-*ba.begin())>1)cout<<"YES"<<endl;
	else if(abs(*ba.rbegin()-*ab.begin())>1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
