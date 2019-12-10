/*
You are given a dataset consisting of N items. Each item is a pair of a word and a boolean denoting whether
the given word is a spam word or not. We want to use this dataset for training our latest machine learning
model. Thus we want to choose some subset of this dataset as training dataset. We want to make sure that
there are no contradictions in our training set, i.e.
there shouldn't be a word included in the training set that's marked both as spam and
not-spam. For example item {"fck", 1}, and item {"fck, 0"} can't be present in the training set,
because first item says the word "fck" is a spam, whereas the second item says it is not, which is a
contradiction. Your task is to select the maximum number of items in the training set.
Note that same pair of {word, bool} can appear multiple times in input. The training set can also contain
the same pair multiple times.
*/

#include <bits/stdc++.h>
using namespace std;

int sts(int);

int main(void){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << sts(n) << endl;
    }
    return 0;
}

int sts(int n){
    int res = 0;
    unordered_map<string, vector<int>> um;
    unordered_map<string, vector<int>>::iterator it;

    for(int i = 0; i < n; i++){
        string str;
        int status;
        cin >> str >> status;
        um[str].push_back(status);
    }
    for(it = um.begin(); it != um.end(); it++){
        int count0 = 0, count1 = 0;
        for(int i = 0; i < it->second.size(); i++){
            if(it->second[i] == 0)
                count0++;
            if(it->second[i] == 1)
                count1++;
        }
        if(count0 >= count1)
            res += count0;
        else
            res += count1;
    }
    return res;
}
