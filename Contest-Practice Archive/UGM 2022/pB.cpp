#include <bits/stdc++.h>
using namespace std;

int solve(int h[105], int n)
{
    int x[1005], res = 0;
    for (int i = 1; i <= 1000; i++)
    {
        x[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        x[h[i]]++;
        if (x[h[i] + 1] > 0)
            x[h[i] + 1]--;
    }
    for (int i = 1; i <= 1000; i++)
    {
        res += x[i];
    }
    return res;
}

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

int main()
{
    int arr[105];
    int T;
    string H;
    cin >> T;
    getline (cin, H);
    for (int i = 0; i < T; i++)
    {
        getline (cin, H);
        vector<string> v = split(H, ' ');
        for (int j =0 ;j<v.size();j++){
            stringstream s(v[j]);
            s >> arr[j];
        }
        cout << solve(arr, v.size()) << endl;
    }
}
