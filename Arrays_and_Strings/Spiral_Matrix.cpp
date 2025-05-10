/*EXERCISE TEXT
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    short int left = 0;
    short int right = matrix[0].size();
    short int top = 0;
    short int bottom = matrix.size();

    while (left < right && top < bottom){

        //Get all elements from top row and make top row to be next row
        for (int i = left; i < right; i++)
            result.push_back(matrix[top][i]);
        top++;

        //Get all elements from right column and make right column to be next column
        for (int i = top; i < bottom; i++)
            result.push_back(matrix[i][right - 1]);
        right--;
        
        if (!(left < right && top < bottom))
            break;

        //Get all elements from bottom row and make bottom row to be next row
        for (int i = right - 1; i > left - 1; i--)
            result.push_back(matrix[bottom - 1][i]);
        bottom--;

        //Get all elements from left column and make left column to be next column
        for (int i = bottom - 1; i > top - 1; i--)
            result.push_back(matrix[i][left]);
        left++;
    }

  return result;
}


int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i : spiralOrder(matrix))
        cout << i << " ";
}
