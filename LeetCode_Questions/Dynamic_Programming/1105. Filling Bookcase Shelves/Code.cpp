/*
Problem Link: https://leetcode.com/problems/filling-bookcase-shelves/?envType=daily-question&envId=2024-07-31
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
private:
    int width, dp[1001][1001];
    int solve(int indx, int remainingW, int maxH, vector<vector<int>>& books)
    {
        int n = books.size();
        // In indx exceeds the limit we keep the book
        if (indx == n) return maxH;

        if (dp[indx][remainingW] != -1) return dp[indx][remainingW];

        int bookW = books[indx][0];
        int bookH = books[indx][1];

        // Skip the shelf, then put in next shelf
        int skip = maxH + solve(indx+1, width-bookW, bookH, books);

        int keep = INT_MAX;
        if (remainingW >= bookW)
            keep = solve(indx+1, remainingW-bookW, max(maxH, bookH), books);

        return dp[indx][remainingW] = min(keep, skip);
    }   

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        width = shelfWidth;

        memset(dp, -1, sizeof(dp));
        return solve(0, shelfWidth, 0, books);
    }
};
