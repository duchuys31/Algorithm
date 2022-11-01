
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef pair<ll, ll> ii;
#define int long long

#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define vec vector
#define pb push_back
#define all(a) a.begin(), a.end()
#define fi first
#define se second


const ll N = 1e5 + 5;
const ll mod = 998244353;
const ll oo = 1e18;

string s;
ll n;
map<ll, ll> segment;
ll p[N];
struct node
{
    ll sum, l, r;
    ll dir;
    struct child
    {
        ll sum, l, r, dir;
    } front, back;
    node()
    {
        sum = -1, l = -1, r = -1, dir = 1;
        front.l = front.r = -1;
        front.sum = front.dir = -1;
        back.l = back.r = -1;
        back.sum = back.dir = -1;
    }
};
void print(node x)
{
    cout << "NODE [" << x.l << "," << x.r << "]\n";
    cout << x.sum << ":" << x.dir << endl;
    cout << "FRONT [" << x.front.l << "," << x.front.r << "]\n";
    cout << x.front.sum << ":" << x.front.dir << endl;
    cout << "BACK [" << x.back.l << "," << x.back.r << "]\n";
    cout << x.back.sum << ":" << x.back.dir << endl;
}
ii pos(ll l, ll r)
{
    auto it = segment.upper_bound(l);
    return *prev(it);
}

node merge(node l, node r)
{
    if (l.l == -1 && l.r == -1)
        return r;
    if (r.l == -1 && r.r == -1)
        return l;
    node ans;
    ans.l = l.l;
    ans.r = r.r;
    ans.sum = (l.sum + r.sum + mod * mod) % mod;
    ans.front = l.front;
    ans.back = r.back;
    ans.dir = 1;
    if (pos(l.back.l, l.back.r) == pos(r.front.l, r.front.r))
    {
        ans.sum -= (l.back.sum + r.front.sum + mod * mod) % mod;
        ll sum = 0;
        if (l.back.dir != r.front.dir)
            sum = ((l.back.sum * p[r.front.r - r.front.l + 1]) % mod + abs(r.front.sum) * l.back.dir) % mod;
        else
            sum = ((l.back.sum * p[r.front.r - r.front.l + 1]) % mod + r.front.sum) % mod;
        sum = (sum + mod * mod) % mod;
        ans.sum = (ans.sum + sum + mod * mod) % mod;
        if (pos(l.front.l, l.front.r) == pos(r.back.l, r.back.r))
        {
            ans.dir = l.front.dir;
            ans.front = {ans.sum, l.l, r.r, l.front.dir};
            ans.back = {ans.sum, l.l, r.r, l.front.dir};
        }
        else
        {
            if (pos(l.front.l, l.front.r) == pos(l.back.l, l.back.r))
            {
                ans.front = {sum, l.front.l, r.front.r, l.front.dir};
            }
            if (pos(r.front.l, r.front.r) == pos(r.back.l, r.back.r))
            {
                ans.back = {sum, l.back.l, r.back.r, l.back.dir};
            }
        }
    }
    return ans;
}

node seg[4 * N];

void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        ll sum = isdigit(s[l]) ? s[l] - '0' : 0;
        seg[id].sum = sum;
        seg[id].l = l;
        seg[id].r = r;
        seg[id].front = {sum, l, r, 1};
        seg[id].back = {sum, l, r, 1};
        seg[id].dir = 1;
    }
    else
    {
        ll m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }
}

void update(ll id, ll l, ll r, ll x, ll value, ll type)
{
    if (l == x && x == r)
    {
        seg[id].sum = value;
        seg[id].dir = type;
        seg[id].front.sum = value;
        seg[id].front.dir = type;
        seg[id].back.sum = value;
        seg[id].back.dir = type;
        return;
    }
    ll m = (l + r) / 2;
    if (x <= m)
        update(id * 2, l, m, x, value, type);
    else
        update(id * 2 + 1, m + 1, r, x, value, type);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(ll id, ll l, ll r, ll x, ll y)
{
    if (l > y || r < x)
        return node();
    if (l >= x && r <= y)
    {
        return seg[id];
    }
    ll m = (l + r) / 2;
    node x1 = get(id * 2, l, m, x, y);
    node x2 = get(id * 2 + 1, m + 1, r, x, y);
    return merge(x1, x2);
}

void init()
{
    p[0] = 1;
    For(i, 1, N - 1) p[i] = (p[i - 1] * 10) % mod;
    For(i, 0, 4 * N - 1) seg[i] = node();
}
void solution()
{
    init();
    cin >> s;
    n = s.size();
    s = "+" + s;
    segment[n + 1] = n + 1;
    Ford(i, n, 0)
    {
        if (!isdigit(s[i]))
        {
            segment[i] = segment.upper_bound(i)->fi - 1;
        }
    }
    build(1, 1, n);
    For(i, 1, n)
    {
        if (!isdigit(s[i]))
        {
            update(1, 1, n, i, 0, (s[i] == '+' ? 1 : -1));
            // break;
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            ll x, y;
            cin >> x >> y;
            node ans = get(1, 1, n, x, y);
            cout << (ans.sum + mod * mod) % mod << endl;
        }
        else if (type == '!')
        {
            ll u;
            char C;
            cin >> u >> C;
            s[u] = C;
            if (!isdigit(C))
            {
                if (segment.count(u))
                    update(1, 1, n, u, 0, (C == '+' ? 1 : -1));
                else
                {
                    auto it = segment.upper_bound(u);
                    segment[prev(it)->fi] = u - 1;
                    segment[u] = it->fi - 1;
                    update(1, 1, n, u, 0, ((C == '+' ? 1 : -1)));
                }
            }
            else
            {
                if (!segment.count(u))
                    update(1, 1, n, u, C - '0', 1);
                else
                {
                    auto it = segment.lower_bound(u);
                    segment[prev(it)->fi] = it->se;
                    segment.erase(it);
                    update(1, 1, n, u, C - '0', 1);
                }
            }
        }
    }
}
main()
{
    ll T = 1;
    // cin >> T;
    For(test, 1, T)
    {
        // cout << "TEST " << test << ": \n";
        solution();
    }
}
