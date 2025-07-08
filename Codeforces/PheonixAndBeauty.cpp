#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> uniq;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            uniq.insert(a[i]);
        }

        if (uniq.size() > k) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> base;
        for (int val : uniq)
            base.push_back(val);
        while (base.size() < k)
            base.push_back(1); // Add 1s to pad if needed

        vector<int> res;
        while ((int)res.size() < n * k)
            res.insert(res.end(), base.begin(), base.end());

        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i)
            cout << res[i] << " ";
        cout << '\n';
    }
    return 0;
}


/*#include <bits/stdc++.h>

using namespace std;

void beautify(int& n,int& k,vector<int>& inp,int& count){
    if(k<count)cout << "-1" << "\n";
    else{
        for(int i=0;i<n-k;i++){
            if(inp[i] != inp[i+k]){
                inp.insert(inp.begin()+i+k,inp[i]);
                n++;
            }
        }
        cout << n << "\n";
        for(int i=0;i<n;i++){
            cout << inp[i] << " ";
        }
    }

}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int k,n;
        cin >> n >> k;
        vector<int>inp(n,0);
        set<int>numbers={0};
        int count=0;
        for(int i=0;i<n;i++){
            cin >> inp[i];
            if(numbers.find(inp[i]) == numbers.end()){
                numbers.insert(inp[i]);
                count++;
            }
        }
        beautify(n,k,inp,count);
    }
}
 */