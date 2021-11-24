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
const int maxN=2e5+3;

string s,tar;
ll arr[maxN];

bool count(ll mid){
	ll idx=0;
	string temp=s;
	for(int i=0;i<mid;i++)temp[arr[i]]='.';
	for(int i=0;i<s.size();i++){
		if(tar[idx]==temp[i])idx++;
		if(idx==tar.size())return 1;
	}
	return 0;
}

ll binser(ll l,ll r){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	bool val=count(mid);
	if(!val) return binser(l,mid-1);
	else return binser(mid+1,r);
}

void solve(){
	cin>>s; cin>>tar;
	for(int i=0;i<s.size();i++){
		cin>>arr[i];
		arr[i]--;
	}
	ll ans=binser(0,s.size()-1);
	if(!count(ans))ans--;
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
