#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string arr;
    cin >> arr;

    int count[3] = {0, 0, 0};
    for(char c : arr) count[c - '0']++;

    int target = n / 3;

    for(int i = 0; i < n; i++) {
        int d = arr[i] - '0';
        for(int k = 0; k < d; k++) {
            if(count[k] < target && count[d] > target) {
                count[d]--;
                count[k]++;
                arr[i] = k + '0';
                break;
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        int d = arr[i] - '0';
        for(int k = 2; k > d; k--) {
            if(count[k] < target && count[d] > target) {
                count[d]--;
                count[k]++;
                arr[i] = k + '0';
                break;
            }
        }
    }

    cout << arr << "\n";
}
