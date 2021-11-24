#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 3, Mod = 1e9 + 7;
 
 
void solve(){
	int n;
	cin>>n;
	bool arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr[n]=1;
	if(arr[0]){
		cout<<n+1<<" ";
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		cout<<endl;
	}else{
		int i=0;
		while(!arr[i+1])cout<<++i<<" ";
		cout<<++i<<" "<<n+1<<" ";
		while(i<n)cout<<++i<<" ";
		cout<<endl;
	}
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
