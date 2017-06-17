// The idea is simple. G(i) = i^(i>>1)

vector<int> grayCode(int n) {
    vector<int> result;
    for (int i=0; i< 1<<n; i++) {
        result.push_back(i ^ i>>1);
    }

    return result;
}