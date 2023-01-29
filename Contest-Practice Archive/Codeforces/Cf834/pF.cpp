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
	//cout<<"! ";
	ll n, p; cin>>n>>p;
	vl arr(n);
	vl arc(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	for(int i=0; i<n; i++)arc[i]=arr[i];
	sort(arc.begin(), arc.end());
	ll l=0, r=p-1;
	for(int i=0; i<n; i++){
		if(arc[i]==l)l++;
		else if (arc[i]>l) break;
	}
	for(int i=n-1; i>=0; i--){
		if(arc[i]==r)r--;
		else if (arc[i]<r) break;
	}
	//cout<<l<<" "<<r<<" ";
	if(l>r){
		cout<<0<<endl;
		return;
	}
	// case 1: no overflow
	if(l==arr[n-1]+1){
		cout<<r-l+1<<endl;
		return;
	}
	// case 2: overflow
	vl ov(n);
	ov[n-1]=0;
	ll cry=1;
	for(int i=n-2; i>=0; i--){
		ov[i]=arr[i]+cry;
		if(ov[i]>=p){
			cry=1;
			ov[i]%=p;
		}else cry=0;
	}
	if(cry)ov.pb(1);
	ll temp=arr[n-1];
	for(int i=n-1; i>=0; i--){
		if(arc[i]==temp-1)temp--;
	}
	r = min(r,temp-1);
	sort(ov.begin(),ov.end());
	for(auto c: ov){
		if(c==l)l++;
	}
	reverse(ov.begin(),ov.end());
	for(auto c: ov){
		if(c>r)continue;
		if(c==r)r--;
		else break;
	}
	//cout<<r<<" ";
	ll ans=p-arr[n-1];
	if(r>0 && l<=r)ans+=r;
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
