/*
Problem Link: https://leetcode.com/problems/my-calendar-ii/description/
Time Complexity: O(n)
Space Complexity: O(n)
*/

class MyCalendarTwo {
    vector<pair<int,int>> intscns;
    vector<pair<int,int>> dintscns; 
public:
    MyCalendarTwo() {
       
    }
    
    bool book(int start, int end) {
        // Check for double intersections
        for (auto &it: dintscns)
        {
            if (start < it.second && end > it.first)
                return false;
            
        }

        // Check for single intersections
        for (auto &itr: intscns)
        {
            if (start < itr.second && end > itr.first)
            {
                int first = max(start, itr.first);
                int second = min(end, itr.second);
                dintscns.push_back({first, second});
            }

        }

        intscns.push_back({start, end});

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
