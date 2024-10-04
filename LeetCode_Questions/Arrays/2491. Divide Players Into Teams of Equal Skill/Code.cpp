/*
Problem Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        long long cumSum = 0;
        for (int s : skill) {
            cumSum += s;
        }
        int n = skill.size();
        
        if (n == 2) return skill[0] * skill[1];

        long long totalPairSum = 2 * cumSum;
        if (totalPairSum % n != 0) return -1;

        long long targetSum = totalPairSum / n;
        std::unordered_map<int, int> skillCount;
        long long ans = 0;

        for (int s : skill) {
            int target = targetSum - s;
            if (skillCount[target] > 0) {
                ans += target * s;
                skillCount[target]--;
            } else {
                skillCount[s]++;
            }
        }
        
        for (auto &it :skillCount)
        {
            if (it.second > 0 ) return -1;
        }

        return  ans;
    }
};
