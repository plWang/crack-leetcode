void backtrack(vector<string>& solution, string& tempsol, int& left, int& right, int n) {
    if (left > n || right > n || left < right) return;
    if (left == n && right == n) {
        solution.push_back(tempsol);
        return;
    }

    tempsol.push_back('(');
    left++;
    backtrack(solution, tempsol, left, right, n);
    left--;
    tempsol.pop_back();

    if (left > right) {
        tempsol.push_back(')');
        right++;
        backtrack(solution, tempsol, left, right, n);
        right--;
        tempsol.pop_back();
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> solution;
    string tempsol = "";
    int left=0, right=0;
    backtrack(solution, tempsol, left, right, n);

    return solution;
}