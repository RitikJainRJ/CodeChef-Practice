#include<bits/stdc++.h>
using namespace std;

int goodPrefix(string, int, int);

int main(){
    int t, k, x;
    string str;

    cin >> t;
    while(t--){
        cin >> str >> k >> x;
        cout << goodPrefix(str, k, x) << endl;
    }
    return 0;
}

int goodPrefix(string str, int k, int x){
    int hash_str[256] = {0}, count = 0;

    for(int i = 0; i < str.length(); i++){
        hash_str[str[i]]++;
        if(hash_str[str[i]] <= x)
            count++;
        else{
            if(k == 0)
                break;
            k--;
        }
    }
    return count;
}
