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

const int N = 1e6 + 3, Mod = 998244353;
const int maxN=1e3+3;

ll arr[N];

//Binary Search
ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%d",mid);
	if(arr[mid]==val)return mid;
	if(arr[mid]>val&&arr[mid-1]<val)return mid;
	if(arr[mid]>val) return binser(l,mid-1, val);
	if(arr[mid]<val) return binser(mid+1,r, val);
}

void solve(){
	int n,s; cin>>n>>s;
	ll ans = 1;
	int cntNeg = 0; // number of -1 spots
	int used = 0; // number of used -1 spots, default to lowest
	int a[n+1], b[n+1];
	map<int, int> ma;
	map<int, int> mb;
	for(int i=1; i<=n; i++)mb[i]=-1;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		ma[a[i]]=i;
	}
	for (int i=1; i<=n; i++){
		cin>>b[i];
		mb[b[i]]=i;
		if (b[i]==-1)arr[++cntNeg] = a[i];
	}
	sort(arr+1, arr+cntNeg+1);
	//for (int i=1; i<=cntNeg; i++)cout<<arr[i]<<" ";
//	cout<<cntNeg<<endl;
	for (ll i=1; i<=n; i++){
		// if mapped
		if(mb[i] != -1){
			if(ma[i]==mb[i])continue;
			int curAtPos = a[mb[i]];
			// if cant swap, cry
			if (curAtPos - i > s){
				cout<<0<<endl;
				return;
			}
			// else do the swap
			swap(a[mb[i]], a[ma[i]]);
			ma[curAtPos]=ma[i];
			ma[i]=mb[i];
		}else{
			if (used == cntNeg){ //should never happen??
				cout<<0<<endl;
				return;
			}
			// count possible jumps
			int r = binser(1, cntNeg, i+s);
			// overestimate
			if (i+s<arr[r])r--;
			r -= used;
			//cout<<r+used<<" "<<arr[r+used]<<" ";
			//cout<<i<<" "<<r<<endl;
			// check if swap is neccessary
			if(b[ma[i]] != -1){
				if (r==0) {
					// should never happen too
					cout<<0<<endl;
					return;
				}
				// and do the swap
				int tar = arr[used+1];
				swap (a[ma[i]], a[ma[tar]]);
				int temp = ma[tar];
				ma[tar] = ma[i];
				ma[i] = temp;
			}
			if (r==0) {
				continue;
			}
			ans *= r;
			ans %= Mod;
			used++;
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
