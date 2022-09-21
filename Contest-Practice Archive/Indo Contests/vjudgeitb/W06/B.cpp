#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

const string op="+-*/^";
const string cc="()";

string rec(string s){
	if((int)s.size()==1)return s;
	ll cur=0;
	string l,ret,temp;
	for(int i=1;i<s.size()-1;i++){
		if(s[i]==cc[0])cur++;
		if(s[i]==cc[1])cur--;
		temp+=s[i];
		if(cur==0)for(int j=0;j<op.size();j++){
			if(s[i]==op[j]){
				ret=s[i];
				l=temp;
				l.pop_back();
				temp="";
			}
		}
	}
	return rec(l)+rec(temp)+ret;
}

void solve(){
	string s; cin>>s;
	cout<<rec(s)<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

