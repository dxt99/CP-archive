#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int n;
	cin>>n;
	int even=0;
	int odd=0;
	int idxe=0;
	int idxo=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x%2){
			odd++;
			idxo=i+1;
		}else{
			even++;
			idxe=i+1;
		}
	}
	if(even>1)cout<<idxo<<endl;
	else cout<<idxe<<endl;
}
