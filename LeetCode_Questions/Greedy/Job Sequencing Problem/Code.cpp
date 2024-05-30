/*
Problem Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1 
Time Complexity: O(n*logn + n*maxDeadLine)
Space Complexity: O(maxDeadLine)
*/
class Solution 
{
    public:
    
    static bool compare(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compare);
        
        int maxDeadLine = 0;
        for (int i=0; i<n; i++) maxDeadLine = max(maxDeadLine, arr[i].dead);
        
        int has[maxDeadLine] = {0};
        int profit=0, jobs=0;
        
        for(int i=0; i<n; i++)
        {
            for (int index = arr[i].dead-1; index>=0; index--)
            {
                if (has[index]==0)
                {
                    has[index] = 1;
                    profit += arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        
        return {jobs,profit};
    } 
};
