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
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	int n; cin>>n;
	bool r=0;
	vector<string> arr;
	set<int> two[26];
	set<int> tiga[26];
	map<string,int> tri;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		arr.pb(s);
	}
	for(auto s:arr){
		if(s.size()==1||s.size()==2&&s[0]==s[1]||s.size()==3&&s[0]==s[2]){
			cout<<"YES"<<endl;
			return;
		}
		if(s.size()==2){
			int l=s[0]-'a';
			int r=s[1]-'a';
			if(two[r].find(l)!=two[r].end()){
				cout<<"YES"<<endl;
				return;
			}
			if(tiga[r].find(l)!=tiga[r].end()){
				cout<<"YES"<<endl;
				return;
			}
			two[l].insert(r);
		}else{
			int a=s[0]-'a';
			int b=s[1]-'a';
			int c=s[2]-'a';
			tri[s]++;
			reverse(s.begin(),s.end());
			if(tri[s]||two[c].find(b)!=two[c].end()){
				cout<<"YES"<<endl;
				return;
			}
			tiga[a].insert(b);
		}
	}
	cout<<"NO"<<endl;
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
