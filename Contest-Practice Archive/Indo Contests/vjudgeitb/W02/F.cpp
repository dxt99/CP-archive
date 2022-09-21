#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

pair<ll,ll> arr[30];
bool zero=0;

void solve(){
	ll n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		ll k=1;
		for(int i=s.size()-1;i>-1;i--){
			ll x=s[i]-'a';
			if(i==0)arr[x].sd=1;
			arr[x].fs+=(k);
			k*=10;
		}
	}
	sort(arr,arr+30);
	reverse(arr,arr+30);
	ll ans=0;
	ll j=1;
	for(int i=0;i<11;i++){
		if(arr[i].sd==0&&zero==0){
			zero=1;
		}else{
			ans+=(arr[i].fs*j);
			j++;
		}
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
