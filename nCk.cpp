int fac[N];
int fac_inv[N];
int inv[N];
void setup()
{
    int n = 1e5;
    fac[0] = inv[1] = fac_inv[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }
}
int nCk(int n, int k)
{
    return fac[n] * fac_inv[k] % mod * fac_inv[n - k] % mod;
}
