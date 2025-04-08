//Longest Increasing Subsequence

#include <bits/stdc++.h>
#define int long long


using namespace std;


signed main(){
    // Naive LIS (complexity O(n²) not ideal)
    vector<int> v = {2, 18, 7, 20, 18, 5, 18, 15, 13, 19, 9}; 
    
    int n = v.size();

/*     vector<int> dp(n, 1);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            
            if(v[j] < v[i]){
                
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int lis_size = 1;

    for(int i = 0; i < n; i++){
        lis_size = max(lis_size, dp[i]);
    }

    cout << lis_size; // should print 4 */



    // Optimized LIS (use binary search) O(n * log n) complexity


    // L
    vector <int> dp;



    // Lema: O tamanho da LIS terminando em v[i+1], é igual a j+1, onde j é o menor valor possível que staisfaz dp[j] >= v[i+1]
    // Para encontrar esse j usamos lower bound.
    
    for(int i = 0; i < n; i++){

        auto it = lower_bound(dp.begin(), dp.end(), v[i]);


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