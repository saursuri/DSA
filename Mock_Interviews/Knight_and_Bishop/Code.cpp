/*
Question: Given a n*n chess Board, Find min Steps required for Knight to reach end position from start position.
Also, there's Bishop present on the chess board, Place knight such that bishop can't kill the knight but Knight can 
kill the bishop.
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  private:
  void findSafePositions(vector<vector<int>> &safePositions, pair<int,int> bishopPos)
  {
    int n = safePositions.size();

    pair<int,int> currPos = bishopPos;
    
    // Upper-Left Diagnoal
    while(0<=currPos.first && 0<=currPos.second)
    {
      safePositions[currPos.first][currPos.second] = 1;
      currPos.first--;
      currPos.second--;
      
    }

    currPos = bishopPos;

    // Lower-Left Diagnoal
    while(currPos.first<n && 0<=currPos.second)
    {
      safePositions[currPos.first][currPos.second] = 1;
      currPos.first++;
      currPos.second--;
      
    }

    currPos = bishopPos;

    // Upper-Right Diagonal
    while(0<=currPos.first && currPos.second<n)
    {
      safePositions[currPos.first][currPos.second] = 1;
      currPos.first--;
      currPos.second++;
      
    }

    currPos = bishopPos;

    // Lower-Right Diagonal
    while(currPos.first<n && currPos.second<n)
    {
      safePositions[currPos.first][currPos.second] = 1;
      currPos.first++;
      currPos.second++;
      
    }

    // Bishop Position is safe, can kill it
    safePositions[bishopPos.first][bishopPos.second] = 0;

  }


  public:
    StepsToReachEnd(int chessBoardSize, pair<int,int> bishopPos, pair<int,int> knightStartPos,
    pair<int,int> knightEndPos)
    { 
      // Queue for BFS Traversal
      // To keep check Bishop is alive or not
      // vector contains 4 elements --> KnightPos, isBishopAlive, noOfSteps
      queue<vector<int>> bfsQueue;
      bfsQueue.push({knightStartPos.first, knightStartPos.second, 1, 0});

      // Positions which are unsafe for Knight to go
      // Safe positions are marked with 0 and unsafe with 1.
      vector<vector<int>> safePositions(chessBoardSize,vector<int>(chessBoardSize,0));
      findSafePositions(safePositions,bishopPos);

      // Visited array so that Knight will not go again to same position
      vector<vector<vector<int>>> visited(chessBoardSize, vector<vector<int>>(chessBoardSize, vector<int>(2,0)));

      // For Knight Traversals
      int dr[] = {1,-1,1,-1,-2,-2,2,2};
      int dc[] = {-2,-2,2,2,1,-1,1,-1};

      // Perform BFS Traversal
      while(!bfsQueue.empty())
      {
        auto qElems = bfsQueue.front();
        bfsQueue.pop();
        pair<int,int> currPos = {qElems[0],qElems[1]};
        int isBishopAlive = qElems[2];
        int steps = qElems[3];

        // If current Position becomes equal to knightEndPos, return steps
        if (currPos == knightEndPos)
        {
          return steps;
        }

        // Explore Knight Paths (Visit Neighbors)
        for(int index=0; index<8; index++)
        {
          pair<int,int> uPos = {currPos.first + dr[index], currPos.second + dc[index]};

          // Boundary Checks
          // If not visited before
          if (0<=uPos.first && uPos.first<chessBoardSize && 0<=uPos.second && uPos.second<chessBoardSize &&
          visited[uPos.first][uPos.second][isBishopAlive]==0)
          {

            // if Knight lands on Bishop position and kills bishop, all pos will be safe
            if(uPos==bishopPos)
            {
              // Mark the node as visited
              visited[uPos.first][uPos.second][isBishopAlive] = 1;
              // Update status of Bishop as Killed
              bfsQueue.push({uPos.first, uPos.second, 0, steps+1});
            }
            // If Bishop is Killed, then all positions becomes safe
            else if (!isBishopAlive)
            {
              // Mark the node as visited
              visited[uPos.first][uPos.second][isBishopAlive] = 1;
              // Increase the steps and keep the status of Bishop 
              bfsQueue.push({uPos.first, uPos.second, isBishopAlive, steps+1});
            }
            // If bishop is Alive, move only to safePositions
            else if (isBishopAlive && !safePositions[uPos.first][uPos.second])
            {
              // Mark the node as visited
              visited[uPos.first][uPos.second][isBishopAlive] = 1;
              bfsQueue.push({uPos.first, uPos.second, isBishopAlive, steps+1});
            }

          }
        }
      }

      // If Knight can't reach end position
      return -1;  

    }
};


int main(){

  int chessBoardSize;
  cout << "Enter the Chess Board Size: ";
  cin >> chessBoardSize;

  pair<int,int> bishopPos;
  cout << "Enter the Bishop Position: ";
  cin >> bishopPos.first >> bishopPos.second;

  pair<int,int> knightStartPos;
  cout << "Enter the Knight Start Position: ";
  cin >> knightStartPos.first >> knightStartPos.second;

  pair<int,int> knightEndPos;
  cout << "Enter the Knight End Position: ";
  cin >> knightEndPos.first >> knightEndPos.second;

  Solution S;
  int ans = S.StepsToReachEnd(chessBoardSize, bishopPos, knightStartPos, knightEndPos);

  cout << "Min No of Steps required to reach end position: " << ans;

  return 0;
}
