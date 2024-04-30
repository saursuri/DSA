/*
Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Stack to store index
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<=n; i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {   
                // Calculate height 
                int height = heights[st.top()];
                st.pop();

                int width;
                // If stack is empty that means there is no leftMax 

                if(st.empty()) width = i;
                // i is the rightMin height index and stack top will
                // have leftMin height index
                // So width 
                else width = i - st.top() - 1;

                maxArea = max(maxArea,width*height);
            }
            st.push(i);
        
        }
        return maxArea;
    }
};
