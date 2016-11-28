/*
一个处理器要处理一堆request，一次只能处理一条，如果它有几个积压着的requests，它会先执行持续时间短的那个；
对于持续时间相等的requests，先执行最早到达处理器的request。问平均每个request要等多久才能被处理。
input：requestTimes[]，每个request到达处理器的时间; durations[] 每个request要处理的持续时间。 两个数组是一一对应的，并已按requestTimes[] 从小到大排序过
*/
class process {
public:
    int arrTime;
    int exeTime;
    process(int arr, int exe) {
        arrTime = arr;
        exeTime = exe;
    }
};

struct cmp {
    bool operator()(process* p1, process* p2) {
        if(p1->exeTime == p2->exeTime) {
            return p1->arrTime > p2->arrTime;
        }
        return p1->exeTime > p2->exeTime;
    }
};

class ShortestJobFirst {
public:
    float solution(vector<int> req, vector<int> dur) {
        if(req.empty() || dur.empty() || req.size() != dur.size()) return 0;
        int size = req.size();
        int index = 0;
        int waitTime = 0, curTime = 0;
        priority_queue<process*, vector<process*>, cmp> pq;

        while(!pq.empty() || index < size) {
            if(!pq.empty()) {
                process* cur = pq.top();
                pq.pop();
                waitTime += curTime - cur->arrTime;
                curTime += cur->exeTime;
                while(index < size && curTime >= req[index]) {
                    pq.push(new process(req[index], dur[index]));
                    index++;
                }
            } else {
                pq.push(new process(req[index], dur[index]));
                curTime = req[index++];
            }
        }
        return (float)waitTime/size;
    }
};

int main() {
    vector<int> req = {0,1,4};
    vector<int> dur = {4,3,2};
    ShortestJobFirst sj;
    cout << sj.solution(req, dur) << endl;
}
