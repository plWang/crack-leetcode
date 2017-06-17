void backtrack(vector<vector<int> >& solutions, vector<int>& tempsol, int n, int k, int used, int begin) {
    if (used == k) {
        solutions.push_back(tempsol);
        return;
    }

    for (int i=begin; i<=n; i++) {
        tempsol.push_back(i);
        used++;
        backtrack(solutions, tempsol, n, k, used, i+1);
        used--;
        tempsol.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > solutions;
    vector<int> tempsol;
    int used = 0;
    backtrack(solutions, tempsol, n, k, used, 1);

    return solutions;
}