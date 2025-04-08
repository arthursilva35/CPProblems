#include <bits/stdc++.h>
#define int long long

using namespace std;



// the minimum number of longest increasing subsequences is the size of the longest non-increasing subsequence
// dilworth theorem

signed main(){
    int n;

    cin >> n;

    vector<int> v(n), dp;

    for(int i = 0; i < n; i++){

        cin >> v[i];
    
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < n; i++){

        auto it = upper_bound(dp.begin(), dp.end(), v[i]);


        if( it == dp.end()){
            // podemos adicionar e ao final da subsequencia crescente
            
            dp.push_back(v[i]);
        }
        else{
            // nao podemos aumentar o tamanho da subsequencia crescente, apenas tornar o elemento na posição j menor
            
            int idx = it - dp.begin();
            dp[idx] = v[i];
        }
    }

    // dp NÃO guarda a maior subsequencia crescente

    cout << dp.size();




    
}