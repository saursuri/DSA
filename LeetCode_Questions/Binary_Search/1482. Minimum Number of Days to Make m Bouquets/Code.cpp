/*
Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19
Time Complexity: O(nlog(max(no of bouquets)))
Space Complexity: O(1)
*/

class Solution {
    bool canMakeBouquets(int days, vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        int boq = 0, flowers = 0;
        for (int indx = 0; indx < n; indx++)
        {
            if (days >= bloomDay[indx])
            {
                flowers++;

                if (flowers % k == 0)
                    boq++;
            }
            else
            {
                flowers = 0;
            }

        }

        if (boq >= m) return true;
        else return false;

    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (m > n/k) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if (canMakeBouquets(mid, bloomDay, m, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};
