class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        for (auto &meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            while (!busy.empty() && busy.top().first <= start) {
                int room = busy.top().second;
                busy.pop();
                free.push(room);
            }
            if (!free.empty()) {
                int room = free.top();
                free.pop();
                busy.push({end, room});
                count[room]++;
            }
            else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                long long duration = end - start;
                long long newEnd = freeTime + duration;
                busy.push({newEnd, room});
                count[room]++;
            }
        }
        int answer = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[answer]) {
                answer = i;
            }
        }
        return answer;
    }
};