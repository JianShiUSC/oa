// rectangle overlap
struct Point {
    double x;
    double y;
    Point(double m, double n) : x(m), y(n) {}
};

bool doOverlap(Point topLeftA, Point bottomRightA, Point topLeftB, Point bottomRightB) {

}

// k closest points
struct Point {
    double x;
    double y;
    Point(double a, double b) : x(a), y(b) {}
};

vector<Point> kNearestPoint(vector<Point> arr, int k) {

}

// window sum
vector<int> getSum(vector<int> A, int k) {

}

// longest palindromic substring
class Solution {
public:
    string longestPalindrome(string s) {

    }
};

// copy list with random pointer
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

    }
};

// order dependency
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

    }
};

// minimum spanning tree
class Connection {
public:
    string node1;
    string node2;
    int cost;
    Connection(string a, string b, int c) {
        node1 = a;
        node2 = b;
        cost = c;
    }
};

class City_Connections {
public:
    vector<Connection*> getLowCost(vector<Connection*> connections) {

    }
};

// five scores
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

    }
};

// maximum subtree
class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
    TreeNode(int v) {
        val = v;
    }
};

class CompanyTree {
public:
    TreeNode* getHighAve(TreeNode* root) {

    }
};
