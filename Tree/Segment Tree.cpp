struct Seg
{
    int seg[4 * N], lazy[4 * N];
    void to_set(int x, int n)
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            seg[i] = x;
            lazy[i] = 0;
        }
    }
    int merge(int x, int y)
    {
        return x + y;
    }
    int add(int l, int r, int x)
    {
        return (r - l + 1) * x;
        // return x;
    }
    void down(int id, int l, int r)
    {
        int t = lazy[id];
        lazy[id] = 0;
        int m = (l + r) >> 1;

        seg[id << 1] += add(l, m, t);
        lazy[id << 1] += t;

        seg[id << 1 | 1] += add(m + 1, r, t);
        lazy[id << 1 | 1] += t;
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (l > v || r < u || l > r)
            return;
        if (l >= u && r <= v)
        {
            seg[id] += add(l, r, val);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u || l > r)
            return 0;
        if (l >= u && r <= v)
        {
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        int v1 = get(id << 1, l, mid, u, v);
        int v2 = get(id << 1 | 1, mid + 1, r, u, v);
        return merge(v1, v2);
    }

    void build(int a[], int id, int l, int r)
    {
        if (l == r)
        {
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, id << 1, l, mid);
        build(a, id << 1 | 1, mid + 1, r);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }
};
