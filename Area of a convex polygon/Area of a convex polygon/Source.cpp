#include <iostream> 
#include <vector> 
#include <cmath> 
#include <set> 
#include <iomanip> 
using namespace std;

struct Point
{
    int x;
    int y;
};

struct Triangle
{
    Point a, b, c;
};

double distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double triangleHeronField(Triangle tr)
{
    double a = distance(tr.c, tr.b);
    double b = distance(tr.a, tr.c);
    double c = distance(tr.a, tr.b);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double polygonFieldFromFirstPoint(vector<Point>& points)
{
    double field = 0;
    for (int i = 2; i < points.size(); ++i)
    {
        Triangle tr = { points[0], points[i - 1], points[i] };
        field += triangleHeronField(tr);
    }
    return field;
}

double polygonFieldFromAnyPoint(vector<Point>& points, Point anyPoint)
{
    double field = 0;
    int n = points.size();
    for (int i = 1; i < n; ++i)
    {
        Triangle tr = { anyPoint, points[i - 1], points[i] };
        field += triangleHeronField(tr);
    }
    Triangle tr = { anyPoint, points[n - 1], points[0] };
    field += triangleHeronField(tr);
    return field;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
    {
        Point p;
        cin >> p.x >> p.y;
        points[i] = p;
    }

    double fieldFromFirstPoint = polygonFieldFromFirstPoint(points);
    cout << setprecision(1) << fixed;
    cout << fieldFromFirstPoint << '\n';

    int m;
    cin >> m;

    while (m--)
    {
        Point p;
        cin >> p.x >> p.y;
        double fieldFromAnyPoint = polygonFieldFromAnyPoint(points, p);
        if (fabs(fieldFromFirstPoint - fieldFromAnyPoint) < 0.01)
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }

    return 0;
}