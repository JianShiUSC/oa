class process {
public:
    int arrTime;
    int exeTime;
    process(int arr, int exe) {
        arrTime = arr;
        exeTime = exe;
    }
};

class RoundRobinScheduling {
public:
    float solution(vector<int> Atime, vector<int> Etime, int q) {
        if(Atime.empty() || Etime.empty() || Atime.size() != Etime.size()) return 0;
        int size = Atime.size();
        queue<process*> qu;
        int curTime = 0, waitTime = 0;
        int index = 0;
        while(!qu.empty() || index < size) {
            if(!qu.empty()) {
                process* cur = qu.front();
                qu.pop();
                waitTime += curTime - cur->arrTime;
                curTime += min(cur->exeTime, q);

                for(; index < size && Atime[index] <= curTime; index++) {
                    qu.push(new process(Atime[index], Etime[index]));
                }
                if(cur->exeTime > q) {
                    qu.push(new process(curTime, cur->exeTime - q));
                }
            } else {
                qu.push(new process(Atime[index], Etime[index]));
                curTime = Atime[index++];
            }
        }
        return (float) waitTime/size;
    }
};

int main() {
    vector<int> Atime = {0,1,4};
    vector<int> Etime = {5,2,3};
    RoundRobinScheduling sol;
    cout << sol.solution(Atime, Etime, 3) << endl;
}
