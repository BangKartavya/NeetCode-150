class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();

            int s = 0;
            int e = n * m - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                int x = mid / n;
                int y = mid % n;

                if(matrix[x][y] == target) return true;
                else if(matrix[x][y] < target) s = mid + 1;
                else e = mid - 1;
            }

            return false;
        }
};
