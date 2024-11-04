#include <iostream>
#include <fstream>


using namespace std;

const int SIZE = 4; //Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin(){
        //This for loop iterates through each row, then each column of the 
        //Matrix to print its value
        int i, j;
        for (i =0; i < SIZE; ++i){
            for (j = 0; j <SIZE; ++j){
                //This cin function allows input from stdin, which can be used
                //to get input from data .txt files as well
                cin >> data[i][j];
            }
        }
    }

    // 2. Display a matrix
    void display() const{
        /*
        This code basically goes in tandom with readFromStdin, except this time
        The code in this program uses the cout function which now outputs the input 
        */
        int i, j;
        for (i =0; i< SIZE; ++i) {
            for (j = 0; j <SIZE; ++j){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }


    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const {
        /*How this function works to my understanding is that it intializes a class object,
        Matrix, and from out above defintion of what the object of Matrix would be, result
        matrix would essetially just be first initailized as an empty 4x4 Matrix. Once it 
        has been intiialzied, it is from there where we have 3 differet looping iterators for
        which, on the outter most loop, it is making sure it is looping through all of the
        rows first, then it is making it loops thorugh all of the columns, after this step,
        the next step in this program is to make sure that we have another variable, named,
        k for which k gives us 
    
        */
        Matrix result;
        int i,j,k;
        for (i = 0; i<SIZE; ++i){
            for (j =0; j<SIZE; ++j){
                result.data[i][j] = 0;
                for (k=0; k<SIZE; ++k){
                    result.data[i][j] += (data[i][k] + other.data[k][j]);
                }
            }
        }
        return result;
    }


    // 4. Multiply two matrices (operator overloading for *)
    /*
    Same concept as the code above, except this time we are multiplying the data from the other
    matrix 
    */
    Matrix operator*(const Matrix& other) const{
        Matrix result;
        int i,j,k;
        for (i = 0; i<SIZE; ++i){
            for (j =0; j<SIZE; ++j){
                result.data[i][j] = 0;
                for (k=0; k<SIZE; ++k){
                    result.data[i][j] += (data[i][k] * other.data[k][j]);
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    /*
    This code is different with the previous ones as in the previous ones, we had to loop 
    through all of the values in the matrices but for this function we are only summing
    the diagonals so the indexes are different with 
    */
    int sumOfDiagonals() const{
        int sum = 0, i, j;
        for (i=0; i<SIZE; ++i){
            sum+=data[i][i] + data[i][(SIZE-i)-1];
        }
        return sum;    
    }

    // 6. Swap matrix rows
    /*
    By using the swap function, it allows the switching of two objects, in our case the matrix
    object but switching the row values that are going to be passed to the parameter
    */
    void swapRows(int row1, int row2){
        int j;
        for (j =0; j <SIZE; ++j){
            swap(data[row1][j],data[row2][j]);
        }
    }


};

int main() {
// Example usage:

    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();


    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
    
}


