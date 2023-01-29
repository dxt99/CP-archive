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
ll n, m;

bool check(ll l, ll** arr){
	ll temp[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			temp[i][j]=arr[i][j];
			if(temp[i][j]>l)temp[i][j]=l;
		}
	}
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			if(j+1!=m)temp[i][j]+=temp[i][j+1];
			if(i+1!=n)temp[i][j]+=temp[i+1][j];
			if(i+1!=n && j+1!=m)temp[i][j]-=temp[i+1][j+1];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ll cur = temp[i][j];
			if(i+l<n)cur-=temp[i+l][j];
			if(j+l<m)cur-=temp[i][j+l];
			if(i+l<n && j+l<m)cur+=temp[i+l][j+l];
			if(cur%l==0 && (cur/l) == l*l){
				return 1;
			}
		}
	}
	return 0;
}

ll binser(ll l, ll r, ll** arr){
	if(l>=r)return l;
	ll mid = (l+r)/2;
	if(check(mid, arr))l=mid+1;
	else r=mid;
	return binser(l, r, arr);
}
void solve(){
	cin>>n>>m;
	ll** arr;
	arr = new ll *[n];
	for(int i=0; i<n; i++){
		arr[i] = new ll [m];
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	cout<<binser(1, 1e6, arr)-1<<endl;
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
	return 0;
}
