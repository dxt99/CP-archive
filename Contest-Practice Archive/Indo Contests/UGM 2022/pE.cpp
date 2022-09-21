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

int stoii(char c){
	return c-'0';
}

void solve(){
	string s; cin>>s;
	if(s.size()==1){
		cout<<s<<" "<<s<<endl;
		return;
	}
	string maxi;
	string mini;
	int canMax = -1;
	int canMin = -1;
	for(int i=0;i<s.size()-1;i++){
		int a=(s[i]) - '0';
		int b=(s[i+1]) - '0';
		if(a+b>9) canMax=i;
		else canMin = i;
	}
	if(canMax == -1){
		maxi = s.substr(1,s.size()-1);
		maxi[0] = '0'+(stoii(s[0])+stoii(s[1]));
	}else{
		maxi = s;
		string ans = to_string(stoii(s[canMax])+stoii(s[canMax+1]));
		maxi[canMax] = ans[0];
		maxi[canMax+1] = ans[1];
	}
	
	if(canMin==-1){
		mini = s;
		string ans = to_string(stoii(s[1])+stoii(s[0]));
		mini[0] = ans[0];
		mini[1] = ans[1];
	}else{
		mini = s.substr(0,s.size()-1);
		int d=0;
		for(int i=0;i<s.size()-1;i++){
			if(i == canMin){
				mini[i] = '0'+(stoii(s[canMin])+stoii(s[canMin+1]));
				d=1;
				continue;	
			}
			mini[i]=s[i+d];
		}
	}
	cout<<maxi<<" "<<mini<<endl;
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
