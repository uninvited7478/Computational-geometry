#include <bits/stdc++.h> 
using namespace std;

int det_2(int matrix[2][2])
{
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int det_3(int matrix[3][3])
{
    return matrix[0][0] * matrix[1][1] * matrix[2][2]
        + matrix[0][1] * matrix[1][2] * matrix[2][0]
        + matrix[0][2] * matrix[1][0] * matrix[2][1]
        - matrix[0][2] * matrix[1][1] * matrix[2][0]
        - matrix[0][0] * matrix[1][2] * matrix[2][1]
        - matrix[0][1] * matrix[1][0] * matrix[2][2];
}

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[columns];
    }

    srand(time(nullptr));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}