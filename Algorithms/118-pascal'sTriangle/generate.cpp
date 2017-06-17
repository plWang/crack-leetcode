vector<vector<int> > generate(int n) {
    vector<vector<int> > triangle;
    if (n == 0) return triangle;
    for (int i=0; i<n; i++) {
        vector<int> row(i+1, 0);
        for (int j=0; j<=i; j++) {
            if (j == 0 || j == i)
                row[j] = 1;
            else 
                row[j] = triangle[i-1][j-1] + triangle[i-1][j]; 
        }
        triangle.push_back(row);
    }

    return triangle;
}