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
	
	//filing
	ifstream inn;
	string filename;
	cin>>filename;
	inn.open(filename);
	int t;
	inn>>t;
	ofstream out;
	out.open("out.txt");
	
	for(int time=0;time<t;time++){
		int n;
		inn>>n;
		string s;
		inn>>s;
		ll i=0;
		ll ans=0;
		ll prev=0;
		ll bign=0;
		ll cur=0;
		char bef='x';
		for(int i=0;i<n;i++){
			if(s[i]=='.')bign*=2;
			else bign++;
			bign=bign%Mod;
		}
		while((s[i]=='F'||s[i]=='.')&&i<n){
			i++;
			if(s[i]!='.')cur++;
			else cur*=2;
		};
		prev=i;
		bef=s[prev];
		ll fs,sd;
		fs=i;
		sd=-1;
		//char tst=s[fs]^'O'^'X';
		//cout<<tst<<endl;
		//cout<<bign<<endl;
		for(;i<n;i++){
			if(s[i]=='.'){
				ans*=2;
				ans=ans%Mod;
				if(bign<cur+fs)bign+=Mod;
				ans+=((sd+1)*(bign-cur-fs));
				//cout<<cur<<endl;
				ans=ans%Mod;
				if(sd!=-1)sd+=cur;
				bign=bign%Mod;
				prev+=cur;
			}else if(s[i]!='F'&&s[i]!=bef){
				if(bign<i)bign+=Mod;
				ans+=((prev+1)*(bign-cur));
				prev=cur;
				bef=s[i];
				ans=ans%Mod;
				bign=bign%Mod;
			}else if(s[i]!='F'){
				prev=cur;
				bef=s[i];
			}
			if(s[i]!='.')cur++;
			else cur*=2;
			if(s[i]==char(s[fs]^('O'^'X')))sd=cur-1;
			cout<<ans<<endl;
		}
		out<<"Case #"<<time+1<<": ";
		out<<ans<<endl;
		cout<<endl;
	}
	inn.close();
	out.close();
}
