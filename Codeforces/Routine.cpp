#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >>d;

    int x=gcd(a*d,b*c);

    int p,q=0;

    if(a*d > b*c){
        p=(a*d -b*c)/x;
        q=(a*d)/x;
    }else{
        p=(b*c-a*d)/x;
        q=(b*c)/x;
        
    }
    cout << p << "/" << q << "\n";

}