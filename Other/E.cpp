#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>array(n,0);

    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    unordered_map<int,vector<int>>pos;

    for(int i=0;i<n;i++){
        pos[array[i]].push_back(i);
    }

    while(m--){
        int l,r,x;
        cin >> l >> r >> x;
        l--;
        r--;

        vector<int>& p=pos[x];
        
        auto it=lower_bound(p.begin(),p.end(),l);

        if (it == p.end() || *it > r)cout << l+1<< "\n";
        else {
            if (array[l] != x) cout << l+1 << "\n";
            else if (array[r] != x) cout << r+1 << "\n";
            else {
                bool found = false;
                for (int i = l + 1; i < r; ++i) {
                    if (array[i] != x) {
                        cout << i+1 << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << -1 << "\n";
            }
        }
    }
}