#include <iostream> 
#include <fstream> 
#include <vector> 
using namespace std;

struct Point
{
    int x, y;
};

struct Line
{
    Point p, q;
    int i;
};

struct CommonFraction
{
    int numerator;
    int denominator;
};

struct FractionPoint
{
    CommonFraction x, y;
};

int det3(Point a, Point b, Point c)
{
    // | ax ay 1 | 
    // | bx by 1 | 
    // | cx cy 1 | 
    return a.x * b.y + a.y * c.x + b.x * c.y - b.y * c.x - a.x * c.y - a.y * b.x;
}

int det2(int matrix[2][2])
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
FractionPoint intersectionPoint(Line& line1, Line& line2)
{
    int smallMatrix12[2][2] = {
        {line1.p.x, line1.p.y},
        {line1.q.x, line1.q.y} };
    int smallMatrix34[2][2] = {
        {line2.p.x, line2.p.y},
        {line2.q.x, line2.q.y} };

    int bigMatrixX[2][2] = {
        {det2(smallMatrix12), line1.p.x - line1.q.x},
        {det2(smallMatrix34), line2.p.x - line2.q.x} };

    int bigMatrixY[2][2] = {
        {det2(smallMatrix12), line1.p.y - line1.q.y},
        {det2(smallMatrix34), line2.p.y - line2.q.y} };

    int denominatorMatrix[2][2] = {
        {line1.p.x - line1.q.x, line1.p.y - line1.q.y},
        {line2.p.x - line2.q.x, line2.p.y - line2.q.y} };

    int numeratorX = det2(bigMatrixX);
    int numeratorY = det2(bigMatrixY);
    int denominatorX = det2(denominatorMatrix);
    int denominatorY = det2(denominatorMatrix);

    FractionPoint fractionPoint = {
        {numeratorX, denominatorX},
        {numeratorY, denominatorY} };
    return fractionPoint;
}

bool isParallelTo(Line& line1, Line& line2)
{
    int matrix[2][2] = {
        {line1.p.x - line1.q.x, line1.p.y - line1.q.y},
        {line2.p.x - line2.q.x, line2.p.y - line2.q.y} };
    if ((det2(matrix) == 0) && (det3(line1.p, line1.q, line2.p) != 0))
    {
        return true;
    }
    return false;
}

int main()
{
    fstream inputFile;
    inputFile.open("linie.txt");

    ofstream resFile1, resFile2;
    resFile1.open("wyniki1.txt");
    resFile2.open("wyniki2.txt");

    int N;
    inputFile >> N;

    Line firstLine;
    inputFile >> firstLine.p.x;
    inputFile >> firstLine.p.y;
    inputFile >> firstLine.q.x;
    inputFile >> firstLine.q.y;
    firstLine.i = 1;

    vector<Line> lines;
    for (int i = 2; i <= N; ++i)
    {
        Line nextLine;
        inputFile >> nextLine.p.x;
        inputFile >> nextLine.p.y;
        inputFile >> nextLine.q.x;
        inputFile >> nextLine.q.y;
        nextLine.i = i;
        lines.push_back(nextLine);
    }

    vector<Line> intersectWithFirstLine;
    vector<FractionPoint> intersectionPoints;

    for (Line line : lines)
    {
        if (!isParallelTo(firstLine, line))
        {
            intersectWithFirstLine.push_back(line);
            intersectionPoints.push_back(intersectionPoint(firstLine, line));
        }
    }

    resFile1 << intersectWithFirstLine.size() << '\n';
    for (Line line : intersectWithFirstLine)
    {
        resFile1 << line.i << ' ';
    }

    for (FractionPoint point : intersectionPoints)
    {
        resFile2 << point.x.numerator << ' ' << point.x.denominator << ' '
            << point.y.numerator << ' ' << point.y.denominator << '\n';
    }

    inputFile.close();
    resFile1.close();
    resFile2.close();

    return 0;
}