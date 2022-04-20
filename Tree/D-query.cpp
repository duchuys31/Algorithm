#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
struct T
{
    int l, r;
    int sum;
    T *left, *right;
    T(int l, int r)
    {
        this->l = l;
        this->r = r;
        this->sum = 0;
        left = right = NULL;
    }
    T *update(int i)
    {
        T *a = new T(l, r);
        if (l == r)
        {
            a->sum = sum + 1;
        }
        else
        {
            if (i <= (l + r) / 2)
            {
                a->left = left->update(i);
                a->right = right;
            }
            else
            {
                a->left = left;
                a->right = right->update(i);
            }
            a->sum = a->left->sum + a->right->sum;
        }
        return a;
    }
    int get(int i)
    {
        cout << l << "," << r << ":" << i << "->";
        if (i < l){
            cout<<"0"<<endl;
            return 0;
        }
        if (r <= i){
            cout<<sum<<endl;
            return sum;
        }
        cout<<"continue"<<endl;
        return left->get(i) + right->get(i);
    }
};
T *build(int l, int r)
{
    T *a = new T(l, r);
    if (l != r)
    {
        a->left = build(l, (l + r) / 2);
        a->right = build((l + r) / 2 + 1, r);
    }
    return a;
}
int n;
int a[N];
int last[N];
T *root[N];
void convert()
{
    v b(a + 1, a + n + 1);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
}
void init() {}
void solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    convert();
    for (int i = 1; i <= n; i++)
        last[a[i]] = n + 1;
    root[n + 1] = build(1, n + 1);
    for (int i = n; i >= 1; i--)
    {
        root[i] = root[i + 1]->update(last[a[i]]);
        last[a[i]] = i;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (r - l + 1) - root[l]->get(r) << endl;
    }
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
