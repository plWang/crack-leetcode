bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    int lo = 0, hi = m*n-1;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (matrix[mid/n][mid%n] == target) return true;
        else if (matrix[mid/n][mid%n] < target) {
            lo = mid+1;
        }
        else 
            hi = mid-1;
    }

    return false;
}