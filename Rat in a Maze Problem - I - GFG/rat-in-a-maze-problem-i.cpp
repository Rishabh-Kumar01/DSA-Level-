//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void rec(int row, int col, vector<vector<int>> &m, int n, 
    vector<vector<int>> &visited, vector<string> &res, string temp){
        if(row == n-1 && col == n-1){
            res.push_back(temp);
            return;
        }
        
        
        if(row+1<n && m[row+1][col] == 1 && !visited[row+1][col]){
            visited[row][col] = 1;
            rec(row+1, col, m, n, visited, res,temp + 'D');
            visited[row][col] = 0;
        }
        
        if(col-1>=0 && m[row][col-1] == 1 && !visited[row][col-1]){
            visited[row][col] = 1;
            rec(row, col-1, m, n, visited, res,temp + 'L');
            visited[row][col] = 0;
        }
        
        if(row-1>=0 && m[row-1][col] == 1 && !visited[row-1][col]){
            visited[row][col] = 1;
            rec(row-1, col, m, n, visited, res,temp + 'U');
            visited[row][col] = 0;
        }
        
        if(col+1<n && m[row][col+1] == 1 && !visited[row][col+1]){
            visited[row][col] = 1;
            rec(row, col+1, m, n, visited, res,temp + 'R');
            visited[row][col] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n, vector<int> (n,0));
        vector<string> res;
        if(m[0][0] == 1) rec(0,0,m,n,visited, res, "");
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends