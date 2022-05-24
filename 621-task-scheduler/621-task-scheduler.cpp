class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        queue<pair<int, int>> context;
        vector<int> counter = getCount(tasks);
        priority_queue<int> max_heap;
        for (auto &c : counter) {
            if (c == 0) continue;
            max_heap.push(c);
        }
        while (!max_heap.empty() || !context.empty()) {
            int process = 0;
            if (max_heap.size()){
                process = max_heap.top();
                max_heap.pop();
            }
            time++;
            if ((process-1) > 0) {
                context.push({process-1, (time+n)});
            }
            if (!context.empty() && time == context.front().second) { 
                max_heap.push(context.front().first);
                context.pop();
            }
        }
        return time;
    }
private:
    vector<int> getCount(vector<char> &tasks) {
        vector<int> arr(26, 0);
        for (char &ch : tasks) {
            arr[ch - 'A']++;
        }
        return arr;
    }
};