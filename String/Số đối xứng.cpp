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
// #define int long long
#define ll long long
// #define db double
// #define fi first
// #define se second

// typedef pair<int, int> ii;
// typedef vector<int> v;

// const ll oo = 1e13;
const ll mod = 1e9 + 3;
const ll N = 1e5 + 5;

// int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
// int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
struct nodeIT
{
    ll length;
    ll hashval;
};
ll n, m;
ll a[N];
nodeIT Tree[4 * N], rTree[4 * N];
ll Lazy[4 * N], rLazy[4 * N];
ll Pow[N];

nodeIT merge(nodeIT A, nodeIT B)
{
    nodeIT ans;
    ans.length = A.length + B.length;
    ans.hashval = (A.hashval * Pow[B.length] + B.hashval) % mod;
    return ans;
}

void build(ll node, ll l, ll r)
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
void rbuild(ll node, ll l, ll r)
{
    if (l == r)
    {
        rTree[node].hashval = a[l];
        rTree[node].length = 1;
    }
    else
    {
        ll m = (l + r) / 2;
        rbuild(2 * node, l, (l + r) / 2);
        rbuild(2 * node + 1, (l + r) / 2 + 1, r);

        rTree[node] = merge(rTree[node * 2], rTree[node * 2 + 1]);
    }
}
void update(ll node, ll l, ll r, ll left, ll right, ll val)
{
    if (Lazy[node] != -1)
    {
        Tree[node].hashval = Lazy[node];

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
        Tree[node].hashval = val;

        if (l != r)
        {
            Lazy[node * 2] = val;
            Lazy[node * 2 + 1] = val;
        }
        return;
    }
    update(node * 2, l, (l + r) / 2, left, right, val);
    update(node * 2 + 1, (l + r) / 2 + 1, r, left, right, val);
    Tree[node] = merge(Tree[node * 2], Tree[node * 2 + 1]);
}
void rupdate(ll node, ll l, ll r, ll left, ll right, ll val)
{
    if (rLazy[node] != -1)
    {
        rTree[node].hashval = rLazy[node];

        if (l != r)
        {
            rLazy[node * 2] = Lazy[node];
            rLazy[node * 2 + 1] = Lazy[node];
        }
        rLazy[node] = -1;
    }
    if (r < left || l > right)
        return;
    if (left <= l && r <= right)
    {
        rTree[node].hashval = val;

        if (l != r)
        {
            rLazy[node * 2] = val;
            rLazy[node * 2 + 1] = val;
        }
        return;
    }
    rupdate(node * 2, l, (l + r) / 2, left, right, val);
    rupdate(node * 2 + 1, (l + r) / 2 + 1, r, left, right, val);
    rTree[node] = merge(rTree[node * 2], rTree[node * 2 + 1]);
}
nodeIT get(ll node, ll l, ll r, int left, ll right)
{
    if (l > right || r < left)
        return {0, 0};
    if (Lazy[node] != -1)
    {
        Tree[node].hashval = Lazy[node];
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

    return merge(a, b);
}
nodeIT rget(ll node, ll l, ll r, int left, ll right)
{
    if (l > right || r < left)
        return {0, 0};
    if (rLazy[node] != -1)
    {
        rTree[node].hashval = rLazy[node];
        if (l != r)
        {
            rLazy[node * 2] = rLazy[node];
            rLazy[node * 2 + 1] = rLazy[node];
        }
        rLazy[node] = -1;
    }
    if (l >= left && r <= right)
        return rTree[node];
    nodeIT a = rget(node * 2, l, (l + r) / 2, left, right);
    nodeIT b = rget(node * 2 + 1, (l + r) / 2 + 1, r, left, right);

    return merge(a, b);
}
void check(ll l, ll r)
{
    int mid = (l + r) / 2;
    // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    nodeIT val1;
    if ((r - l + 1) % 2 == 0)
        val1 = get(1, 1, n, l, mid);
    else
        val1 = get(1, 1, n, l, mid - 1);
    nodeIT val2 = rget(1, 1, n, n - r + 1, n - mid);
    // cout << val1.hashval << " " << val2.hashval << endl;
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
    Pow[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        Pow[i] = (Pow[i - 1] * 10) % mod;
    }
    // Pow[i] = (Pow[i - 1] * 10) % mod;
    memset(Lazy, -1, sizeof(Lazy));
    memset(rLazy, -1, sizeof(rLazy));
}
void solution()
{
    string s;
    cin >> s;
    n = s.size();
    cin >> m;
    init();
    // cout << sum[2] << endl;
    char key;
    int x, y;
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    build(1, 1, n);
    reverse(a + 1, a + n + 1);
    rbuild(1, 1, n);
    while (m--)
    {
        cin >> key >> x >> y;
        if (key == 'c')
        {
            update(1, 1, n, x, x, y);
            rupdate(1, 1, n, n - x + 1, n - x + 1, y);
            // cout<<endl<<endl;
        }
        else
        {
            check(x, y);
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
