/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    static int cmp(Interval a, Interval b)
    {
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>res;
        if (intervals.size()<1)
            return res;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval lastnode = intervals[0];
        res.push_back(lastnode);
        for (int i = 1; i < intervals.size(); ++i) {

            if (intervals[i].start>lastnode.end) {
                res.push_back(intervals[i]);
                lastnode = intervals[i];
            }
            else
            {
                res[res.size() - 1].end = max(lastnode.end, intervals[i].end);
                lastnode = res[res.size() - 1];
            }
        }
        return res;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int left = 0, right = intervals.size();
        while (left<right)//找到插入的位置
        {
            int mid = (left + right) / 2;
            if (intervals[mid].start <= newInterval.start)
                left = mid + 1;
            else
                right = mid;
        }
        intervals.insert(intervals.begin() + left, newInterval);
        return merge(intervals);//合并
    }
};
