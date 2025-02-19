//COMPLETE SEARCH WITH RECURSION (GENERATING PERMUTATIONS)
#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int len;
string permutation;
vector<bool> chosen(false);

set<string> p;

void print_set(set<string> &s){
    set<string>::iterator it;
    
    for(it = s.begin(); it != s.end(); it++){
        
        cout << *it << endl;
    
        
    }
}

void perm(){
    if(permutation.size() == len){
        
        p.insert(permutation); // permutação completa
    
    }else{
        for(int i = 0; i < len; i++){
            if(chosen[i]) continue; // esse elemento já está na permutação atual
            else{
                chosen[i] = true;
                permutation.push_back(s[i]); // adiciona elemento na permutação atual
                
                perm(); // completa essa permutação
                
                chosen[i] = false; // retira elemento da permutação na volta da chamada recursiva
                permutation.pop_back();   
            }
        }
    }
}



signed main()
{
    cin >> s;
    
    len = s.size();
    
    sort(s.begin(), s.end());
    
    chosen.resize(len);
    
    perm();
    
    cout << p.size() << endl;
    
    print_set(p);
}
