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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll tot=0;
 
bool findPartition(vector<ll> arr, int n)
{
    int i, j;
 
 
    if (tot % 2 != 0)
        return false;
 
    bool part[tot / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= tot / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= tot / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
 
    return part[tot / 2][n];
}
 
 

void solve(){
	vector<ll> arr;
	ll n; cin>>n;
	bool saw=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		if(x==2&&!saw){
			saw=1;
			continue;
		}
		arr.pb(x);
		tot+=x;
	}
	if(sum%2==1){
		cout<<"NO"<<endl;
		return;
	}
	sum/=2;
	bool ret=0;
	if(!saw)if(findPartition(arr,arr.size())){
		ret=1;
	};
	if(saw){
		if(findPartition(arr,arr.size())){
			ret=1;
		};
		arr.pb(2);
		tot+=2;
		if(findPartition(arr,arr.size())){
			ret=1;

		}
	}
	if(ret)cout<<"YES\n";
	else cout<<"NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

