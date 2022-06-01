struct Segment_Tree
{
    int Max[4 * N], Min[4 * N], Sum[4 * N];
    int Tree[4 * N], lazy[4 * N];
    void set_min()
    {
        for (int i = 0; i <= 4 * N; i++)
            Min[i] = oo;
    }
    void build(int a[], int node, int l, int r)
    {
        if (l == r)
        {
            // Tree[node] = a[l];
            // Max[node] = a[l];
            // Min[node] = a[l];
            // Sum[node] = a[l];
        }
        else
        {
            build(a, 2 * node, l, (l + r) / 2);
            build(a, 2 * node + 1, (l + r) / 2 + 1, r);
            // Tree[node] = (Tree[node * 2], Tree[node * 2 + 1]);
            // Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
            // Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
            // Sum[node] = Sum[node * 2] + Sum[node * 2 + 1];
        }
    }
    void update(int node, int l, int r, int left, int right, int value)
    {
        if (lazy[node] != 0)
        {
            // Tree[node] += lazy[node];
            // Max[node] += lazy[node];
            // Min[node] += lazy[node];
            // Sum[node] += lazy[node];
            if (l != r)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (r < left || l > right)
            return;
        if (l >= left && r <= right)
        {
            // Tree[node] += value;
            // Max[node] += value;
            // Min[node] += value;
            // Sum[node] += value;
            if (l != r)
            {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }
        update(node * 2, l, (l + r) / 2, left, right, value);
        update(node * 2 + 1, (l + r) / 2 + 1, r, left, right, value);
        // Tree[node] = (Tree[node * 2], Tree[node * 2 + 1]);
        // Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
        // Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
        // Sum[node] = Sum[node * 2] + Sum[node * 2 + 1];
    }
    int get(int node, int l, int r, int left, int right)
    {
        if (l > right || r < left)
            return 0;
        if (lazy[node] != 0)
        {
            Tree[node] += lazy[node];
            if (l != r)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (l >= left && r <= right)
            return Tree[node];
        return (get(node * 2, l, (l + r) / 2, left, right), get(node * 2 + 1, (l + r) / 2 + 1, r, left, right));
    }
    int get_max(int node, int l, int r, int left, int right)
    {
        if (l > right || r < left)
            return 0;
        if (lazy[node] != 0)
        {
            Max[node] += lazy[node];
            if (l != r)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (l >= left && r <= right)
            return Max[node];
        return max(get(node * 2, l, (l + r) / 2, left, right), get(node * 2 + 1, (l + r) / 2 + 1, r, left, right));
    }
    int get_min(int node, int l, int r, int left, int right)
    {
        if (l > right || r < left)
            return oo;
        if (lazy[node] != 0)
        {
            Min[node] += lazy[node];
            if (l != r)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (l >= left && r <= right)
            return Min[node];
        return min(get(node * 2, l, (l + r) / 2, left, right), get(node * 2 + 1, (l + r) / 2 + 1, r, left, right));
    }
    int get_sum(int node, int l, int r, int left, int right)
    {
        if (l > right || r < left)
            return 0;
        if (lazy[node] != 0)
        {
            Sum[node] += lazy[node];
            if (l != r)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            Sum[node] = 0;
        }
        if (l >= left && r <= right)
            return Sum[node];
        return get(node * 2, l, (l + r) / 2, left, right)+ get(node * 2 + 1, (l + r) / 2 + 1, r, left, right);
    }
};
