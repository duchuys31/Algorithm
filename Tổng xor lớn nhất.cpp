#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, ans;
struct Trie
{
    Trie *child[2];
    Trie()
    {
        for (int i = 0; i < 2; ++i)
            child[i] = NULL;
    }
};
Trie *root;
void TrieInsert(const int &s)
{
    Trie *p = root;
    for (int i = l - 1; i >= 0; --i)
    {
        int nxt = (s >> i) & 1;
        if (p->child[nxt] == NULL)
            p->child[nxt] = new Trie();
        p = p->child[nxt];
    }
}
void TrieFind(const int &s)
{
    int tmp = 0;
    Trie *p = root;
    for (int i = l - 1; i >= 0; --i)
    {
        int nxt = (s >> i) & 1;
        if (p->child[nxt] == NULL)
        {
            nxt = !nxt;
            tmp += (1 << i);
            if (tmp > ans)
                return;
        }
        p = p->child[nxt];
    }
    ans = tmp;
}
vector<int> vs;
void init()
{
    vs.clear();
    vs.push_back(0);
    l = 0;
    ans = 0;
    root = new Trie();
}
void solution()
{
    int tmp = 0, n, x, Max = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        tmp ^= x;
        vs.push_back(tmp);
        while (Max <= tmp)
            Max *= 2, l++;
    }
    for (auto i : vs)
        if (i > Max / 2)
            TrieInsert(i);
    Max -= 1;
    ans = Max;
    sort(vs.begin(), vs.end());
    for (int i = 0; i < vs.size(); ++i)
    {
        tmp = Max - vs[i];
        if (tmp < vs[i])
            break;
        TrieFind(tmp);
        if (!ans)
            break;
    }
    cout << Max - ans << endl;
}

/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        init();
        solution();
    }
}
/*THE END*/
