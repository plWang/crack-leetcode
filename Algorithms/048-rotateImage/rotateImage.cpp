void rotate(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();
    if (n == 0) return;

    for (int i=0; i<m/2; i++) {
        for (int j=0; j<n; j++) {
            swap(matrix[i][j], matrix[m-1-i][j]);  // reverse up and down
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}