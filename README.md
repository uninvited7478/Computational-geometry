# Computational-geometry
A matrix is a two-dimensional array that holds many values. The matrix stores
data in rows and columns. The number of rows and columns of a matrix is called its dimensions Below
we present matrix A with dimensions of 3 x 4 (three rows, four columns) with the stored in
this matrix with numbers:
1 2 3 4  

A =[]
1   |5 11 -4 3 | 
2   |29 -3 12 91|  
3   |82 0 3 -2|
Determinant of the matrix
The determinant of the nth degree (determinant) of a square matrix A of n x n is a number,
which we compute recursively as follows:
If n = 1, then the determinant of a matrix is ​​equal to the value of an element of this matrix,
that is: det A 1x1 = det [ a 1 ] = a 1
For n > 1; select any row or column (preferably the one with the most zeros). Then
we multiply each term of this row or column by the determinant of the matrix, which is formed by
removing the row and column with the multiplied term (this determinant is calculated recursively with the same
method). If the sum of the row and column numbers of the multiplied term is odd, then the resulting
the product is additionally multiplied by -1. The calculated products are summed up to obtain the value of the determinant.
This method is called Laplace's method and unfortunately it is not very efficient.
