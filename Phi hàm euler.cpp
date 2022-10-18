ll e[N];
void init()
{
    For(i, 1, N - 1) e[i] = i;
    For(i, 2, N - 1){
        if(e[i] == i){
            e[i] = i - 1;
            for (ll j = i * 2; j < N; j += i)
                e[j] = e[j] - e[j] / i;
        }
    }
}
