/*
Problem Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2024-10-25
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());

        vector<string> result;
        result.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++)
        {
            string currentFolder = folder[i];
            string prevFolder = result.back();
            prevFolder += '/';
            
            if (currentFolder.find(prevFolder) != 0)
            {
                result.push_back(currentFolder);
            }
        }

        return result;
    }
};
