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
	int arr[n+1];
	for(int i=1;i<=n;i++)cin>>arr[i];
	int key[n+1];
	for(int i=0;i<n;i++){
		cin>>key[i+1];
	}
	for(int i=1;i<=n;i++)cout<<arr[key[i]]<<" ";
	cout<<endl;
}
int main(){
	while(true)solve();
}
