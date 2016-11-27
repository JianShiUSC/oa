/*
Find the K closest points to the origin in a 2D plane,
given an array containing N points.
*/
struct Point {
    double x;
    double y;
    Point(double a, double b) : x(a), y(b) {}
};

// max heap
struct cmp {
    bool operator()(Point a, Point b) {
        return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
    }
};

vector<Point> kNearestPoint(vector<Point> arr, int k) {
    vector<Point> res;
    priority_queue<Point, vector<Point>, cmp> pq;
    for(int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    res.resize(pq.size(), Point(0, 0));
    for(int i = pq.size() - 1; i >= 0; i--) {
        res[i] = pq.top();
        pq.pop();
    }
    return res;
}



int main() {
    Point* p0 = new Point(1,0.5);
    Point* p1 = new Point(1,0);
    Point* p2 = new Point(1,0.6);
    Point* p3 = new Point(1,1);
    Point* p4 = new Point(2,2);
    vector<Point> arr = {*p0, *p1, *p2, *p3, *p4};

    kNearestPoint(arr, 3);
}
