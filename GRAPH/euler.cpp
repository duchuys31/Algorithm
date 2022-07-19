void trace(int u)
{
    stack<int> st, ce;
    st.push(u);
    while (st.size())
    {
        u = st.top();
        bool ok = 0;
        for (auto x : g[u])
        {
            if (vis[u][x] == 0)
            {
                vis[u][x] = 1;
                st.push(x);
                ok = 1;
                break;
            }
        }
        if (!ok)
        {
            ce.push(u);
            st.pop();
        }
    }
    while (ce.size())
    {
        ans += 'a' + ce.top();
        ce.pop();
    }
}
