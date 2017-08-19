class UF {
private:
    int *id;
    int *sz;
    int count;

public:
    // Constructor
    UF(int n) {
        id = new int[n];
        sz = new int[n];
        for (int i=0; i<n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // Deconstructor
    ~UF() {
        delete id;
        delete sz;
    }

    int find(int p) {
        while (id[p] != p) {
            id[p] = id[id[p]];  // 把父节点设为它的爷爷节点，压缩路径
            p = id[p];  
        }

        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void Union(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if (rootp == rootq) return;
        if (sz[rootp] > sz[rootq]) {  //较小尺寸的树连接到较大的树上
            id[rootq] = rootp;
            sz[rootp] += sz[rootq];
        }
        else {
            id[rootp] = rootq;
            sz[rootq] += sz[rootp];
        }
    }


};

void solve(vector<vector<char> >& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    if (n == 0) return;

    UF uf(m*n + 1);
    int dummy = m*n;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if ((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
                uf.Union(i*n+j, dummy);
            else if (board[i][j] == 'O') {
                if (board[i-1][j] == 'O')
                   uf. Union((i-1)*n+j, i*n+j);
                if (board[i+1][j] == 'O')
                    uf.Union((i+1)*n+j, i*n+j);
                if (board[i][j-1] == 'O')
                    uf.Union(i*n+j-1, i*n+j);
                if (board[i][j+1] == 'O')
                    uf.Union(i*n+j+1, i*n+j);
            }
        }
    }

    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
            if (board[i][j] == 'O' && !uf.connected(i*n+j, dummy))
                board[i][j] = 'X';
        }
}