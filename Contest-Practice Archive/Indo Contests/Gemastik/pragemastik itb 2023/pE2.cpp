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
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

int n, m;
char arr[100][100];
int cnt[100][100];

struct pt{
	int i, j;
};

int count(pt p){
	int i = p.i;
	int j = p.j;
	int tmp = 0;
	if (arr[i-1][j]=='.')tmp++;
	if (arr[i+1][j]=='.')tmp++;
	if (arr[i][j+1]=='.')tmp++;
	if (arr[i][j-1]=='.')tmp++;
	return tmp;
}

pt findMin(){
	int iF=-1;
	int jF=-1;
	int cur = maxN;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if (arr[i][j]=='.' && cnt[i][j]<cur){
				iF = i;
				jF = j;
				cur = cnt[i][j];
			}
		}
	}
	return {iF, jF};
}

pt findMinAdj(pt p){
	int i = p.i;
	int j = p.j;
	int cur = maxN;
	int iF = -1;
	int jF = -1;
	
	if (cnt[i+1][j]<cur && arr[i+1][j] == '.'){
		iF = i+1;
		jF = j;
		cur = cnt[i+1][j];
	}
	if (cnt[i-1][j]<cur && arr[i-1][j] == '.'){
		iF = i-1;
		jF = j;
		cur = cnt[i-1][j];
	}
	if (cnt[i][j+1]<cur && arr[i][j+1] == '.'){
		iF = i;
		jF = j+1;
		cur = cnt[i][j+1];
	}
	if (cnt[i][j-1]<cur && arr[i][j-1] == '.'){
		iF = i;
		jF = j-1;
		cur = cnt[i][j-1];
	}
	return {iF, jF};
}

void updateAdj(pt plant){
	int i = plant.i;
	int j = plant.j;
	if (arr[i-1][j] == '.'){
		cnt[i-1][j]-=1;
	}
	if (arr[i+1][j] == '.'){
		cnt[i+1][j]-=1;
	}
	if (arr[i][j+1] == '.'){
		cnt[i][j+1]-=1;
	}
	if (arr[i][j-1] == '.'){
		cnt[i][j-1]-=1;
	}
}

bool shouldPlant(pt plant){
	int i = plant.i;
	int j = plant.j;
	int ones = 0;
	if (arr[i-1][j] == '.' && cnt[i-1][j]==1){
		ones++;
	}
	if (arr[i+1][j] == '.' && cnt[i+1][j]==1){
		ones++;
	}
	if (arr[i][j+1] == '.' && cnt[i][j+1]==1){
		ones++;
	}
	if (arr[i][j-1] == '.' && cnt[i][j-1]==1){
		ones++;
	}
	return ones<1;
}

void colorAdj(pt water){
	int i = water.i;
	int j = water.j;
	arr[i][j]='O';
	if (arr[i-1][j] == '.'){
		if (shouldPlant({i-1, j})){
			arr[i-1][j] = 'X';
			updateAdj({i-1, j});
		}else{
			colorAdj({i-1, j});	
		}
	}
	if (arr[i+1][j] == '.'){
		if (shouldPlant({i+1, j})){
			arr[i+1][j] = 'X';
			updateAdj({i+1, j});
		}else{
			colorAdj({i+1, j});
		}
	}
	if (arr[i][j+1] == '.'){
		if (shouldPlant({i, j+1})){
			arr[i][j+1] = 'X';
			updateAdj({i, j+1});
		}else{
			colorAdj({i, j+1});
		}
	}
	if (arr[i][j-1] == '.'){
		if (shouldPlant({i, j-1})){
			arr[i][j-1] = 'X';
			updateAdj({i, j-1});
		}else{
			colorAdj({i, j-1});
		}
	}
}
void solve(){
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++)arr[i][j]='#';
	}
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=1; j<=m; j++){
			char x = s[j-1];
			arr[i][j]=x;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cnt[i][j]=count({i, j});
		}
	}
	
	pt smol = findMin();
	while(smol.i != -1){
		pt water = findMinAdj(smol);
		//cout<<water.i<<water.j<<endl;
		//cout<<smol.i<<smol.j<<endl;
		if (water.i == -1){
			arr[smol.i][smol.j]='O';
			smol = findMin();
			continue;
		}else{
			colorAdj(water);
		}
		
		smol = findMin();
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
