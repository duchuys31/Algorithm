int p[N];
void setup()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * 26 % mod;
}
struct HASH
{
    int f[N];
    void convert(string s)
    {
        s = "#" + s;
        For(i, 1, s.size() - 1)
        {
            f[i] = (f[i - 1] * 26 + s[i] - 'a') % mod;
        }
    }
    int get(int l, int r)
    {
        return (f[r] - f[l - 1] * p[r - l + 1] + mod * mod) % mod;
    }
    int val(string a)
    {
        int s = 0;
        for (auto x : a)
        {
            s = (s * 26 + x - 'a') % mod;
        }
        return s;
    }
};
