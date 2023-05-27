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

int main()
{
    vector<Point> points;
    srand(time(nullptr));
    for (int i = 1; i <= 100; ++i)
    {
        int x = rand() % 101; // (0, 100); 
        int y = rand() % 101; // (0, 100); 
        points.push_back({ x, y });
    }

    Point p, q;

    cout << "Punkt p: (x, y)\n";
    cin >> p.x >> p.y;

    cout << "Punkt q: (x, y)\n";
    cin >> q.x >> q.y;

    int leftCounter = 0;
    int rightCounter = 0;
    int collinearCounter = 0;
    for (Point r : points)
    {
        int res = det(p, q, r);
        if (res > 0) {
            leftCounter++;
        }
        else if (res < 0) {
            rightCounter++;
        }
        else {
            collinearCounter++;
        }
    }

    cout << leftCounter << " punktów leży po lewej stronie prostej pq\n";
    cout << rightCounter << " punktów leży po prawej stronie prostej pq\n";
    cout << collinearCounter << " punktów jest współliniowych z punktami p i q\n";


    return 0;
}