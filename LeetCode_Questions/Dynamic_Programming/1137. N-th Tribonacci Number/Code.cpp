/*
Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        
        int first = 0;
        int second = 1;
        int third = 1;

        int next;
        for(int i=3; i<=n; i++)
        {
            next = first + second + third;
            first = second;
            second = third;
            third = next;
        }

        return next;
    }
};
