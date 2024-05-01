//
//  main.cpp
//  LevenshteinDistance
//
//  Created by Woo Sung Jahng on 2024/05/01.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    string S, T;
    
    S = "abcd";
    T = "axyd";
    
    vector<vector<int>> y(S.size() + 1, vector<int>(T.size() + 1));
    
    int i, j;
    for (i = 0; i <= S.size(); i++) y[i][0] = i;
    for (j = 0; j <= T.size(); j++) y[0][j] = j;
    
    for (i = 1; i <= S.size(); i++) {
        for (j = 1; j <= T.size(); j++) {
            if (S[i - 1] == T[j - 1]) {
                y[i][j] = min({y[i-1][j-1], y[i-1][j]+1, y[i][j-1]+1});
            } else {
                y[i][j] = min({y[i-1][j-1]+1, y[i-1][j]+1, y[i][j-1]+1});
            }
        }
    }
    
    cout << y[S.size()][T.size()] << endl;
}
