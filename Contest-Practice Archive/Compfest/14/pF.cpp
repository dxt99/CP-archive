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
const ll negInf = -1 * 1e12;

void solve(){
	ll n; cin>>n;
	vll arr(n); // l, r
	for(int i=0; i<n ;i++){
		ll l, r;
		cin>>l>>r;
		arr[i].fs=l;
		arr[i].sd=r;
	}
	vl ans; // lsb to msb
	ans.pb(n);
	ll lsb = 2;
	while(lsb<Mod){
		//cout<<"Add lsb"<<endl;
		ll tempAns=0;
		vll tempArr;
		for(auto p: arr){
			if(p.sd-p.fs+1>=lsb){
				tempAns++;
			}else{
				ll tempL = p.fs%lsb;
				ll tempR = p.sd%lsb;
				if(tempL > tempR){
					tempArr.pb(mp(tempL, lsb-1));
					tempArr.pb(mp(0,tempR));
				}else{
					tempArr.pb(mp(tempL,tempR));
				}
			}
		}
		sort(tempArr.begin(), tempArr.end());
		ll maxi = 0;
		for(int i=0; i<tempArr.size(); i++){
			ll tempR = tempArr[i].sd;
			ll dist = lower_bound(tempArr.begin(), tempArr.end(), mp(tempR+1, negInf))-tempArr.begin();
			maxi = max(maxi, dist-i);
		}
		//cout<<maxi<<" "<<tempAns<<endl;
		ans.pb(maxi+tempAns);
		lsb*=2;
	}
	
	ll q; cin>>q;
	for(int i=0; i<q; i++){
		ll w; cin>>w;
		lsb = w&(-w);
		ll cnt =0;
		while(lsb>1){
			lsb>>=1;
			cnt++;
		}
		//cout<<"ANSWER: ";
		cout<<ans[cnt]<<endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
