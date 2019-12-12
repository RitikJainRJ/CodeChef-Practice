/*
The Little Elephant from the Zoo of Lviv currently is on the military mission.
There are N enemy buildings placed in a row and numbered from left to right strating from 0.
Each building i (except the first and the last) has exactly two adjacent buildings with indices i-1 and i+1.
The first and the last buildings have just a single adjacent building.
Some of the buildings contain bombs. When bomb explodes in some building it destroys it and all adjacent
to it buildings.
You are given the string S of length N, where Si is 1 if the i-th building contains bomb, 0 otherwise.
Find for the Little Elephant the number of buildings that will not be destroyed after all bombs explode.
Please note that all bombs explode simultaneously.
*/
#include<bits/stdc++.h>
using namespace std;

int remainingBuilding(string, int);

int main(void){
    int t, n;
    string str;

    cin >> t;
    while(t--){
        cin >> n >> str;
        cout << remainingBuilding(str, n) << endl;
    }
    return 0;
}

int remainingBuilding(string str, int n){
    int arr[n], res[n];

    memset(res, 0, sizeof(res));
    for(int i = 0; i < str.length(); i++)
        arr[i] = str[i] - '0';
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            res[i] = 1;
            if(i - 1 >= 0)
                res[i - 1] = 1;
            if(i + 1 < n)
                res[i + 1] = 1;
        }
    }
    return count(res, res + n, 0);
}
