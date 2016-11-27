class Container {
public:
    double first;
    double second;
};

Container findOptimalWeights(double capacity, vector<double> weights, int numOfContainers) {
    Container res;
    double min = 0.0;
    sort(weights.begin(), weights.end());
    int minPos = 0;
    int maxPos = weights.size() - 1;
    int i = 0, j = weights.size() - 1;

    while(i < j) {
        double sum = weights[i] + weights[j];
        if(sum > min && sum <= capacity) {
            min = sum;
            minPos = i;
            maxPos = j;
        }
        if(sum > capacity) j--;
        else i++;
    }
    res.first = weights[minPos];
    res.second = weights[maxPos];

    return res;
}

int main() {
    vector<double> weights = {1,2,3,4,5};
    findOptimalWeights(9, weights, 5);
}
