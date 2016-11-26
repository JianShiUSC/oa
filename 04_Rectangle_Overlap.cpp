// 给两个长方形的topLeft和bottomRight坐标, 判断这两个长方形是否重叠
struct Point {
    double x;
    double y;
    Point(double m, double n) : x(m), y(n) {}
};

bool doOverlap(Point topLeftA, Point bottomRightA, Point topLeftB, Point bottomRightB) {
    if(topLeftA.x > bottomRightB.x || topLeftB.x > bottomRightA.x) {
        return false;   // no overlap
    }
    if(topLeftA.y < bottomRightB.y || topLeftB.y < bottomRightA.y) {
        return false;
    }
    return true;
}


int main() {
    Point topLeftA(-3, 4);
    Point bottomRightA(3, 0);
    Point topLeftB(3, 2);
    Point bottomRightB(9, -1);

    cout << doOverlap(topLeftA, bottomRightA, topLeftB, bottomRightB) << endl;
}
