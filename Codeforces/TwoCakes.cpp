#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int ,pair<int ,int>>shop;

    for(int i=0;i<2*n;i++){
        int a;
        cin >> a;
        if(shop[a].first ==0){
            shop[a].first=i;
        }else{
            shop[a].second=i;
        }
    }
    long long sum1=0;
    long long sum2=0;
    int position1=0;
    int position2=0;
    for(int i=0;i<n;i++){
        if(abs(shop[i+1].first-position1)+abs(shop[i+1].second-position2) > abs(shop[i+1].first-position2)+abs(shop[i+1].second-position1)){
            sum1+= abs(shop[i+1].second-position1);
            sum2+=abs(shop[i+1].first-position2);
            position1=shop[i+1].second;
            position2=shop[i+1].first;
        }else{
            sum1+= abs(shop[i+1].first-position1);
            sum2+= abs(shop[i+1].second-position2);
            position1=shop[i+1].first;
            position2=shop[i+1].second;
        }
    }

    cout << sum1+sum2;
    
}