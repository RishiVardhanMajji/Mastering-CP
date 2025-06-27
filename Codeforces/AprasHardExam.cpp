#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x=1378;

    x%=10;
    int ans=1;
    while(n>0){
        if(n & 1)ans=ans*x % 10;
        x=x*x %10;
        n>>=1;
    }
    cout << ans;
}