/*
Problem Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02
Time Complexity: O(n*m)
Space Complexity: O(1)
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int m = searchWord.size();
        int indx = 0, ans=1;

        while(indx<n)
        {
            if (indx != 0 && sentence[indx-1] != ' ') 
            {   
                indx++;
                continue;
            }
            
            int i=indx, j=0;
            while(sentence[i] != ' ' && i<n && j<m)
            {
                if (sentence[i] != searchWord[j])
                    break;
                
                i++,j++;
            }
            
            if (j==m) return ans;

            ans++;
            indx++;
        }

        return -1;
    }
};
