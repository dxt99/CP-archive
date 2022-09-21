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
	
	int n;
	cin>>n;
	int arr[n],pre[n],suf[n];
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	for(int i=0;i<n;i++)cin>>arr[i];
	if(!arr[0])pre[0]++;
	for(int i=1;i<n;i++)if(!arr[i])pre[i]=pre[i-1]+1;else pre[i]=pre[i-1];
	if(arr[n-1])suf[n-1]++;
	for(int i=n-2;i>=0;i--)if(arr[i])suf[i]=suf[i+1]+1;else suf[i]=suf[i+1];
	int ans=0;
	for(int i=0;i<n-1;i++)ans=max(ans,pre[i]+suf[i+1]);
	ans=max(ans,suf[0]);
	ans=max(ans,pre[n-1]);
	cout<<ans<<endl;
}
