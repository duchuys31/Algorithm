ll n, m;
map<ll, ll> Trie[N];
ll cnt[N];
string s;
ll nxt = 1;

void insert(string a)
{
    ll now = 0;
    for (auto x : a)
    {
        if (!Trie[now].count(x))
        {
            Trie[now][x] = nxt;
            nxt += 1;
        }
        now = Trie[now][x];
    }
    cnt[now] += 1;
}
ll search(string a)
{
    ll now = 0;
    for (auto x : a)
    {
        if (!Trie[now].count(x))
            return 0;
        now = Trie[now][x];
    }
    return cnt[now];
}
