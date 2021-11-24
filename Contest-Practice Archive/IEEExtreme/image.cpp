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
const int maxN=35;

ll p,q,n,m;
ll r,o;
char arr1[maxN][maxN];
char arr2[maxN][maxN];

ll check(){
	ll ret=0;
	for(int i=0;i<o;i++){
		for(int j=0;j<o;j++){
			ll temp=0;
			for(int k=0;k+i<o&&k<r;k++){
				for(int l=0;l+j<o&&l<r;l++){
					if(arr1[k][l]=='#'&&arr2[i+k][j+l]=='#')temp++;
				}
			}
			ret=max(ret,temp);
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){
			ll temp=0;
			for(int k=0;k+i<r&&k<o;k++){
				for(int l=0;l+j<r&&l<o;l++){
					if(arr2[k][l]=='#'&&arr1[i+k][j+l]=='#')temp++;
				}
			}
			ret=max(ret,temp);
		}
	}
	//cout<<ret<<",..";
	return ret;
}

void rotate(ll N)
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++) {
            // Store current cell in
            // temp variable
            char temp = arr1[x][y];
 
            // Move values from right to top
            arr1[x][y] = arr1[y][N - 1 - x];
 
            // Move values from bottom to right
            arr1[y][N - 1 - x]
                = arr1[N - 1 - x][N - 1 - y];
 
            // Move values from left to bottom
            arr1[N - 1 - x][N - 1 - y]
                = arr1[N - 1 - y][x];
 
            // Assign temp to left
            arr1[N - 1 - y][x] = temp;
        }
    }
}

void mirror(ll n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap(arr1[i][j],arr1[i][n-1-j]);
		}
	}
}

void solve(){
	cin>>p>>q;
	r=max(p,q);
	 //just make it square
	for(int i=0;i<r;i++)for(int j=0;j<r;j++)arr1[i][j]='.';
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++)cin>>arr1[i][j];
	}
	cin>>n>>m;
	o=max(n,m);
	for(int i=0;i<o;i++)for(int j=0;j<o;j++)arr2[i][j]='.';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>arr2[i][j];
	}
	ll ans=0;
	for(int i=0;i<4;i++){
		ans=max(ans,check());
		rotate(r);
	}
	mirror(r);
	for(int i=0;i<4;i++){
		ans=max(ans,check());
		rotate(r);
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

