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
	
	ifstream inn;
	string filename;
	cin>>filename;
	inn.open(filename);
	int t;
	inn>>t;
	ofstream out;
	out.open("out.txt");
	for(int time=0;time<t;time++){
		out<<"Case #"<<time+1<<": ";
			string s;
		inn>>s;
		int edges;
		inn>>edges;
		int dp[100][100];
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++)dp[i][j]=INT_MAX;
		}
		for(int i=0;i<edges;i++){
			string temp;
			inn>>temp;
			dp[(int)temp[0]-65][(int)temp[1]-65]=1; //w=1
		}
		//nodes
		for(int i=0;i<100;i++)dp[i][i]=0;
		//floyd
		for(int i=0;i<30;i++){
			for(int j=0;j<30;j++){
				for(int k=0;k<30;k++){
					if(dp[j][i]!=INT_MAX&&dp[i][k]!=INT_MAX)dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				}
			}
		}
		//finding the minimum
		int arr[100];
		memset(arr,0,sizeof(arr));
		int ans=INT_MAX;
		for(int i=0;i<26;i++){
			int tar=i;
			int total=0;
			for(int j=0;j<s.size();j++){
				int from=(int)s[j]-65;
				if(dp[from][tar]==INT_MAX){
					total=-1;
					break;
				}
				total+=dp[from][tar];
			}
			if(total!=-1)ans=min(ans,total);
		}
		if(ans==INT_MAX)out<<-1<<endl;
		else out<<ans<<endl;
	}
	inn.close();
	out.close();
}
