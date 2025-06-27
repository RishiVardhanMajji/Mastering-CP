#include <iostream>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<long long, long long> freq;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            long long r = (k - (x % k)) % k;
            if (r != 0) freq[r]++;
        }

        long long ans = 0;
        for (auto [r, count] : freq) {
            // Each repeat of same remainder needs to wait k more
            long long moves = (count - 1) * (long long)k + r + 1;
            ans = max(ans, moves);
        }
        cout << ans << "\n";
    }
    return 0;
}

/* 
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n,k;
        cin >> n >> k;
        map<int,int>freq;
        multiset<int>s;
        int maxfreq=0;
        int y=0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        for(auto x:s){
            freq[x%k]++;
            if(freq[x%k] > maxfreq and (x%k !=0)){
                maxfreq=freq[x%k];
                y=x%k;
            }
        }
        if (y != 0)cout << ((k*maxfreq) - y +1) << "\n";
        else cout << "0" << "\n";
    }
}
*/