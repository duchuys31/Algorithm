ll inv[N], fac[N], Inv[N];

ll nCk(int n, int m) { return (m > n) ? 0 : ((fac[n] * Inv[n - m]) % mod) * Inv[m] % mod; }

void setup()
{
    inv[0] = fac[0] = Inv[0] = inv[1] = fac[1] = Inv[1] = 1;
    For(i, 2, (int)(2e5))
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        Inv[i] = Inv[i - 1] * inv[i] % mod;
    }
}
