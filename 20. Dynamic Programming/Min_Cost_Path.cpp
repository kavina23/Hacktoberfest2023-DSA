/*
Given a cost matrix cost[][] and a position (M, N) in cost[][], write a function that returns cost of minimum cost path to reach (M, N) from (0, 0). 
Each cell of the matrix represents a cost to traverse through that cell. The total cost of a path to reach (M, N) is the sum of all the costs on that path 
(including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), 
cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed. 


Follow the below steps to solve the problem:

# Calculate prefix sum for the first row and first column in ‘cost’ array as there is only one way to reach any cell in the first row or column
# Run a nested for loop for i [1, M-1] and j [1, N-1]
   # Set cost[i][j] equal to minimum of (cost[i-1][j-1], cost[i-1][j], cost[i][j-1]) + cost[i][j]
# Return cost[M-1][N-1]


Below is the implementation of the above approach:
*/


#include <bits/stdc++.h>
using namespace std;
 
#define row 3
#define col 3
 
int minCost(int cost[row][col])
{
 
    // for 1st column
    for (int i = 1; i < row; i++)
        cost[i][0] += cost[i - 1][0];
 
    // for 1st row
    for (int j = 1; j < col; j++)
        cost[0][j] += cost[0][j - 1];
 
    // for rest of the 2d matrix
    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
            cost[i][j] += min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
 
    // returning the value in last cell
    return cost[row - 1][col - 1];
}
 

int main(int argc, char const* argv[])
{
    int cost[row][col]
        = { { 1, 2, 7 }, { 4, 6, 2 }, { 1, 5, 3 } };
 
    cout << minCost(cost) << endl;
    return 0;
}
