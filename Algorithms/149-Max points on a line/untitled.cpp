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

struct Slope {
    int x;
    int y;
    Slope(): x(0), y(0) {}
    Slope(int a, int b) : x(a), y(b) {}
}

bool equal(double x1, double x2) {
    if (fabs(x1-x2) < 0.000000001) return true;
    else return false;
}

Slope calcSlope(int x, int y) {
    int a = x, b = y;
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }

    Slope s(x/a, y/a);
    return s;
    
}

int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int maxCount = 2, tmpCount;
    Slope slope;
    for (int i=0; i<=n-3; i++) {
        Point p1 = points[i];                        // p1
        for (int j=i+1; j<=n-2; j++) {
            Point p2 = points[j];                    // p2
            tmpCount = 2;
            bool ver = false; // vertical flag
            bool eql = false; // equal flag

            if (p1.x == p2.x && p1.y == p2.y)
                eql = true;
            else if (p1.x == p2.x)
                ver = true;
            else
                slope = calcSlope(p2.y - p1.y, p2.x - p1.x);

            for (int k=j+1; k<=n-1; k++) {
                Point p3 = points[k];                          // p3
                if (eql) {                                     // p1 == p2
                    if (p3.x == p1.x && p3.y == p1.y)          // 1) p1 == p2 == p3
                        tmpCount++;
                    else if (p3.x == p1.x) {                   // 2) 
                        ver = true;
                        tmpCount++;
                        eql = false;
                    }
                    else {
                        slope = calcSlope(p3.y- p1.y, p3.x - p1.x);
                        tmpCount++;
                        eql = false;
                    }
                }
                else {
                    if ((p3.x == p1.x && p3.y == p1.y) || (p3.x == p2.x && p3.y == p2.y))
                        tmpCount++;
                    else if (p3.x == p1.x) {
                        if (ver) tmpCount++;
                    }
                    else {
                        Slope tmp_slope = calcSlope(p3.y - p1.y, p3.x - p1.x);
                        if (!ver && tmp_slope.x == slope.x && tmp_slope.y == tmp_slope.y)
                            tmpCount++;
                    }
                }
            }

            if (tmpCount > maxCount)
                maxCount = tmpCount;
        }
    }

    return maxCount;
}

int main() {
    // Point p1(84,250);
    // Point p2(0,0);
    // Point p3(1,0);
    // Point p4(0,-70);
    // Point p5(0,-70);
    // Point p6(1,-1);
    // Point p7(21,10);
    // Point p8(42,90);
    // Point p9(-42,-230);
    // vector<Point> points;
    // points.push_back(p1);
    // points.push_back(p2);
    // points.push_back(p3);
    // points.push_back(p4);
    // points.push_back(p5);
    // points.push_back(p6);
    // points.push_back(p7);
    // points.push_back(p8);
    // points.push_back(p9);
    Point p1(0,0);
    Point p2(-1,-1);
    Point p3(2,2);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    int count = maxPoints(points);

    cout << count << endl;

    return 0;
}