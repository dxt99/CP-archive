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
	bool ans=0;
	while(n>0){
		if(n%10==0)ans=1;
		n/=10;
	}
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
