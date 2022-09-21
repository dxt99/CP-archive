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

const int N = 2e5 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n; cin>>n;
	vl rm(2*n);
	for(int i=0; i<2*n; i++)rm[i]=0;
	string s; cin>>s;
	ll cnt=0;
	ll ans =n;
	for(int i=0; i<2*n; i++){
		if(s[i]=='('){
			rm[cnt]++;
			cnt++;
		}
		else{
			cnt--;
			if(rm[cnt]>1){
				ans--;
				rm[cnt]=1;
			}
			rm[cnt+1]=0;
		}
	}
	cout<<ans<<endl;
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
