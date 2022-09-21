#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long Mod=1e9+7;
const ll N=1e6+3;

string s;
// Function to find precedence of
// operators.

ll precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*')
    return 2;
    return 0;
}
 
// Function to perform arithmetic operations.
ll applyOp(ll a, ll b, char op){
    switch(op){
        case '+': return (a + b) % Mod;
        case '-': return (a - b + Mod) % Mod;
        case '*': return (a * b) % Mod;
    }
}
 
// Function that returns value of
// expression after evaluation.
ll evaluate(string tokens){
    ll i;
     
    // stack to store lleger values.
    stack <ll> values;
     
    // stack to store operators.
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;
         
        // Current token is an opening
        // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
         
        // Current token is a number, push
        // it to stack for numbers.
        else if(isdigit(tokens[i])){
            ll val = 0;
             
            // There may be more than one
            // digits in number.
            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            values.push(val);
             
            // right now the i polls to
            // the character next to the digit,
            // since the for loop also increases
            // the i, we would skip one
            //  token position; we need to
            // decrease the value of i by 1 to
            // correct the offset.
              i--;
        }
         
        // Closing brace encountered, solve
        // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                ll val2 = values.top();
                values.pop();
                 
                ll val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // pop opening brace.
            if(!ops.empty())
               ops.pop();
        }
         
        // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                ll val2 = values.top();
                values.pop();
                 
                ll val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }
     
    // Entire expression has been parsed at this
    // poll, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        ll val2 = values.top();
        values.pop();
                 
        ll val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    // Top of 'values' contains result, return it.
    long long ret=values.top();
    while(ret<0)ret+=Mod;
    ret%=Mod;
    return ret;
}

// ((expr)+k)+z
//  a       b
bool check(int a, int b){
	if(a>=b)return 0;
	bool st=0;
	bool f=1;
	for(int i=a;i<b&&f;i++){
		if(!st){
			if(isdigit(s[i])){
				while(isdigit(s[i]))i++;
				i--;
				st=1;
			}else if(s[i]=='('){
				//skip this expr, recurse
				int cur=1;
				i++;
				int z=i;
				while(cur!=0&&i<b){
					if(s[i]=='(')cur++;
					if(s[i]==')')cur--;
					i++;
				}
				i--;
				if(cur==0)f=check(z,i);
				else f=0;
				st=1;
			}else{
				f=0;
			}
		}else if(st){
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
				st=0;
			}else{
				f=0;
			}
		}
	}
	if(!st)f=0;
	return f;
}

void solve(){
	cin>>s;
	if(check(0,s.size())){
		cout<<evaluate(s)<<endl;
	}else{
		cout<<"invalid"<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		s="";
		solve();
	}
}

