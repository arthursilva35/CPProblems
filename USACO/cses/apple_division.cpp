// COMPLETE SEARCH WITH RECURSION

#include <bits/stdc++.h>
#define int long long
 
 
 
 
// da pra usar bitmask!!!
 
using namespace std;
 
 
int find_minimum_weight(vector<int> &v, int idx, int sum1, int sum2){
    
    if(idx == v.size()) return abs(sum1 - sum2);
    
    return min(find_minimum_weight(v, idx+1, sum1 + v[idx], sum2),
        find_minimum_weight(v, idx+1, sum1, sum2 + v[idx])); // verifica se é melhor adicionar o próximo elemento ao vetor 1 ou 2
}
 
signed main()
{
    int n; // n < 20, dá pra fazer busca completa
    
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        int q; cin >> q;
        
        v[i] = q;
        
    }
    
    
    
    
    cout << find_minimum_weight(v, 0,  0, 0) << endl;
   
}