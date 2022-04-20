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

const ll oo = 100;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
int n, m;
int a[N];
struct dl
{
    int sum, dp[3];
};
struct nodeIT
{
    dl A;
    nodeIT()
    {
        this->A.sum = 0;
        for (int i = 0; i < 3; i++)
            this->A.dp[i] = 0;
    }
    void set(int val)
    {
        A.sum = val;
        A.dp[val % 3]++;
    }
    void change(int val)
    {
        A.dp[A.sum % 3] = 0;
        A.sum = val;
        A.dp[val % 3]++;
    }
    void merge(nodeIT left, nodeIT right)
    {
        A.sum = left.A.sum + right.A.sum;

        int x = (0 + left.A.sum) % 3;
        A.dp[x] = right.A.dp[0] + left.A.dp[x];

        int y = (1 + left.A.sum) % 3;
        A.dp[y] = right.A.dp[1] + left.A.dp[y];

        int z = (2 + left.A.sum) % 3;
        A.dp[z] = right.A.dp[2] + left.A.dp[z];
    }
} Tree[4 * N];
void build(int node, int l, int r)
{
    if (l == r)
    {
        Tree[node].set(a[l]);
        return;
    }
    else
    {
        build(2 * node, l, (l + r) / 2);
        build(2 * node + 1, (l + r) / 2 + 1, r);
        Tree[node].merge(Tree[2 * node], Tree[2 * node + 1]);
    }
}
void update(int node, int l, int r, int id, int val)
{
    if (r < id || l > id)
        return;
    if (l == r)
    {
        Tree[node].change(val);
        return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, id, val);
    update(node * 2 + 1, m + 1, r, id, val);
    Tree[node].merge(Tree[2 * node], Tree[2 * node + 1]);
}
nodeIT get(int node, int l, int r, int left, int right)
{
    nodeIT ans = nodeIT();
    if (r < left || l > right)
        return ans;
    if (l >= left && r <= right)
    {
        return Tree[node];
    }
    int m = (l + r) / 2;
    nodeIT L = get(node * 2, l, m, left, right);
    nodeIT R = get(node * 2 + 1, m + 1, r, left, right);
    ans.merge(L, R);
    return ans;
}
void solve(int l, int r)
{
    nodeIT node = get(1, 1, n, l, r);
    // cout << "sum:" << node.A.sum << endl;
    int F[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        F[i] = node.A.dp[i];
        if (i == 0)
            F[i]++;
        F[i] = F[i] * (F[i] - 1) / 2;
    }
    // cout << endl;
    cout << F[0] + F[1] + F[2] << endl;
}
void init()
{
}
void solution()
{
    string s;
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            update(1, 1, n, x, y);
        }
        else
        {
            solve(x, y);
        }
    }
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
