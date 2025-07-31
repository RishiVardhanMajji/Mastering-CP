#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> seq1(n);
    vector<int> seq2(m);

    for(int i = 0; i < n; i++) cin >> seq1[i];
    for(int i = 0; i < m; i++) cin >> seq2[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(seq1[i - 1] == seq2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(seq1[i - 1] == seq2[j - 1]){
            lcs.push_back(seq1[i - 1]);
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs.size() << "\n";
    for(int val : lcs){
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
