

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
typedef pair<pii, pii> ppp;
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/
void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}

#define debug(...) cerr << "(" << #__VA_ARGS__ << "): ", debug_out(__VA_ARGS__)
#define here cerr << "here\n"
#define MP make_pair
#define F first
#define S second

constexpr int MAXN = 2e5 + 2;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 2;
constexpr int LOG = 3e1 + 2;
constexpr int SQ = 2e3 + 20;
constexpr int ALP = 130;

inline int mul(int a, int b)
{
    return 1ll * a * b % MOD;
}

int pwr(int a, int b)
{
    if (!b)
    {
        return 1;
    }
    int ret = pwr(a, b >> 1);
    ret = mul(ret, ret);
    if (b & 1)
    {
        ret = mul(ret, a);
    }
    return ret;
}

int inv(int p)
{
    return pwr(p, MOD - 2);
}

int n, q, a[MAXN], ans[MAXN], P[5 * MAXN], fen[MAXN];
ppi Q[MAXN];
vector<int> G[5 * MAXN], vc;

void add(int idx, int x)
{
    for (idx; idx <= n; idx += idx & -idx)
    {
        fen[idx] = mul(fen[idx], x);
    }
}

inline int get(int idx)
{
    int ret = 1;
    for (idx; idx > 0; idx -= idx & -idx)
    {
        ret = mul(fen[idx], ret);
    }
    return ret;
}

inline int get(int l, int r)
{
    return mul(get(r), inv(get(l - 1)));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fen[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        add(i, a[i]);
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i].F.F >> Q[i].F.S;
        Q[i].S = i;
    }
    sort(Q + 1, Q + q + 1);
    for (int i = 2; i < 5 * MAXN; i++)
    {
        if (!P[i])
        {
            vc.push_back(i);
            P[i] = i;
            for (int j = i << 1; j < 5 * MAXN; j += i)
            {
                P[j] = i;
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        int tmp = a[i];
        while (tmp != 1)
        {
            G[P[tmp]].push_back(i);
            tmp /= P[tmp];
        }
    }
    for (auto p : vc)
    {
        if (!G[p].empty())
        {
            add(G[p].back(), mul(p - 1, inv(p)));
        }
    }
    int ptr = 1;
    for (int i = 1; i <= q; i++)
    {
        int l = Q[i].F.F, r = Q[i].F.S, idx = Q[i].S;
        while (ptr < l)
        {
            int tmp = a[ptr];
            while (tmp != 1)
            {
                G[P[tmp]].pop_back();
                if (!G[P[tmp]].empty())
                {
                    add(G[P[tmp]].back(), mul(P[tmp] - 1, inv(P[tmp])));
                }
                tmp /= P[tmp];
            }
            ptr++;
        }
        ans[idx] = get(l, r);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
