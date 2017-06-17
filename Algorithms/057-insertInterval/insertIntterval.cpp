struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Solution 1: naive solution, sort and insert and merge
static bool compare(Interval a, Interval b) {
    if (a.start < b.start) return true;
    else return false;
}

vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int merge_count = 0;
    for (int i=1; i<intervals.size(); i++) {
        if (intervals[i].start <= intervals[i-1].end) {
            intervals[i].start = intervals[i-1].start;
            intervals[i].end = max(intervals[i-1].end, intervals[i].end);
            intervals.erase(intervals.begin()+i-1);
            i--;
        }
    }

    return intervals;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    sort(intervals.begin(), intervals.end(), compare);
    int i=0, n = intervals.size();
    while (i < n && intervals[i].start <= newInterval.start) i++;
    if (i == n) intervals.push_back(newInterval);
    else 
        intervals.insert(intervals.begin()+i, newInterval);

    vector<Interval> result = merge(intervals);

    return result;
}


// solution 2: note that the given intervals is non-overlapping, use that feature
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    if (intervals.size() == 0) {
        res.push_back(newInterval);
        return res;
    }
    int s = newInterval.start;
    int e = newInterval.end;
    
    vector<Interval> left;
    vector<Interval> merge;
    vector<Interval> right;
    for (int i=0; i<intervals.size(); i++) {
        if (intervals[i].end < s)
            left.push_back(intervals[i]);
        else if (intervals[i].start > e)
            right.push_back(intervals[i]);
        else {
            merge.push_back(intervals[i]);
        }
    }

    for (int i=0; i<left.size(); i++)
        res.push_back(left[i]);
    if (merge.size() > 0) {
        s = min(merge.front().start, s);
        e = max(merge.back().end, e);
    }
    res.push_back(Interval(s, e));
    for (int i=0; i<right.size(); i++)
        res.push_back(right[i]);

    return res;
}