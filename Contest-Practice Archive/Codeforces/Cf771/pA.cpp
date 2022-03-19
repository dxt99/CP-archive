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
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int i=0;
	while(arr[i]==i+1)i++;
	int f=i+1;
	if(f==n+1){
		for(int i=0;i<n;i++)cout<<arr[i]<<' ';
		cout<<endl;
		return;
	}
	int j=0;
	for(j=0;j<n;j++)if(arr[j]==f)break;
	reverse(arr+i,arr+j+1);
	for(int i=0;i<n;i++)cout<<arr[i]<<' ';
	cout<<endl;
	return;
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
