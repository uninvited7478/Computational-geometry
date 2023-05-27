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

int main()
{
    Point p, q, r;

    cout << "Podaj współrzędne odcinka pq: \n";
    cout << "p: (x, y) \n";
    cin >> p.x >> p.y;
    cout << "q: (x, y) \n";
    cin >> q.x >> q.y;


    cout << "Podaj punkt r: (x, y) \n";
    cin >> r.x >> r.y;

    bool check_x = false;
    if (p.x <= q.x) {
        if (p.x <= r.x && r.x <= q.x && sgn(det(p, q, r)) == 0) {
            check_x = true;
        }
    }
    else {
        if (q.x <= r.x && r.x <= p.x && sgn(det(p, q, r)) == 0) {
            check_x = true;
        }
    }

    bool check_y = false;
    if (p.y <= q.y) {
        if (p.y <= r.y && r.y <= q.y && sgn(det(p, q, r)) == 0) {
            check_y = true;
        }
    }
    else {
        if (q.y <= r.y && r.y <= p.y && sgn(det(p, q, r)) == 0) {
            check_y = true;
        }
    }

    if (check_x && check_y) {
        cout << "Punkt r NALEŻY do odcinka pq\n";
    }
    else {
        cout << "Punkt r NIE NALEŻY do odcinka pq\n";
    }

    return 0;
}