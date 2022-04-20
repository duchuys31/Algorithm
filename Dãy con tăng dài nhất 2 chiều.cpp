#include <bits/stdc++.h>
using namespace std;
// S31[:v]
//  #define int long long
#define fi first
#define se second
typedef pair<int, int> ii;
// typedef vector<int> v;
// int di[]={-1,0,0,1,-1,-1,1,1};

// int dj[]={0,-1,1,0,-1,1,-1,1};
//
const int N = 1e5 + 5;
ii a;
int n;
set<ii> s[N];
bool cmp(ii x, ii y)
{
    return (x.fi < y.fi && x.se < y.se);
}
bool check(set<ii> &s)
{
    for (ii x : s)
    {
        if (cmp(x, a))
            return true;
        else if (x.fi >= a.fi)
            break;
    }
    return false;
}
int search(int left, int right)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(s[mid]))
        {
            left = mid + 1;
        }
        else
            right = mid;
    }
    return left;
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (auto x : s[i])
        {
            cout << x.fi << "-" << x.se << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//
main()
{
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i << ":" << endl;
        cin >> a.fi >> a.se;
        int id = search(0, n);
        if (id < n)
        {
            auto x = ++s[id].insert(a).first;
            while (x != s[id].end())
            {
                if (cmp(a, *x))
                    s[id].erase(x++);
                else
                    x++;
            }
        }
        print();
    }
    int ans = 0;
    cout << ans;
    return 0;
}
// TheEnd
