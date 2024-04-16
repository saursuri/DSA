#include<bits/stdc++.h>
using namespace std;

// ============================================================================
class Solution{
  typedef pair<int,char> iPair;

  public:
    vector<vector<pair<int,char>>> removeDuplicateHouses(vector<vector<int>> &neighborhoods, 
    vector<vector<char>> &colors)
    {
      // Get Total no of neighborhoods
      int m = neighborhoods.size();
      // Get Total no of houses in heighborhoods
      int n = neighborhoods[0].size();

      // List to store houses in sorted order
      vector<iPair>sortedList;

      // For each neighborhood in neighborhoods
      for (int neighborhood=0; neighborhood<m; neighborhood++)
      {
        // For each house in neighborhood
        for(int house=0; house<n; house++)
        {
          // Push houses to SortedList along with colors
          sortedList.push_back({neighborhoods[neighborhood][house],
          colors[neighborhood][house]});
        }
      }
      
      // Sort the list
      // {{1,'b'},{2,'g'},{4,'b'},{4,'w'},{4,'x'},{5,'y'},{6,'c'},{8,'r'},{9,'b'}}
      sort(sortedList.begin(),sortedList.end());

      // List of Lists to store the ans
      vector<vector<iPair>> ans(m);

      // For each neighborhood in neighborhoods
      for (int neighborhood=0; neighborhood<m; neighborhood++)
      {
        // For each house in neighborhood
        for(int house=0; house<n; house++)
        {
          // Update the ans
          // ans[0] --> {1,'b'}, {4,'w'}, {6,'c'}
          // ans[1] --> {2,'g'}, {4,'x'}, {8,'r'}
          // ans[2] --> {4,'b'}, {5,'y'}, {9,'b'}
          ans[house].push_back(sortedList[neighborhood*n + house]);
        }
      }

      return ans;
    }
};
// ============================================================================


/*Helper function to Print the answer*/
void printer(vector<vector<pair<int,char>>> &neighborhoods)
{
  // For each neighborhood in neighborhoods
  for (auto neighborhood: neighborhoods)
  {
    // For each house in neighborhood
    for(auto house: neighborhood)
    {
      // Print the House No and House Color
      cout << house.first << house.second << " ";
    }

    cout << endl;
  }
}


int main(){

  // All houses are painted with the colors 
  vector<vector<int>> neighborhoods = { {8, 2, 9}, {4, 6, 4}, {4, 5, 1} };
  vector<vector<char>> colors = {{'r','g','b'},{'w','c','b'},{'x','y','b'}};

  // Create the Solution object
  Solution s;

  // Call the houseColor function and store the ans
  vector<vector<pair<int,char>>> ans = s.removeDuplicateHouses(neighborhoods, colors);

  // Call the helper to store the ans
  printer(ans);

}