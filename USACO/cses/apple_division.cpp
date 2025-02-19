// COMPLETE SEARCH WITH RECURSION

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> v;
int mw = 20*1e9; // diferença máxima de peso possível



void fmw(int idx, int sum1, int sum2){
    if(idx == v.size()){ 
        
        mw = min(mw, abs(sum1-sum2)); // finished processing subset
        
    }else{
        
        fmw(idx + 1, sum1 + v[idx], sum2); // include current element in subset1
        
        fmw(idx + 1, sum1, sum2 + v[idx]); // include current element in subset2
        
    }
}

signed main()
{
    cin >> n;
    
    v.resize(n);
    
    for(int i = 0; i < n; i++){
        
        cin >> v[i];
    }
    
    fmw(0, 0, 0);
    
    cout << mw;

}