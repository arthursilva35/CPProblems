#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> pi(string s){

    vector<int>p(s.size());

    for(int i = 1, j = 0; i < s.size(); i++){

        while( j > 0 && s[j] != s[i] ) j = p[j -1];
        if (s[j]  ==  s[i]) j++;
        p[i] = j;
    }

    return p;
}

int kmp(string& t, string& s){
    vector<int> p = pi(s);

    for(int i = 0, j = 0; i < t.size(); i++){

        
        while(j > 0 && s[j] != t[i]) j = p[j-1]; // desloca a janela de acordo com a tabela pi
        
        if(s[j] == t[i]) j++;

        if(j == s.size()) return i-j+1; // matching
    }

    return -1;
}

signed main(){

    int n;
    string s, target;


    cin >> n;

    cin >> s; cin >> target;


    string s2 = s + s;


    int r = kmp(s2, target);

    if(r == -1) cout << r; 
    else cout << n - r;
    
}