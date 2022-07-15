#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    vector<ll> pos_s, pos_t;

    if(s[0] != t[0] || s[n-1] != t[n-1]){
        cout << -1 << "\n";
        return;
    }
    for(int i=0; i<n-1; i++){
        if(s[i] != s[i+1]) pos_s.push_back(i);
        if(t[i] != t[i+1]) pos_t.push_back(i);
    }
    if(pos_s.size() != pos_t.size()){
        cout << -1 << "\n";
    }
    else{
        int k = pos_s.size();
        ll ans = 0;
        for(int i=0; i<k; ++i){
            ans += abs(pos_s[i] - pos_t[i]);
        }
        cout << ans << "\n";
    }
}

int main(){
    int tt; cin >> tt;
    while(tt--) solve();
}
