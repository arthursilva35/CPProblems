#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n;
    
    cin >> n;

    char last;

    vector<int> p, l;

    vector< vector<int>> dp(n+1, vector<int>(3, -1)); // dp[i][j] guarda o max de pontos usando as 



    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    for(int i = 0; i < n; i++){
        cin >> l[i];
    }



    if(p[0] > l[0]){
        last = 'p';
    }else{
        last = 'l';
    }


    // caso base
    for(int i = 0; i <= 3; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= 3; i++){
        for(int i = 1; i <= n; i++){
               
        
        }
    }

    
}