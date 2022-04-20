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
typedef pair<string, int> si;

typedef vector<int> v;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
int n;
string start, finish;
unordered_map<string, bool> visit;
unordered_map<string, vector<string>> List;
void BFS()
{
    queue<si> q;
    q.push({start, 1});
    visit[start] = 1;
    while (!q.empty())
    {
        si u = q.front();
        q.pop();
        string str = u.fi;
        if (str == finish)
        {
            cout << u.se << endl;
            return;
        }
        for(int i=0;i<str.size();i++){
            string x=str.substr(0,i)+"*"+str.substr(i+1);
            for(auto r:List[x]){
                if(!visit[r]){
                    visit[r]=1;
                    q.push({r,u.se+1});
                }
            }
        }
    }
}
void init()
{
    visit.clear();
    List.clear();
}
void solution()
{
    cin >> n >> start >> finish;
    unordered_set<string>a;
    for (int i = 0; i < n; i++){
        string x;
        cin>>x;
        a.insert(x);
    }
    for (int i = 0; i < start.size(); i++)
    {
        string str = start.substr(0, i) + "*" + start.substr(i + 1);
        // cout<<str<<endl;
        List[str].push_back(start);
    }
    for (string s : a)
    {
        // cout<<s<<":";
        for (int i = 0; i < s.size(); i++)
        {
            string str = s.substr(0, i) + "*" + s.substr(i + 1);
            // cout<<str<<",";
            List[str].push_back(s);
        }
        // cout<<endl;
    }
    BFS();
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
