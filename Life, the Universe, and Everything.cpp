#include<bits/stdc++.h>
using namespace std;

int main(void){
    int temp, flag = 1;

    while(flag){
       cin >> temp;
       if(temp == 42)
            flag = 0;
       if(flag == 1)
            cout << temp << endl;
    }
    return 0;
}
