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
const int maxN=3e5+3;
 
int arr[maxN];
set<ll> nums;
 
void solve(){
	nums.insert(0);
	int n; cin>>n;
	int sum=0;
	int cnt2=0;
	int maxi=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		if(arr[i]==2)cnt2++;
		if(arr[i]!=2||cnt2>1){
			vl temp;
			for(auto it:nums){
				if(it+arr[i]<=125000)temp.pb(it+arr[i]);
			}
			for(auto k:temp)nums.insert(k);
			maxi=max(maxi,2);
		}
	}
	if(sum%2){
		cout<<"NO"<<endl;
		return;
	}
	sum/=2;
	if(maxi>sum){
		cout<<"NO"<<endl;
		return;
	}
	for(int i=0;i<=min(cnt2,1);i++){
		for(int j=0;j<=min(cnt2,1)-i;j++)if(nums.find(sum-2*j-i)!=nums.end()){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
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
