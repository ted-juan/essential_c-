#include "c6-2.hpp"

// Member Functions
template <typename elemType>
inline Matrix<elemType>::Matrix(int rows, int columns) {
  _rows = rows;
  _columns = columns;
  _matrix = new elemType[rows * columns];
}

template <typename elemType>
Matrix<elemType>::Matrix(const Matrix &rhs) { //< Specified constructor

  _rows = rhs._rows;
  _columns = rhs._columns;
  int mat_size = _rows * _columns;
  _matrix = new elemType[mat_size];
  for (int i = 0; i < mat_size; ++i) {
    _matrix[i] = rhs._matrix[i];
  }
}

template <typename elemType>
Matrix<elemType>& Matrix<elemType>::operator=(const Matrix &rhs) { //< Specified constructor

  if (this != &rhs) {
    _rows = rhs._rows;
    _columns = rhs._columns;
    int mat_size = _rows * _columns;
    delete [] _matrix;
    _matrix = new elemType[mat_size];
    for (int i = 0; i < mat_size; ++i) {
      _matrix[i] = rhs._matrix[i];
    }
  }
  return *this;
}

template <typename elemType>
inline ostream& Matrix<elemType>::print(ostream& os) const { //< print matrix
int col = cols();
int matrix_size = col * rows();
  for (int i = 0; i < matrix_size; ++i) {
    if ( i % col == 0) 
      cout << endl;
    cout << _matrix[i] << ' ';
  }
  cout << endl;
  return os;
}

template <typename elemType>
inline void Matrix<elemType>::operator += (const Matrix &add_matrix) {
  if (! this -> add_check(add_matrix)) {
    cerr << "Addition error: matrices incompatible dimensions." << endl;
  }
  int matrix_size = _columns * _rows;
  for (int i = 0; i < matrix_size; ++i) {
      _matrix[i] += add_matrix._matrix[i];
  }
}

// Non-member Functions
template <typename elemType>
inline Matrix<elemType> operator + (const Matrix<elemType> &matrix_1, const Matrix<elemType> &matrix_2) { //< add two matrices
  if (! matrix_1.add_check(matrix_2)) {
    cerr << "Addition error: matrices incompatible dimensions." << endl;
  }
  Matrix<elemType> out_matrix(matrix_1);
  out_matrix += matrix_2;
  return out_matrix;
}

template <typename elemType>
inline Matrix<elemType> operator * (const Matrix<elemType> &matrix_1, const Matrix<elemType>&matrix_2) { //< multiply two matrices
  if (! matrix_1.multiply_check(matrix_2)) {
    cerr << "Multiplication error: rows - " << matrix_1.rows() << " - not equal "
    << "to columns - " << matrix_2.cols() << "." << endl;
  }
  Matrix<elemType>  out_matrix(matrix_1.rows(), matrix_2.cols());
  for (int i = 0; i < matrix_1.rows(); ++i) {
    for (int j = 0; j < matrix_1.cols(); ++j) {
      out_matrix(i, j) = 0;
      for (int k = 0; k < matrix_1.cols(); ++k) {
        out_matrix(i,j) += matrix_1( i, k) * matrix_2( k, j);
      }
    }
  }
  return out_matrix;
}

template <typename elemType>
inline ostream &operator<<(ostream &os, const Matrix<elemType> &mat)
{
	return mat.print(os);
}