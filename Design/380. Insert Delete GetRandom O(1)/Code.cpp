/*
Problem Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
Time ComplexitY: O(1)
Space Complexity: O(no of Elements inserted but not removed)
*/
class RandomizedSet {
    vector<int> indexItemMap;
    unordered_map<int, int> itemIndexMap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if (itemIndexMap.count(val))
            return false;
        
        indexItemMap.push_back(val);
        itemIndexMap.insert({val, indexItemMap.size()-1});

        return true; 
    }
    
    bool remove(int val) {
        
        if(!itemIndexMap.count(val))
            return false;

        int index = itemIndexMap[val];
        int lastIndex = indexItemMap.size()-1;

        swap(indexItemMap[index], indexItemMap[lastIndex]);
        indexItemMap.pop_back();

        itemIndexMap[indexItemMap[index]] = index;
        itemIndexMap.erase(val);
        
        return true;

    }
    
    int getRandom() {
        int n = indexItemMap.size();
        int index = rand()%n;

        return indexItemMap[index];

    }
};
