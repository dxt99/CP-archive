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
 
ll tt,slen;
string ss;
 
int main(){
    tt=1;
    for (int ww = 1; ww <= tt; ww++)
    {
        cin >> ss;
        slen = ss.size();
        int anss = -1;
        anss = 0;
        for (int ii = 0; ii < 10; ii++)
        {
            for (int jf = 0; jf < 10; jf++)
            {
                int le = 0, q = 0;
                bool flag = false;
                for (int k = 0; k < slen; k++)
                {
                    if (!flag && ss[k] - '0' == ii) ++le, flag = 1;
                    else if (flag && ss[k] - '0' == jf) ++le, flag = 0;
                }
                if (flag && le > 2 && ii != jf) le -= 1;
                anss = max(le, anss);
            }
        }
        cout << slen - anss << endl;
    }
}
  
