#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y;
        cin >> x >> y;
        if(x%2 == y%2)cout << "-1" << "\n";
    }
}