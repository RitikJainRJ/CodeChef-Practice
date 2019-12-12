#include<iostream>
using namespace std;

string solve();

int main(void){
    int t;

    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}

string solve(){
    int x, y, k, n;
    int temp, flag = 0;

    cin >> x >> y >> k >> n;
    temp = x - y;
    for(int i = 0; i < n; i++){
        int p, c;
        cin >> p >> c;
        if(c <= k && p >= temp)
            flag = 1;
    }
    if(flag == 1)
        return "LuckyChef";
    else
        return "UnluckyChef";
}
