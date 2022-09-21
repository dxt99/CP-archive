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
	cout<<"? 1 "<< n<<endl;
	vl arr(n);
	int sum;
	cin>>sum;
	cout<<"? 2 "<<n<<endl;
	int temp;
	cin>>temp;
	arr[0]=sum-temp;
	for(int i=n-1; i>1; i--){
		cout<<"? 1 "<<i<<endl;
		cin>>temp;
		arr[i]=sum-temp;
		sum=temp;
	}
	arr[1] = temp - arr[0];
	cout<<"!";
	for(int i=0; i<n; i++){
		cout<<" ";
		cout<<arr[i];
	}
	cout<<endl;
	
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
