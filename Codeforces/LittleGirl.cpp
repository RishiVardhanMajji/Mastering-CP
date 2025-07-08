#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> input(n);
    vector<int> freq(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        freq[a - 1]++;
        if (b < n) freq[b]--;
    }
    for (int i = 1; i < n; i++) {
        freq[i] += freq[i - 1];
    }

    freq.pop_back();

    sort(input.begin(), input.end());
    sort(freq.begin(), freq.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * input[i] * freq[i];
    }

    cout << ans << "\n";
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int>input(n,0);
    vector<int> maximise(n,0);
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a>>b;
        for(int i=a;i<=b;i++){
            maximise[i-1]++;
        }
    }
    sort(maximise.begin(),maximise.end());
    sort(input.begin(),input.end());
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+= (input[n-i-1])*(maximise[n-i-1]);
    }
    cout << ans << "\n";
}
*/