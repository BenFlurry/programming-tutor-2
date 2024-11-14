// heres the type definition of the matrix were gonna use
typedef struct _matrix {
    // which has a pointer to a 2d matrix represented by a 1d integer array pointer
    int* arr;
    // with the specified column length
    int col_len;
    // and the crucial row length, so that iteration through the matrix can be possible to calculate
    int row_len;
} matrix; // and lets type alias this as matrix to save your poor fingers from typing struct matrix everywhere


matrix* create_matrix(int row_len, int col_len);
/*
your first challenge is to make the matrix, now this wont be simple as you have to use malloc to create the array in heap memory
you need malloc both the matrix and the int array, then set the matrix's attributes
*/

matrix* zeros_matrix(matrix* m);
/*
here you will take in a matrix (either empty but this would work for a filled matrix too), and set all the values to 0
*cough* iterate through the matrix with a for loop *cough*
remember to return the matrix at the end 
matrix* zeros_matrix(matrix* m);
*/

int get_rows(matrix* m);
/*
simply return the number of rows specified by the matrix pointer. remember pointer syntax ->
*/

int get_cols(matrix* m);
/*
see above but for columns this time
*/

int free_matrix(matrix* m);
/*
for the love of god please dont make a massive matrix and never free it. so lets make a function for it
remember you have to free the integer array inside the matrix before you free the matrix otherwise pain
*/

void print_matrix(matrix* m);
/*
using row_len is required here in order to get the line breaks to make the matrix look like a matrix and not a 1d array
*/

matrix* set_matrix(matrix* m, int row, int col, int val);
/*
take in a row colum and value, and assign the matrix the value at said row and column, remember the matrix[row * row_len + col] to access the correct index
if the index they wish to edit is outside the bounds of the matrix, then print a statement telling them they did an ooopsie
*/

/*
FROM THIS POINT ON THE REST ARE CHALLENGES
*/
matrix* add(matrix* m, matrix* n);
/*
create a new array using create_matrix() and zeros_matrix() functions, then iterate through adding m and n into each cell of the array
*/

matrix* sub(matrix* m, matrix* n);
/*
see add but just sub
*/

matrix* multiply(matrix* m, matrix* n);
/* 
this is tricky since it could throw an error, so check that the dimensions are correct first, remmeber a m,n * n,p dimentional matrix is valid
*/

matrix* rotate(matrix* m);
/*
remember to check that the matrix is a square (row_len == col_len)
this is actually quite fun if you want to give a go, my tip is to either iterate through in a diagonal pattern using the optimised for loop, and swap matrix
m[i][j] with m[j][i], or you can make a new matrix to flip
*/
