//TEH NOOB KOBUAR
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define cnl cout << "\n"
#define nl "\n"
#define sp(x,n) fixed << setprecision(x) << n
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define len(x) int(x.length())
#define fore(i,l,r) for(auto i = l; i < r; ++i)
#define pb push_back
#define pf push_front

using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;

/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vii restaurantes(n);
    
    fore(i,0,n){
        cin >> restaurantes[i].first >> restaurantes[i].second;
    }
    
    sort(all(restaurantes), [&](const ii & a, const ii & b){
       return a.second < b.second;
    });
    
    //for(auto & x : restaurantes)cout << x.first << " " << x.second << nl;
    
    vii dp;
    fore(i,0,n){
        auto it = lower_bound(all(dp),restaurantes[i]);
    
        if(it == dp.end())dp.pb(restaurantes[i]);
        else *it = restaurantes[i];
}

    
    cout << sz(dp);
    
    cout << "\n";

    return 0;
}
