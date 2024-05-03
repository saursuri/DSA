/*
Problem Link: https://leetcode.com/problems/maximal-rectangle/description/
Time Complexity: O(n^2)
Space Complexity: O(n)
*/


class Solution {
public:
    int areaOfHisto(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width = i-st.top()-1;
                maxArea = max(maxArea,width*height);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(n,0);

        // For every row
        for(int row=0; row<m; row++)
        {
            // For every col
            for(int col=0; col<n; col++)
            {
                if (matrix[row][col]=='1') heights[col]++;
                else heights[col] = 0;
            }
            int area = areaOfHisto(heights);
            maxArea = max(maxArea,area);
            
        }    
        return maxArea;
    
    }
};
