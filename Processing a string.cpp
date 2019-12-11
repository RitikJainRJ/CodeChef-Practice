/*
Given an alphanumeric string made up of digits and lower case Latin characters only, find the sum of
all the digit characters in the string.
*/

#include<iostream>
using namespace std;

int main(void){
    int t, temp;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        temp = 0;
        for(int i = 0; i < str.length(); i++){
            if('0' <= str[i] && str[i] <= '9'){
                temp += (str[i] - '0');
            }
        }
        cout << temp << endl;
    }
    return 0;
}
