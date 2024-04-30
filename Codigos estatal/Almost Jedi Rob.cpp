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
