#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int ans=0;
	for(int i=1;i<n-1;i++)if((!arr[i])&&arr[i-1]&&arr[i+1]){
		ans++;
		arr[i+1]=0;
	}
	cout<<ans<<endl;
}
