#include <bits/stdc++.h>
using namespace std;
/* 𝑴𝒚 𝒄𝒂𝒕 𝒊𝒔 𝒍𝒐𝒐𝒌𝒊𝒏𝒈 𝒂𝒕 𝒚𝒐𝒖 ◉‿◉. */
/* 𝑭𝒆𝒆𝒅 𝒊𝒕 𝒂𝒏𝒅 𝒊𝒕 𝒘𝒊𝒍𝒍 𝒉𝒆𝒍𝒑 𝒚𝒐𝒖 𝒖𝒏𝒅𝒆𝒓𝒔𝒕𝒂𝒏𝒅 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 (｡◕‿◕｡). */
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒███
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
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef pair<db, db> dd;
typedef vector<int> v;

const ll oo = 9223372036854775807;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, m, q;
int a[1005][1005];
int Lazy[1005][4005];
int Tree[1005][4005];
int TREE[4005], LAZY[4005];
void build(int i, int node, int l, int r)
{
    if (l == r)
        Tree[i][node] = a[l][i];
    else
    {
        build(i, 2 * node, l, (l + r) / 2);
        build(i, 2 * node + 1, (l + r) / 2 + 1, r);
        Tree[i][node] = Tree[i][node * 2] + Tree[i][node * 2 + 1];
    }
}
void BUILD(int node, int l, int r)
{
    if (l == r)
        TREE[node] = Tree[l][1];
    else
    {
        BUILD(2 * node, l, (l + r) / 2);
        BUILD(2 * node + 1, (l + r) / 2 + 1, r);
        TREE[node] = TREE[2 * node] + TREE[2 * node + 1];
    }
}
void update(int i, int node, int l, int r, int left, int right, int val)
{
    if (Lazy[i][node] != 0)
    {
        Tree[i][node] += (r - l + 1) * Lazy[i][node];
        if (l != r)
        {
            Lazy[i][node * 2] += Lazy[i][node];
            Lazy[i][node * 2 + 1] += Lazy[i][node];
        }
        Lazy[i][node] = 0;
    }
    if (r < left || l > right)
        return;
    if (left <= l && r <= right)
    {
        Tree[i][node] += (r - l + 1) * val;
        if (l != r)
        {
            Lazy[i][node * 2] += val;
            Lazy[i][node * 2 + 1] += val;
        }
        return;
    }
    update(i, node * 2, l, (l + r) / 2, left, right, val);
    update(i, node * 2 + 1, (l + r) / 2 + 1, r, left, right, val);
    Tree[i][node] = Tree[i][node * 2] + Tree[i][node * 2 + 1];
}
void UPDATE(int node, int l, int r, int left, int right, int val)
{
    if (LAZY[node] != 0)
    {
        TREE[node] += (r - l + 1) * LAZY[node];
        if (l != r)
        {
            LAZY[node * 2] += LAZY[node];
            LAZY[node * 2 + 1] += LAZY[node];
        }
        LAZY[node] = 0;
    }
    if (r < left || l > right)
        return;
    if (left <= l && r <= right)
    {
        TREE[node] += (r - l + 1) * val;
        if (l != r)
        {
            LAZY[node * 2] += val;
            LAZY[node * 2 + 1] += val;
        }
        return;
    }
    UPDATE(node * 2, l, (l + r) / 2, left, right, val);
    UPDATE(node * 2 + 1, (l + r) / 2 + 1, r, left, right, val);
    TREE[node] = TREE[node * 2] + TREE[node * 2 + 1];
}
int get(int i, int node, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return 0;
    if (Lazy[i][node] != 0)
    {
        Tree[i][node] += (r - l + 1) * Lazy[i][node];
        if (l != r)
        {
            Lazy[i][node * 2] += Lazy[i][node];
            Lazy[i][node * 2 + 1] += Lazy[i][node];
        }
        Lazy[i][node] = 0;
    }
    if (l >= left && r <= right)
        return Tree[i][node];
    return get(i, node * 2, l, (l + r) / 2, left, right) + get(i, node * 2 + 1, (l + r) / 2 + 1, r, left, right);
}
int GET(int node, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return 0;
    if (LAZY[node] != 0)
    {
        TREE[node] += (r - l + 1) * LAZY[node];
        if (l != r)
        {
            LAZY[node * 2] += LAZY[node];
            LAZY[node * 2 + 1] += LAZY[node];
        }
        LAZY[node] = 0;
    }
    if (l >= left && r <= right)
        return TREE[node];
    return GET(node * 2, l, (l + r) / 2, left, right) + GET(node * 2 + 1, (l + r) / 2 + 1, r, left, right);
}

/*Main*/
void init()
{
}
void solution()
{
    cin >> n >> m >> q;

    For(i, 1, n)
    {
        For(j, 1, m)
        {
            char x;
            cin >> x;
            a[i][j] = (x == '*');
        }
    }
    For(i, 1, m)
    {
        build(i, 1, 1, n);
    }
    BUILD(1, 1, m);
    For(i, 1, q)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y])
        {
            // cout<<1<<endl;
            a[x][y] = 0;
            update(y, 1, 1, n, x, x, -1);
            UPDATE(1, 1, m, y, y, -1);
        }
        else
        {
            // cout<<-1<<endl;
            a[x][y] = 1;
            update(y, 1, 1, n, x, x, 1);
            UPDATE(1, 1, m, y, y, 1);
        }
        int s = GET(1, 1, m, 1, m);
        int r, c;
        r = s / n;
        c = s % n;
        if(r)s -= GET(1, 1, m, 1, r);
        if(c)s -= get(r + 1, 1, 1, n, 1, c);
        // cout << GET(1, 1, n, 1, n) << "-" << get(r + 1, 1, 1, n, 1, c) << endl;
        cout << s << endl;
        // cout << endl;
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
    // cin >> t;
    while (t--)
    {
        // db start = (db)(clock());
        init();
        solution();
        // db end = (db)(clock());
        // cout << (end - start) / CLOCKS_PER_SEC <<"s"<<endl;
    }
    return 0;
}
/* 𝑴𝒚 𝒄𝒐𝒅𝒆 𝒉𝒂𝒔 𝒆𝒏𝒅𝒆𝒅. */
/* 𝑺𝒆𝒆 𝒚𝒐𝒖 𝒂𝒈𝒂𝒊𝒏 ❤ */
/*
♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪
▄ █ ▄ █ ▄ ▄ █ ▄ █ ▄ █
Min- - - - - - - - - - - -●Max
*/
