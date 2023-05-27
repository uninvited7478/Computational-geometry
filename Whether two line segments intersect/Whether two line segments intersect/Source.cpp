#include <bits/stdc++.h> 
using namespace std;

struct Point
{
    int x, y;
};

int det(Point a, Point b, Point c)
{
    // | ax ay 1 | ax ay 
    // | bx by 1 | bx by 
    // | cx cy 1 | cx cy 
    return a.x * b.y + a.y * c.x + b.x * c.y
        - b.y * c.x - a.x * c.y - a.y * b.x;
}

int sgn(int x)
{
    if (x > 0) return 1;
    else if (x == 0) return 0;
    return -1;
}

bool isPointOnLineSegment(Point line_start, Point line_end, Point point)
{
    int start_x = line_start.x;
    int start_y = line_start.y;
    int end_x = line_end.x;
    int end_y = line_end.y;

    if (start_x > end_x) swap(start_x, end_x);
    if (start_y > end_y) swap(start_y, end_y);

    if (sgn(det(line_start, line_end, point)) == 0
        &&
        (start_x <= point.x && point.x <= end_x)
        &&
        (start_y <= point.y && point.y <= end_y))
        return true;
    return false;
}

int main()
{
    Point p, q, a, d;

    cout << "Podaj współrzędne odcinka pq: \n";
    cout << "p: (x, y) \n";
    cin >> p.x >> p.y;
    cout << "q: (x, y) \n";
    cin >> q.x >> q.y;


    cout << "Podaj współrzędne odcinka ad: \n";
    cout << "a: (x, y) \n";
    cin >> a.x >> a.y;
    cout << "d: (x, y) \n";
    cin >> d.x >> d.y;


    if (sgn(det(p, q, a)) != sgn(det(p, q, d)) && sgn(det(a, d, p)) != sgn(det(a, d, q))
        || isPointOnLineSegment(p, q, a)
        || isPointOnLineSegment(p, q, d)
        || isPointOnLineSegment(a, d, p)
        || isPointOnLineSegment(a, d, q)
        ) {
        cout << "Odcinki pq i ad się przecinają\n";
    }
    else {
        cout << "Odcinki pq i ad się NIE przecinają\n";
    }

    return 0;
}