/*
Chef is practising his typing skills since his current typing speed is very low.
He uses a training application that displays some words one by one for Chef to type.

When typing a word, Chef takes 0.2 seconds to type the first character; for each other character of this word,
he takes 0.2 seconds to type this character if it is written with a different hand than the previous character,
 or 0.4 seconds if it is written with the same hand. The time taken to type a word is the sum of times taken
 to type all of its characters. However, if a word has already appeared during practice, Chef can type it in
 half the time it took him to type this word for the first time.

Currently, Chef is practising in easy mode, which only uses words that consists of characters 'd', 'f', 'j'
and 'k'. The characters 'd' and 'f' are written using the left hand, while the characters 'j' and 'k' are
written using the right hand.
*/
#include<bits/stdc++.h>
using namespace std;

int chefTime(int);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << chefTime(n) << endl;
    }
    return 0;
}

int chefTime(int n){
    unordered_map<string, int> um;
    unordered_map<char, int> temp;
    string str;
    int res = 0;

    temp['d'] = 0;
    temp['f'] = 0;
    temp['j'] = 1;
    temp['k'] = 1;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(um.find(str) == um.end()){
            int t = 2;
            for(int j = 1; j < str.length(); j++){
                char ch1 = str[j], ch2 = str[j - 1];
                if(temp[ch1] == temp[ch2])
                    t += 4;
                else
                    t += 2;
            }
            res += t;
            um[str] = t;
        }
        else{
            res += (um.find(str)->second / 2);
        }
    }
    return res;
}
