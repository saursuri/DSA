/*
Problem Link: https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26
Time Complexity: O(N)
Space Complexity: O(N)
*/

class MyCalendar {
vector<pair<int,int>> data_struct;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &it: data_struct)
        {
            if (start < it.second && end > it.first)
                return false;
        }

        data_struct.push_back({start, end});
        return true;
    }
};
