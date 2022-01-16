#include <iostream>

using namespace std;

template <typename elemType>
class Matrix {

public:
  Matrix(int rows, int coloums); 
  Matrix(const Matrix&); 
  ~Matrix() { delete [] _matrix; };
  Matrix& operator=(const Matrix&); 
  ostream& print(ostream&) const; //< member function to print out matrix

  int rows() const {
    return _rows;
  }

  int cols() const {
    return _columns;
  }
  // Overload operators
  inline elemType& operator () (int row, int column) { //< index operator for element extraction
    return(_matrix[row * cols() + column]);
  }
  inline elemType operator () (int row, int column) const { //< index operator for element extraction
    return(_matrix[row * cols() + column]);
  }
  void operator += (const Matrix<elemType> &add_matrix); //< compound addition operator for matrices

  bool add_check(const Matrix<elemType> &matrix) const {
    if ((*this).rows() != matrix.rows() || (*this).cols() != matrix.cols()) {
      return false;
    }
    return true;
  }

  bool multiply_check(const Matrix &matrix) const {
    if ((*this).rows() != matrix.cols()) {
      return false;
    }
    return true;
  }
private:
  elemType *_matrix;
  int _rows;
  int _columns;

};
