#include<bits/stdc++.h>
using namespace std;

const int N=1e6+3;

int mini=1;

int main(){
	int n; cin>>n;
	int ans=1;
	n-=2;
	int a;
	cin>>a;
	while(n--){
		cin>>a;
		if(a==0){
			mini=2;
			ans++;
		}else{
			ans=1;
		}
	}
	if(ans<mini)ans=mini;
	cout<<ans<<endl;
}
