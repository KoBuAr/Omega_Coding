#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define nl cout<<"\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front

/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> victor;

    fore(i, 0, n) {
        string a;
        cin >> a;

        if (a == "ADD") {
            int y;
            cin >> y;
            victor.pb(y);
        }
        else if (a == "POP") {
            victor.pop_back();
        }
        else if (a == "DELETE") {
            int l, r;
            cin >> l >> r;

            
              victor.erase(victor.begin() + l-1, victor.begin() + r);
    
            }
        
        else if (a == "INSERT") {
            int i, x;
            cin >> i >> x;

            victor.insert(victor.begin() + (i-1), x);
          
        }
    }
        
        for (auto z : victor) {
        cout << z << " ";
    
        }
    return 0;

}
