#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool equal(double x1, double x2) {
    if (fabs(x1-x2) < 0.000000001) return true;
    else return false;
}

int maxPoints(vector<Point>& points) {
    bool flag, eq;
    int maxCount = 2;
    double k;
    if (points.size() <= 2) return points.size();
    for (int i=0; i <= points.size()-3; i++) {
        Point p1 = points[i];
        for (int l=i+1; l <= points.size()-2; l++) {
            flag = false;
            eq = false;
            Point p2 = points[l];
            if (p1.x == p2.x && p1.y == p2.y) {
                eq = true;
            }
            else if (p1.x == p2.x)
                flag = true;
            else 
                k = (double)(p2.y-p1.y) / (p2.x-p1.x);

            int tmpCount = 2;
            for (int j=l+1; j< points.size(); j++) {
                Point tmp = points[j];
                if (eq == true) {
                    if (tmp.x == p1.x && tmp.y == p1.y) {
                        eq = true;
                    }
                    else if (tmp.x == p1.x) {
                        flag = true;
                        eq = false;
                    }
                    else {
                        k = (double)(tmp.y-p1.y) / (tmp.x-p1.x);
                        eq = false;
                    }
                    tmpCount++;
                }
                else {
                    if (tmp.x == p1.x) {
                        if (flag || tmp.y == p1.y) tmpCount++;
                    }
                    else {
                        if (!flag && equal((double)(tmp.y-p1.y)/(tmp.x-p1.x), k))
                            tmpCount++;
                    }
                }
            }

            if (tmpCount > maxCount) maxCount = tmpCount;
        }

    }

    return maxCount;
}

int main() {
    Point p1(84,250);
    Point p2(0,0);
    Point p3(1,0);
    Point p4(0,-70);
    Point p5(0,-70);
    Point p6(1,-1);
    Point p7(21,10);
    Point p8(42,90);
    Point p9(-42,-230);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p8);
    points.push_back(p9);
    int count = maxPoints(points);

    cout << count << endl;

    return 0;
}