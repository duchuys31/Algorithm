struct LCA
{
    v height, euler, first, seg;
    vb vis;
    int n, m;
    LCA(vv g, int root = 1)
    {
        n = g.size();
        height.resize(n);
        first.resize(n);
        vis.resize(n, 0);
        dfs(g, root);
        m = euler.size();
        seg.resize(m * 4);
        build(1, 0, m - 1);
    }
    void dfs(vv g, int node, int h = 0)
    {
        vis[node] = 1;
        height[node] = h;
        first[node] = euler.size();
        euler.pb(node);
        for (auto x : g[node])
        {
            if (vis[x])
                continue;
            dfs(g, x, h + 1);
            euler.pb(node);
        }
    }
    void build(int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = euler[l];
        }
        else
        {
            int m = (l + r) / 2;
            build(node * 2, l, m);
            build(node * 2 + 1, m + 1, r);
            int x = seg[node * 2], y = seg[node * 2 + 1];
            seg[node] = (height[x] < height[y]) ? x : y;
        }
    }
    int get(int node, int L, int R, int l, int r)
    {
        if (L > r || l > R)
            return -1;
        if (l <= L && R <= r)
            return seg[node];
        int m = (L + R) / 2;
        int x = get(node * 2, L, m, l, r);
        int y = get(node * 2 + 1, m + 1, R, l, r);
        if (x == -1)
            return y;
        if (y == -1)
            return x;
        return height[x] < height[y] ? x : y;
    }
    int lca(int x, int y)
    {
        int l = first[x], r = first[y];
        if (l > r)
            swap(l, r);
        return get(1, 0, m - 1, l, r);
    }
};
