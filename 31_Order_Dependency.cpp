class Order {
public:
    string orderName;
    Order(string name) {
        orderName = name;
    }
};

class OrderDependency {
public:
    Order* cur;
    Order* pre;
    OrderDependency(Order* pre, Order* cur) {
        this->pre = pre;
        this->cur = cur;
    }
};

class Solution {
public:
    vector<Order*> solution(vector<OrderDependency*> orderDependencies) {
        vector<Order*> res;
        map<string, int> inMap;
        map<string, vector<string>> outMap;
        map<string, Order*> recordMap;
        set<string> ss;

        for(auto od : orderDependencies) {
            Order* pre = od->pre;
            Order* cur = od->cur;
            string preName = pre->orderName;
            string curName = cur->orderName;
            ss.insert(preName);
            ss.insert(curName);

            if(recordMap.find(preName) == recordMap.end()) {
                recordMap[preName] = pre;
            }
            if(recordMap.find(curName) == recordMap.end()) {
                recordMap[curName] = cur;
            }
            // in degree
            if(inMap.find(preName) == inMap.end()) {
                inMap[preName] = 0;
            }
            inMap[curName]++;
            // out degree
            outMap[preName].push_back(curName);
            if(outMap.find(curName) == outMap.end()) {
                outMap[curName] = {};
            }
        }

        queue<string> qu;
        for(auto it : inMap) {
            if(it.second == 0) {
                qu.push(it.first);
            }
        }

        while(!qu.empty()) {
            string top = qu.front();
            qu.pop();
            res.push_back(recordMap[top]);
            for(string str : outMap[top]) {
                if(--inMap[str] == 0) {
                    qu.push(str);
                }
            }
        }

        if(ss.size() != res.size()) res.clear();
        return res;
    }
};

int main() {
    Order* o1 = new Order("泡面");
    Order* o2 = new Order("泡面");
    Order* o3 = new Order("SF");
    Order* o4 = new Order("租车");
    Order* o5 = new Order("SF");
    Order* o6 = new Order("泡面");
    Order* o7 = new Order("租车");
    Order* o8 = new Order("SF");
    Order* o9 = new Order("爽(每个行为只输出了一次对吧)");
    OrderDependency* od1 = new OrderDependency(o1, o3);
    OrderDependency* od2 = new OrderDependency(o2, o7);
    OrderDependency* od3 = new OrderDependency(o3, o9);
    OrderDependency* od4 = new OrderDependency(o4, o3);
    OrderDependency* od5 = new OrderDependency(o6, o9);
    OrderDependency* od6 = new OrderDependency(o8, o9);
    OrderDependency* od7 = new OrderDependency(o2, o5);

    vector<OrderDependency*> list;
    list.push_back(od1);
    list.push_back(od2);
    list.push_back(od3);
    list.push_back(od4);
    list.push_back(od5);
    list.push_back(od6);
    list.push_back(od7);

    Solution sol;
    vector<Order*> res = sol.solution(list);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i]->orderName;
        if (i+1 < res.size()){
            cout << " -> ";
        }
    }
    cout << endl;
}














class Order {
public:
    string orderName;
    Order() {}
    Order(string name) {
        orderName = name;
    }
};

class OrderDependency {
public:
    Order cur;
    Order pre;
    OrderDependency(Order p, Order c) : pre(p), cur(c) {}
};

class Solution {
public:
    vector<Order> solution(vector<OrderDependency> orderDependencies) {
        vector<Order> res;
        map<string, int> inDegree;
        map<string, vector<string>> outMap;
        map<string, Order> recordMap;
        set<string> ss;

        for(auto edge : orderDependencies) {
            Order cur = edge.cur;
            Order pre = edge.pre;
            string curName = cur.orderName;
            string preName = pre.orderName;
            ss.insert(curName);
            ss.insert(preName);
            if(recordMap.find(curName) == recordMap.end()) {
                recordMap[curName] = cur;
            }
            if(recordMap.find(preName) == recordMap.end()) {
                recordMap[preName] = pre;
            }

            // indegree
            if(inDegree.find(preName) == inDegree.end()) {
                inDegree[preName] = 0;
            }
            inDegree[curName]++;

            // outDegree
            if(outMap.find(curName) == outMap.end()) {
                outMap[curName] = {};
            }
            outMap[preName].push_back(curName);
        }

        queue<string> qu;
        for(auto it : inDegree) {
            if(it.second == 0) {
                qu.push(it.first);
            }
        }

        while(!qu.empty()) {
            string temp = qu.front();
            qu.pop();
            res.push_back(recordMap[temp]);
            for(string str : outMap[temp]) {
                if(--inDegree[str] == 0) {
                    qu.push(str);
                }
            }
        }
        if(ss.size() != res.size()) return {};
        return res;
    }
};

int main() {
    Order o1("泡面");
    Order o2("泡面");
    Order o3("SF");
    Order o4("租车");
    Order o5("SF");
    Order o6("泡面");
    Order o7("租车");
    Order o8("SF");
    Order o9("爽(每个行为只输出了一次对吧)");

    OrderDependency od1(o1, o3);
    OrderDependency od2(o2, o7);
    OrderDependency od3(o3, o9);
    OrderDependency od4(o4, o3);
    OrderDependency od5(o6, o9);
    OrderDependency od6(o8, o9);
    OrderDependency od7(o2, o5);

    vector<OrderDependency> list;
    list.push_back(od1);
    list.push_back(od2);
    list.push_back(od3);
    list.push_back(od4);
    list.push_back(od5);
    list.push_back(od6);
    list.push_back(od7);

    Solution sol;
    vector<Order> res = sol.solution(list);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].orderName;
        if (i+1 < res.size()){
            cout << " -> ";
        }
    }
    cout << endl;
}
