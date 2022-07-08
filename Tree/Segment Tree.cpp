struct Seg
{
    int seg[4 * N], lazy[4 * N];
    void to_set(int x)
    {
        for (int i = 0; i <= 4 * N; i++)
            seg[i] = x;
    }
    int merge(int x, int y)
    {
        return max(x, y);
    }
    void down(int id)
    {
        int t = lazy[id];
        seg[id << 1] += t;
        seg[id << 1 | 1] += t;
        lazy[id << 1] += t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int u, int val)
    {
        if (r < u)
            return;
        if (l >= u)
        {
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, val);
        update(id << 1 | 1, mid + 1, r, u, val);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return -oo;
        if (l >= u && r <= v)
        {
            return seg[id];
        }
        down(id);
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
