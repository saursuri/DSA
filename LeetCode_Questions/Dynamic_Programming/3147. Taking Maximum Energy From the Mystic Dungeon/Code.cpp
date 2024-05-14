/*
Problem Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
class Solution {
public:
    int maxEnergyUtil(int index, vector<int>& energy, int k,vector<int> &dp)
    {
        int n = energy.size();
        
        if (index>=n) return 0;
        
        if (dp[index]!=-1) return dp[index];
        
        // Absorb energy at index + k
        return dp[index] = energy[index] + maxEnergyUtil(index+k,energy,k,dp);
    }
    
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        
        int maxEnergy = INT_MIN;
        vector<int> dp(n+1,-1);
        for(int i=0; i<n; i++)
        {   
            maxEnergy = max(maxEnergy, energy[i] + maxEnergyUtil(i+k,energy,k,dp));
        }
        return maxEnergy;
    }
};
