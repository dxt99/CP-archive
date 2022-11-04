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
typedef vector< pair<ll,ll> > vll;
typedef vector< pair<ll,pl> > vlll;
typedef priority_queue <ll, vector<ll>, greater<ll> > minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;
bool turnF = false;        
string arr[3][3];

string print_dancer() {
    bool Flag = turnF;
    if (Flag) {
        if (arr[0][0] == "(") {
            if (arr[0][2] == " ") {
                arr[0][0] = " ";
                arr[0][2] = ")";
            }
        
        } else if (arr[0][0] == " ") {
            if (arr[0][2] == ")") {
                arr[0][0] = "(";
                arr[0][2] = " ";
            }
        }
        
        for(int i = 1; i < 3; i++) {
            if (arr[i][0] == "/") {
                if (arr[i][2] == ">") {
                    arr[i][0] = "<";
                    arr[i][2] = "\\";
                } 
                
                if (arr[i][2] == " ") {
                    arr[i][0] = " ";
                    arr[i][2] = "\\";
                }
                    
            } else if (arr[i][0] == "<") {
                if (arr[i][2] == "\\") {
                    arr[i][0] = "/";
                    arr[i][2] = ">";
                }
                if (arr[i][2] == " ") {
                    arr[i][0] = " ";
                    arr[i][2] = ">";
                }
            } else if (arr[i][0] == " ") {
                if (arr[i][2] == "\\") {
                    arr[i][2] = " ";
                    arr[i][0] = "/";
                }

                if (arr[i][2] == ">") {
                    arr[i][2] = " ";
                    arr[i][0] = "<";
                }
            }
        }
    }

    string ret = "";
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret += arr[i][j];
        }
        ret += "\n";
    }
    
    if (Flag) {
        if (arr[0][0] == "(") {
            if (arr[0][2] == " ") {
                arr[0][0] = " ";
                arr[0][2] = ")";
            }
        
        } else if (arr[0][0] == " ") {
            if (arr[0][2] == ")") {
                arr[0][0] = "(";
                arr[0][2] = " ";
            }
        }
        
        for(int i = 1; i < 3; i++) {
            if (arr[i][0] == "/") {
                if (arr[i][2] == ">") {
                    arr[i][0] = "<";
                    arr[i][2] = "\\";
                } 
                
                if (arr[i][2] == " ") {
                    arr[i][0] = " ";
                    arr[i][2] = "\\";
                }
                    
            } else if (arr[i][0] == "<") {
                if (arr[i][2] == "\\") {
                    arr[i][0] = "/";
                    arr[i][2] = ">";
                }
                if (arr[i][2] == " ") {
                    arr[i][0] = " ";
                    arr[i][2] = ">";
                }
            } else if (arr[i][0] == " ") {
                if (arr[i][2] == "\\") {
                    arr[i][2] = " ";
                    arr[i][0] = "/";
                }

                if (arr[i][2] == ">") {
                    arr[i][2] = " ";
                    arr[i][0] = "<";
                }
            }
        }
    }
    return ret.substr(0, ret.length()-1);
}


void dancer(string txt) {
    if (txt.substr(0,3) == "say") {
        cout << txt.substr(4, txt.length()-1) << endl;
        return;
    }

    if (txt == "left hand to head") {
        arr[0][2] = ")";
        arr[1][2] = " ";
        cout << print_dancer() << endl;
    }

    if (txt == "left hand to hip"){
        arr[0][2] = " ";
        arr[1][2] = ">";
        cout << print_dancer() << endl;
    }

    if (txt == "left hand to start")  {
        arr[0][2] = " ";
        arr[1][2] = "\\";
        cout << print_dancer() << endl;
    }

    if (txt == "left leg in") {
        arr[2][2] = ">";
        cout << print_dancer() << endl;
    }

    if (txt == "left leg out") {
        arr[2][2] = "\\";
        cout << print_dancer() << endl;
    }

    if (txt == "right hand to head") {
        arr[0][0] = "(";
        arr[1][0] = " ";
        cout << print_dancer() << endl;
    }

    if (txt == "right hand to hip") {
        arr[0][0] = " ";
        arr[1][0] = "<";
        cout << print_dancer() << endl;
    }

    if (txt == "right hand to start") {
        arr[0][0] = " ";
        arr[1][0] = "/";
        cout << print_dancer() << endl;
    }

    if (txt == "right leg in") {
        arr[2][0] = "<";
        cout << print_dancer() << endl;
    }

    if (txt == "right leg out") {
        arr[2][0] = "/";
        cout << print_dancer() << endl;
    }

    if (txt == "turn"){
        turnF ^=1;
        cout << print_dancer() << endl;

    }
}

int main() {
    int k; cin >> k;
    int n; cin >> n;
    string tmp;
	getline(cin, tmp);
    for(int i = 0;i < k; i++) {
        arr[0][0] = " ";
        arr[0][1] = "o";
        arr[0][2] = " ";
        arr[1][0] = "/";
        arr[1][1] = "|";
        arr[1][2] = "\\";
        arr[2][0] = "/";
        arr[2][1] = " ";
        arr[2][2] = "\\";
        
        turnF = 0;
        for(int j = 0;j < n; j++) {
            string tx; getline(cin, tx);
            dancer(tx);
        }
    }
}

