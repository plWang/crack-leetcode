vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    int rows = n, cols = n;
    int level = (n + 1)/2;
    
    int num = 1;
    for (int i=0; i<level; i++) {   //层数
        int col_begin = 0+i;
        int col_end = cols-i-1;
        int row_begin = 0+i;
        int row_end = rows-i-1;

        for (int j=col_begin; j<=col_end; j++)        //上
            matrix[row_begin][j] = num++; 

        for (int j=row_begin+1; j<=row_end; j++)     // 右
            matrix[j][col_end] = num++;

        for (int j=col_end-1; j>=col_begin && row_end>row_begin; j--)     // 下
            matrix[row_end][j] = num++;

        for (int j=row_end-1; j>row_begin && col_end>col_begin; j--)     // 左
            matrix[j][col_begin] = num++;
    }

    return matrix;

}