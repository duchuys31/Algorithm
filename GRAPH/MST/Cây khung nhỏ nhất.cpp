#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef pair <ii,int> iii;
typedef vector<int> v;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
int n, m;
vector<int> parent(300001);
vector<int> ranked(300001);
 
struct Edge
{
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
 
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
 
void init()
{
    for (int i = 0; i <= 300000; i++)
    {
        parent[i] = i;
        ranked[i] = 0;
    }
}
 
int findSet(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = findSet(parent[x]);
    return parent[x];
}
 
bool Union(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if (u == v)
        return false;
    parent[v] = u;
    return true;
}
 
vector<Edge> edges;
main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        edges.clear();
        cin >> n >> m;
        long long res = 0;
        while (m--)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }
        sort(edges.begin(), edges.end(), cmp);
        for (auto i : edges)
        {
            if (!Union(i.u, i.v))
                continue;
            res += i.w;
        }
        cout << res << endl;
    }
}
//TheEnd
