/*
n Ciel's restaurant, a waiter is training. Since the waiter isn't good at arithmetic, sometimes he gives
guests wrong change. Ciel gives him a simple problem. What is A-B (A minus B) ?
Surprisingly, his answer is wrong. To be more precise, his answer has exactly one wrong digit.
Can you imagine this? Can you make the same mistake in this problem?
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, res, n;
    string temp;

    cin >> a >> b;
    res = a - b;
    temp = to_string(res);
    n = temp.length();
    if(temp[n - 1] == '9')
        temp[n - 1] = temp[n - 1] - 1;
    else
        temp[n - 1] = temp[n - 1] + 1;
    cout << temp << endl;
    return 0;
}
