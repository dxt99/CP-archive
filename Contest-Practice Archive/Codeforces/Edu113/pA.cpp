#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	char arr[n];
	bool no=1;
	cin>>arr[0];
	for(int i=1;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=arr[i-1]&&no){
			printf("%d %d\n",i,i+1);
			no=0;
		}
	}
	if(no)printf("-1 -1\n");
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
