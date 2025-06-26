//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    int searchInRow(vector<vector<int>> mat,int tar,int row){
        int m=mat[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mat[row][mid]==tar) return true;
            else if(tar>mat[row][mid]) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int sr=0,er=n-1;
        while(sr<=er){
            int mr=sr+(er-sr)/2;
            if(target>=matrix[mr][0] && target<=matrix[mr][m-1]) 
                return searchInRow(matrix,target,mr);
            else if(target>=matrix[mr][m-1])
                sr=mr+1;
            else er=mr-1;
        }
        return 0;
    }
};