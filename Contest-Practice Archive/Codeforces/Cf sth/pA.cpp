#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 3, Mod = 1e9 + 7;
 
void solve(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<n;i++){
		int z;
		cin>>z;
		k=k&z;
	}
	cout<<k<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
