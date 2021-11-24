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
	int arr[10];
	int sz=0;
	while(n>0){
		arr[sz]=n%10;
		n/=10;
		sz++;
	}
	int ans=1;
	for(int i=0;i<sz;i++){
		ans*=(arr[i]+1);
		//cout<<ans<<"--";
	}
	ans-=2;
	//cout<<ans<<endl;
	int temparr[10];
	for(int i=0;i<sz;i++)temparr[i]=arr[i];
	if(sz>2)for(int j=0;j<(1<<(sz-2));j++){
		//cout<<j<<"--";
		for(int i=0;i<sz;i++)temparr[i]=arr[i];
		int tempans=1;
		int tempj=j;
		int time=sz-1;
		bool cont=1;
		bool zero=0;
		while(tempj>0){
			if(tempj&1){
				if(temparr[time]!=0){
					temparr[time]-=1;
					temparr[time-2]+=10;
					cont=0;
				}else{
					zero=1;
				}
			}
			tempj/=2;
			time--;
		}
		if(cont)continue;
		if(zero)continue;
		for(int i=0;i<sz;i++){
			if(temparr[i]<10)tempans*=(temparr[i]+1);
			else tempans*=(19-temparr[i]);
		}
		//cout<<tempans<<"\\";
		ans+=tempans;
	}
	cout<<ans<<endl;
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
