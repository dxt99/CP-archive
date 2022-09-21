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
const int maxN=1e5+3;

vl add(N);
vl arr(N);

void solve(){
	ll n;
	cin>>n;
	ll curr=-1;
	for(int i=0;i<n;i++){
		int j; cin>>j;
		if(j==1){
			ll x; cin>>x;
			arr[curr+1]=x;;
			cout<<x;
			curr++;
		}
		if(j==2){
			ll x,y;
			cin>>x>>y;
			add[x-1]+=y;
			if(x-1==curr){
				arr[curr]+=add[curr];
				if(curr>0)add[curr-1]+=add[curr];
				add[curr]=0;
			}
			cout<<arr[curr];
		}
		if(j==0){
			if(curr>=0)curr--;
			if(curr==-1)cout<<"EMPTY";
			else{
				arr[curr]+=add[curr];
				if(curr>0)add[curr-1]+=add[curr];
				add[curr]=0;
				cout<<arr[curr];
			}
		}
		if(i!=n-1)cout<<" ";
		//cout<<curr<<"-";
	}
	cout<<endl;
	//for(int i=0;i<20;i++)cout<<add[i]<<" ";
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
