// COMPLETE SEARCH


#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main()
{
    int n;
    
    cin >> n;
    
    vector<pair<int, int>> a(n), b(n);
 
    for(int i = 0; i < n; i++){
        int q; cin >> q;
        
        a[i].first = q;
        b[i].first = q;
    }
    
    for(int i = 0; i < n; i++){
        int q; cin >> q;
        
        a[i].second = q;
        b[i].second = q;
    }
    
    
    int max_dist = 0;
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            
            int cur_dist = pow((b[j].first - a[i].first), 2) + pow((b[j].second - a[i].second), 2);
            
            max_dist = max(max_dist, cur_dist);
        }
    }
    
    
    cout << max_dist;
 
}