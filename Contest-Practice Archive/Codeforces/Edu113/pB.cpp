#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;
char grid[60][60];

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)grid[i][j]='=';
	vi twos;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){ 
		if(s[i]=='2')twos.pb(i);
	}
	if(twos.size()==0){
		printf("YES\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)printf("X");
				else printf("=");
			}
			printf("\n");
		}
		return;
	}
	if(twos.size()<3){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=0;i<twos.size()-1;i++)grid[twos[i]][twos[i+1]]='+',grid[twos[i+1]][twos[i]]='-';
	grid[twos[twos.size()-1]][twos[0]]='+',grid[twos[0]][twos[twos.size()-1]]='-';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)printf("X");
		else printf("%c",grid[i][j]);
		}
		printf("\n");
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
