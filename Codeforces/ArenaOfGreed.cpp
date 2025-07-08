#include <bits/stdc++.h>

using namespace std;

void game(int a){
    long long ans=0;
    while(a){
        if(a==4){
            ans+=3;
            break;
        }else if(a%4 ==0){
            ans+=1;
            a-=2;
        }else if(a%4 ==2){
            ans+=a/2;
            a= (a/2)-1;
        }else{
            ans+=1;
            a=a-1-(a-1)/2;
        }
    }
    cout << ans<< "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a;
        cin >> a;
        game(a);
    }
}