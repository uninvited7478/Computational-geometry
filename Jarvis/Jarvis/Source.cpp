#include <bits/stdc++.h> 
using namespace std;

struct Point
{
    int x, y;
};

double cosine(int x, int y, int w)
{
    return w * x / sqrt(x * x + y * y);
}

Point findNextPoint(Point current, vector<Point>& points, int unitVectorVal)
{
    double maxiAngleCosine = -1;
    Point maxiPoint = current;
    for (int i = 0; i < points.size(); ++i)
    {
        if ((unitVectorVal == 1 && points[i].y >= current.y) || (unitVectorVal == -1 && points[i].y <= current.y))
        {
            double angleCosine = cosine(points[i].x - current.x, points[i].y - current.y, unitVectorVal);
            if (angleCosine > maxiAngleCosine)
            {
                maxiPoint = points[i];
                maxiAngleCosine = angleCosine;
            }
        }
    }
    return maxiPoint;
}

void jarvis(vector<Point>& points, int n)
{
    Point pMin = points[0];
    Point pMax = points[0];
    for (int i = 1; i < n; ++i)
    {
        if (points[i].y < pMin.y || (points[i].y == pMin.y && points[i].x < pMin.x))
        {
            pMin = points[i];
        }
        if (points[i].y > pMax.y || (points[i].y == pMax.y && points[i].x > pMax.x))
        {
            pMax = points[i];
        }
    }

    vector<Point> convexHull;

    int unitVectorVal = 1;
    Point currentPoint = pMin;
    while (currentPoint.x != pMax.x || currentPoint.y != pMax.y)
    {
        convexHull.push_back(currentPoint);
        currentPoint = findNextPoint(currentPoint, points, unitVectorVal);
    }

    unitVectorVal = -1;
    currentPoint = pMax;
    while (currentPoint.x != pMin.x || currentPoint.y != pMin.y)
    {
        convexHull.push_back(currentPoint);
        currentPoint = findNextPoint(currentPoint, points, unitVectorVal);
    }

    convexHull.push_back(pMin);

    cout << '\n';
    cout << "Convex Hull: \n";
    for (Point p : convexHull)
    {
        cout << p.x << ' ' << p.y << '\n';
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    jarvis(points, n);

    return 0;
}