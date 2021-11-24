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
	string s; cin>>s;
	int cnt1=0;
	for(int i=0;i<n;i++)if(s[i]=='1')cnt1++;
	int l=0;
	int r=n-1;
	int ans=0;
	vl idx;
	while(r>=n-cnt1){
		while(r>=n-cnt1&&s[r]=='1')r--;
		while(l<n&&s[l]=='0')l++;
		if(r<0||l>n-1)break;
		if(l>=r||s[r]!='0'||s[l]!='1')break;
		ans+=2;
		idx.pb(l);
		idx.pb(r);
		r--;
		l++;
	}
	if(ans==0)cout<<0<<endl;
	else{
		sort(idx.begin(),idx.end());
		cout<<1<<endl;
		cout<<ans<<" ";
		for(auto i:idx)cout<<i+1<<" ";
		cout<<endl;
	}
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

