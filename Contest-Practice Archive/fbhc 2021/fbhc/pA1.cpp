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
		int arr[100];
		memset(arr,0,sizeof(arr));
		char vowel[5]={'A','I','U','E','O'};
		int vows=0;
		for(int i=0;i<s.size();i++){
			for(int j=0;j<5;j++){
				if(s[i]==vowel[j])vows++;
			}
			arr[(int)s[i]-65]++;
		}
		int maxi=0;
		int letnum=1;
		for(int i=0;i<100;i++){
			if(arr[i]>maxi&&i!=0&&i!=4&&i!=8&&i!=14&&i!=20){
				maxi=arr[i];
				letnum=i;
			}
		}
		int posvow[5]={0,4,8,14,20};
		maxi=0;
		int letvow=0;
		for(int i=0;i<5;i++){
			if(arr[posvow[i]]>maxi){
				maxi=arr[posvow[i]];
				letvow=posvow[i];
			}
		}
		//cout<<arr[letvow]<<" "<<vows<<" "<<arr[letnum]<<endl;
		out<<(min(s.size()-2*arr[letvow]+vows,2*s.size()-2*arr[letnum]-vows))<<endl;
	}
	inn.close();
	out.close();
}
