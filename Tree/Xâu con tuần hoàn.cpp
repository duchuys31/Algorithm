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
// #define ll long long
// #define db double
// #define fi first
// #define se second

// typedef pair<int, int> ii;
// typedef vector<int> v;

// const ll oo = 1e13;
const int mod = 1e9 + 3;
const int N = 1e5 + 5;

// int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
// int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
struct nodeIT
{
    int length;
    int hashval;
};
int n, m;
int a[N];
nodeIT Tree[4 * N];
int Lazy[4 * N], sum[N];
int Pow[N];

nodeIT merge(nodeIT A, nodeIT B)
{
    nodeIT ans;
    ans.length = A.length + B.length;
    ans.hashval = (A.hashval * Pow[B.length] + B.hashval) % mod;
    return ans;
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        Tree[node].hashval = a[l];
        Tree[node].length = 1;
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * node, l, (l + r) / 2);
        build(2 * node + 1, (l + r) / 2 + 1, r);

        Tree[node] = merge(Tree[node * 2], Tree[node * 2 + 1]);
    }
}

void update(int node, int l, int r, int left, int right, int val)
{
    if (Lazy[node] != -1)
    {
        Tree[node].hashval = sum[Tree[node].length] * Lazy[node];

        if (l != r)
        {
            Lazy[node * 2] = Lazy[node];
            Lazy[node * 2 + 1] = Lazy[node];
        }
        Lazy[node] = -1;
    }
    if (r < left || l > right)
        return;
    if (left <= l && r <= right)
    {
        Tree[node].hashval = sum[Tree[node].length] * val;

        if (l != r)
        {
            Lazy[node * 2] = val;
            Lazy[node * 2 + 1] = val;
        }
        return;
    }
    update(node * 2, l, (l + r) / 2, left, right, val);
    update(node * 2 + 1, (l + r) / 2 + 1, r, left, right, val);
    // cout << Tree[2 * node] << " " << Tree[2 * node + 1] << endl;
    Tree[node] = merge(Tree[node * 2], Tree[node * 2 + 1]);
}

nodeIT get(int node, int l, int r, int left, int right)
{
    int m = (l + r) / 2;
    if (l > right || r < left)
        return {0,0};
    if (Lazy[node] != -1)
    {
        Tree[node].hashval = sum[Tree[node].length] * Lazy[node];
        if (l != r)
        {
            Lazy[node * 2] = Lazy[node];
            Lazy[node * 2 + 1] = Lazy[node];
        }
        Lazy[node] = -1;
    }
    if (l >= left && r <= right)
        return Tree[node];
    nodeIT a = get(node * 2, l, (l + r) / 2, left, right);
    nodeIT b = get(node * 2 + 1, (l + r) / 2 + 1, r, left, right);

    return merge(a,b);
}
void check(int l, int r, int d)
{
    int l1 = l, r1 = r - d;
    int l2 = l + d, r2 = r;
    // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    nodeIT val1 = get(1, 1, n, l1, r1);
    nodeIT val2 = get(1, 1, n, l2, r2);
    // cout << endl
    // cout << val1 << " " << val2 << endl;
    if (val1.hashval == val2.hashval)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
    // cout << endl;
}
void init()
{
    sum[0] = 0;
    Pow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        Pow[i] = (Pow[i - 1] * 10) % mod;
        sum[i] = (sum[i - 1] + Pow[i - 1]) % mod;
    }
    // Pow[i] = (Pow[i - 1] * 10) % mod;
    memset(Lazy, -1, sizeof(Lazy));
}
void solution()
{
    cin >> n >> m;
    init();
    // cout << sum[2] << endl;
    int key, x, y, val;
    string s;
    // cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    build(1, 1, n);
    // cout << get(1, 1, n, 1, 3) << endl;
    while (m--)
    {
        cin >> key >> x >> y >> val;
        if (key == 1)
        {
            update(1, 1, n, x, y, val);
            // cout<<endl<<endl;
        }
        else
        {
            check(x, y, val);
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
        // init();
        solution();
    }
    return 0;
}
/*THE END*/
