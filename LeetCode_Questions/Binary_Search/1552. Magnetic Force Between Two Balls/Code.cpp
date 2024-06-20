/* 
Same Question as Aggressive Cows
Problem Link: https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
class Solution {
public:
    bool canPlace(int dis,int m,vector<int> &position)
    {   
        int n = position.size();
        
        // Can place 1 cow at 0th index
        int ballsCount = 1, ballsInBasket = position[0];
        
        for(int i=1; i<n;i++)
        {
            // Check if can place ball at ith basket keeping min dis
            if (position[i] - ballsInBasket >= dis)
            {
                ballsCount++;
                ballsInBasket = position[i];
            }
            
            // If ballsCount becomes equal to the given balls count --> return true
            if (ballsCount==m) return true;
        }
        
        return false;
    }
    
    int maxDistance(vector<int> &position, int m) {
        int n = position.size();
        // Sorting the stalls, since min distance will be between 2 adjacent cows
        sort(position.begin(), position.end());
        
        int low=1, high = position[n-1] - position[0];
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if (canPlace(mid,m,position))
            {
                // Try to find a max value
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return high;
    }
};
