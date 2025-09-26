#include<iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    int **mat; //2D array to store matrix
    public:
    Matrix(){ //default constructor
        rows=0;
        cols=0;
        mat=nullptr;
    }

    void matrixCreation(){
        cout<<"starting dynamic matrix creation"<<endl;
        cout<<"enter rows of matrix: ";
        cin>>rows;
        cout<<"enter columns of matrix: ";
        cin>>cols;
        mat=new int*[rows]; //allocating rows to the matrix
        for (int i=0; i<rows; i++){
                mat[i]=new int[cols]; //allocating columns for each row in matrix
        }
        cout<<"enter elements in matrix"<<endl;
        for (int i=0; i<rows; i++){ //storing values in matrix
            for (int j=0; j<cols; j++){
                cout<<"element["<<i<<"]["<<j<<"]: ";
                cin>>mat[i][j];
            }
        }
        cout<<"your dynamic matrix is created"<<endl;
    }

    void resizeMatrix(){
        cout<<"starting to resize matrix"<<endl;
        //asking user for new rows and columns
        int c, r, newValue;
        cout<<"enter updated rows: ";
        cin>>r;
        cout<<"enter updated columns: ";
        cin>>c;
        cout<<"enter value to assign to new elements(if there are any): ";
        cin>>newValue;
        cout<<endl;
        int **newMat=new int*[r]; //new matrix with updated rows
        for (int i=0; i<r; i++){
            newMat[i]=new int[c]; //updated column 
        }
        for (int i=0; i<r; i++){ //resizing matrix
            for (int j=0; j<c; j++){
                if (i<rows && j<cols){ //condition to copy old matrix values
                    newMat[i][j]=mat[i][j];
                }
                else {
                    newMat[i][j]=newValue;
                }
            }
        }
        for (int i=0; i<rows; i++){ //deleting old matrix
            delete mat[i];
        }
        delete [] mat;
        mat=newMat; //matrix pointer now points to updated matrix
        rows=r;
        cols=c;
        cout<<"resizing of matrix done"<<endl;
    }

    void transposeMatrix(){
        cout<<"starting transpose of matrix"<<endl;
        //making a transpose matrix
        int **transposedMat=new int*[cols];
        for (int j=0; j<cols; j++){
            transposedMat[j]=new int[rows];
        }
        for (int i=0; i<rows; i++){ //passing values of matrix to transposed matrix
            for (int j=0; j<cols; j++){
                transposedMat[j][i]=mat[i][j];
            }
        }
        //free memory
        for (int i=0; i<rows; i++){
            delete mat[i];
        }
        delete [] mat; 
        mat=transposedMat; //mat pointer now points to transposed matrix
        swap(rows,cols); //swapping values of columns and rows
        cout<<"transposed matrix created"<<endl;
    }

    void printMatrix(){
        cout<<"-----2D dynamic Matrix--------"<<endl;
        for (int i=0; i<rows; i++){ //printing matrix
            for (int j=0; j<cols; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void addTwoInOddRows(){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (i%2!=0){ //check for odd row
                    mat[i][j]+=2;
                }
            }
        }
        cout<<"2 added to each odd row element"<<endl;
    }
    ~Matrix(){ //destructor
        for (int i=0; i<rows; i++){
            delete mat[i];
        }
        delete [] mat;
        cout<<"matrix destroyed"<<endl;
    }
};

int main(){
    Matrix m;
    m.matrixCreation();
    m.printMatrix();
    m.transposeMatrix();
    m.printMatrix();
    m.resizeMatrix();
    m.printMatrix();
    m.addTwoInOddRows();
    m.printMatrix();
}