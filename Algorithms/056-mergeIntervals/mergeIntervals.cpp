struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

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

/// a better solution
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    vector<Interval> res;
    res.push_back(intervals[0]);
    for (int i=1; i<intervals.size(); i++) {
        if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
        else {
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }

    return res;
}
    