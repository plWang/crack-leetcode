vector<int> getRow(int k) {
    if (k < 0) return vector<int>();
    vector<int> row(k+1, 0);
    row[0] = 1;
    for (int i=0; i<=k; i++) {
        for (int j=i; j>=1; j--) {
            row[j] = row[j] + row[j-1];
        }
    }

    return row;
}