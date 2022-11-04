#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int>pii;
typedef priority_queue <ll, vector<ll>, greater<ll>> pqmin;

#define PB(v,a) v.push_back(a)
#define MP(a, b) make_pair(a,b)
#define ALL(s) (s).begin(), (s).end()
#define sz(s) ll(s.size())

/* Some template function */ 
ll gcd(ll a, ll b){ if(b > a){ return gcd(b, a);} if(b == 0){ return a;} return gcd(b, a % b); }
void swap(ll &a, ll &b){ll temp = a; a = b; b = temp;}

/* Some most used constanta */
const ll MOD = 1e9+7;
const double EPS = 1e-9;
const lld PI =  3.141592653589793238462;
const int MXN = 2e5;

// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

void printAns(string s){
	int i=0;
	while(s[i]=='0')i++;
	for(;i<s.size();i++)cout<<s[i];
	cout<<endl;
}

/* ----------------------END HEADER --------------------------------*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    
    ll sz = s.size();
    int i=sz-1;
    while(s[i]==s[sz-1])i--;
    if(i==0){
    	string temp = s;
    	swap(temp[0],temp[1]);
    	printAns(findDiff(temp, s));
	}else{
		string temp = s;
		swap(temp[i],temp[i+1]);
		string ans = findDiff(temp, s);
		temp = s;
		swap(temp[i], temp[i-1]);
		if(temp!=s)ans = min(ans, findDiff(temp, s));
		temp = s;
		swap(temp[i], temp[i-1]);
		swap(temp[i],temp[i+1]);
		if(temp!=s)ans = min(ans, findDiff(temp, s));
		temp = s;
		swap(temp[i], temp[sz-1]);
		if(temp!=s)ans = min(ans, findDiff(temp, s));
		temp = s;
		swap(temp[i], temp[i-1]);
		swap(temp[i], temp[sz-1]);
		if(temp!=s)ans = min(ans, findDiff(temp, s));
		printAns(ans);
	}
}
