#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>>vec;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end());
    long long sum=0;
    long long present=0;
    for(auto &p:vec){
        present+= p.first;
        sum+= p.second- present;
    }
    cout << sum;

}