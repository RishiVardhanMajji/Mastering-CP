#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    cout << vec[(n - 1) / 2] << '\n';

}
