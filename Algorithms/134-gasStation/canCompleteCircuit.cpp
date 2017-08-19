int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = gas.size()-1, end = 0;    //起点设为数组末尾的点，终点设为第一个点，避免了从最后一个点跳转到第一个点
    int sum = 0;
    sum += gas[start] - cost[start];
    while (start > end) {
        if (sum >= 0) {  // can reach end
            sum += gas[end] - cost[end];
            end++;        // 向后移动
        }
        else {           // can not reach end
            start--;     // 出发点向前移动一站
            sum += gas[start] - cost[start];
        }
    }

    return (sum>0)?start:-1;
}