/*
As New Year is approaching, Salik is studying functions in order to sharpen his math skills.
Instead of regular functions, he is studying a strange function F which operates on non-negative integers.
The value of F(A) is obtained by the following process:

    Compute the sum of digits of A; let's denote this sum by S.
    If S is a single-digit integer, then F(A) = S.
    Otherwise, F(A) = F(S).

It's guaranteed that this process correctly defines the function F.

Since this problem was pretty straightforward, he invented a new problem:
Given two integers A and N, compute F(AN). Can you help him solve this task?
*/
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

string multiplyString(string, string);
string divideString(string, int);
string powString(string, string);
void strangeFunction(string, string);

int main(void){
    int t;
    string a, n;

    cin >> t;
    while(t--){
        cin >> a >> n;
        strangeFunction(a, n);
        cout << endl;
    }
    return 0;
}

string multiplyString(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    vector<int> res(l1 + l2, 0);
    int p = 0, k;
    string str;

    for(int i = l2 - 1; i >= 0; i--){
        int c = 0;
        int q = 0;
        for(int j = l1 - 1; j >= 0; j--){
            int temp = (s2[i] - '0') * (s1[j] - '0') + res[p + q] + c;
            res[p + q] = temp % 10;
            c = temp / 10;
            q++;
        }
        if(c > 0)
            res[p + q] += c;
        p++;
    }
    for(k = res.size() - 1; k >= 0; k--)
        if(res[k] != 0)
            break;
    for(int i = k; i >= 0; i--){
        char temp = res[i] + '0';
        str = str + temp;
    }
    return str;
}

string divideString(string str, int a){
    int i = 0;
    string res;

    int temp = 0;
    while(temp < a){
        temp = (temp * 10) + (str[i] - '0');
        i++;
    }
    while(i <= str.length()){
        int p = (temp / a);
        res.push_back(p + '0');
        temp = (temp % a) * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

string powString(string a, string b){
    if(b.empty())
        return "1";
    if(b.length() == 1 && b[0] == '1')
        return a;

    string temp = powString(a, divideString(b, 2));
    if(((b[b.length() - 1]) - '0') % 2 != 0)
        return multiplyString(a, multiplyString(temp, temp));
    else
        return multiplyString(temp, temp);
}

void strangeFunction(string a, string b){
    string res = powString(a, b);
    ll sum;

    while(res.length() > 1){
        sum = 0;
        for(int i = 0; i < res.length(); i++)
            sum += (res[i] - '0');
        res = to_string(sum);
    }
    cout << res;
}
