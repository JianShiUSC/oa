/*
输入是List<节点>，节点里面有两个属性学生id和分数，同时保证每个学生至少会有5个节点(即至少有5个分数)，返回一个map，key是id，value是每个人最高5个分数的平均分。
这题很简单，对每个学生用一个prioriy queue就行了
用priority queue做。对每个学生用一次。
*/
class Result {
public:
    int id;
    int value;
    Result(int id, int value) {
        this->id = id;
        this->value = value;
    }
};

class HighFive {
public:
    map<int, double> getHighFive(vector<Result*> results) {
        map<int, double> mm;
        map<int, vector<int>> pValue;

        for(auto res : results) {
            int id = res->id;
            pValue[id].push_back(res->value);
        }

        for(auto it : pValue) {
            vector<int> temp = it.second;
            sort(temp.begin(), temp.end(), greater<int>());
            double value = 0;
            for(int k = 0; k < 5; k++) {
                value += temp[k];
            }
            value /= 5.0;
            mm[it.first] = value;
        }
        return mm;
    }
};

int main() {
    Result* r1 = new Result(1, 95);
    Result* r2 = new Result(1, 95);
    Result* r3 = new Result(1, 91);
    Result* r4 = new Result(1, 91);
    Result* r5 = new Result(1, 93);
    Result* r6 = new Result(1, 105);

    Result* r7 = new Result(2, 6);
    Result* r8 = new Result(2, 6);
    Result* r9 = new Result(2, 7);
    Result* r10 = new Result(2, 6);
    Result* r11 = new Result(2, 6);
    vector<Result*> arr = {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11};
    HighFive hf;
    hf.getHighFive(arr);
}
