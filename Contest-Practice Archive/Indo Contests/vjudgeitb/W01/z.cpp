#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	/*
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
	*/
	
	int n;
	cin>>n;
	ll arr[n];
	ll temparr[n];
	int maxi=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		temparr[i]=arr[i];
		sum+=arr[i];
	}
	sort(temparr,temparr+n);
	vi ans;
	for(int i=0;i<n;i++)if(arr[i]!=temparr[n-1]&&sum-arr[i]==2*temparr[n-1])ans.pb(i+1);
	for(int i=0;i<n;i++)if(arr[i]==temparr[n-1]&&sum-arr[i]==2*temparr[n-2])ans.pb(i+1);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
}
