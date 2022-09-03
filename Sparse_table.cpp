template <typename type>
struct SparseTable
{
    int n;
    vec<vec<type>> spt;
    v log;
    SparseTable(int a = 0) : n(a)
    {
        log.assign(n + 1, 0);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            log[i] = log[i >> 1] + 1;
        }
        spt.assign(n + 1, vec<type>(log[n] + 1));
    }
    inline type merge(int x, int y)
    {
        return min(x, y);
    }
    inline void build(int a[])
    {
        for (int i = 1; i <= n; i++)
            spt[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                spt[i][j] = merge(spt[i][j - 1], spt[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    inline int get(int l, int r)
    {
        int len = log[r - l + 1];
        return merge(spt[l][len], spt[r - (1 << len) + 1][len]);
    }
};
