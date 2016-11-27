/*
int[] dayChange(int[] cells, int days), cells数组，一共8个元素。

一个cell，如果左右两边的数一样，则将这个数设置为0，否则设置为1，题中用inactive和active来描述，
后来给出的coding中用0和1表示。因为第一个数和最后一个数都只有一个相邻的数，因此设置为0。给出天数days，求days之后的结果。

例子：
cells: [1 0 0 0 0 1 0 0]
days: 1
output: [0 1 0 0 1 0 1 0]
*/
vector<int> solution(vector<int> days, int n) {
    if(days.empty() || n <= 0) return days;
    int size = days.size();
    vector<int> res;
    vector<int> temp(size + 2);
    temp[0] = temp[size+1] = 0;

    int pre = temp[0];
    for(int i = 1; i <= size; i++) {
        temp[i] = days[i-1];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= size; j++) {
            int t = temp[j];
            temp[j] = pre ^ temp[j+1];
            pre = t;
        }
    }

    for(int i = 1; i <= size; i++) {
        res.push_back(temp[i]);
    }
    return res;
}


int main() {
    vector<int> days = {1,0,0,0,0,1,0,0};
    solution(days, 1);
}
