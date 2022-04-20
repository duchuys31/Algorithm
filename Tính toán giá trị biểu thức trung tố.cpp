#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int solve(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    return a / b;
}
int check(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    return 2;
}
int answer(string s)
{
    stack<int> st;
    int i=0;
    while(i<s.size()){
        int d=0;
        bool ok=0;
        while(isalnum(s[i])){
            ok=1;
            d=d*10+(s[i]-'0');
            i++;
        }
        if(ok)st.push(d);
        if(s[i]==' ')i++;
        if(s[i]=='+'||s[i]=='*'||s[i]=='-'||s[i]=='/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = solve(b, a, s[i]);
            st.push(ans);
            i++;
        }
    }
    return st.top();
}
string convert(string s)
{
    string res = "";
    stack<char> st;
    int i = 0;
    while (i < s.size())
    {
        char c = s[i];
        if (isalnum(c))
            res += c;
        else
        {
            res += ' ';
            if (c == '(')
                st.push(c);
            else
            {
                if (c == ')')
                {
                    while (st.top() != '(')
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    while (!st.empty() && check(st.top()) >= check(c))
                    {
                        res += st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        i++;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
/*Main*/
void init() {}
void solution()
{
    string s;
    cin >> s;
    s = convert(s);
    cout << answer(s) << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
