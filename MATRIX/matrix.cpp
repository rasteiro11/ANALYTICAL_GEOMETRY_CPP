#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>
#include <vector>
class DiffVecSpaceError : std::exception {};
class Matrix {
private:
  std::vector<std::vector<double>> matrix;

public:
  Matrix(std::vector<std::vector<double>> matrix);
  Matrix(int nRows, int nCols);
  // MATRIX FROM 1D VECTOR
  Matrix(std::vector<double> vector, int nRows, int nCols);
  // COLUMN MATRIX FROM VECTOR
  Matrix(std::vector<double> vector);
  friend std::ostream &operator<<(std::ostream &o, const Matrix &m);
  Matrix operator+(const Matrix &other);
  Matrix operator+(double d);
  Matrix operator-(const Matrix &other);
  Matrix operator-(double d);
  Matrix operator*(const Matrix &other);
  Matrix operator*(double d);
};

Matrix::Matrix(int nRows, int nCols) {
  std::vector<std::vector<double>> matrix =
      std::vector<std::vector<double>>(nRows);
  for (int i = 0; i < nRows; i++) {
    matrix[i] = std::vector<double>(nCols);
  }

  this->matrix = matrix;
}

Matrix::Matrix(std::vector<std::vector<double>> matrix) {
  this->matrix = matrix;
}
std::ostream &operator<<(std::ostream &o, const Matrix &m) {
  for (int i = 0; i < m.matrix.size(); i++) {
    for (int j = 0; j < m.matrix.at(0).size(); j++) {
      if (j == 0) {
        o << m.matrix.at(i).at(j) << " ";
      } else if (j == m.matrix.at(0).size() - 1) {
        o << " " << m.matrix.at(i).at(j);
      } else {
        o << " " << m.matrix.at(i).at(j) << " ";
      }
    }
    o << "\n";
  }
  return o;
}

Matrix Matrix::operator+(const Matrix &other) {
  if (this->matrix.size() != other.matrix.size()) {
    throw DiffVecSpaceError();
  }
  if (this->matrix.at(0).size() != other.matrix.at(0).size()) {
    throw DiffVecSpaceError();
  }
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] += other.matrix[i][j];
    }
  }
  return result;
}
Matrix Matrix::operator+(double d) {
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] += d;
    }
  }
  return result;
}

Matrix Matrix::operator-(const Matrix &other) {
  if (this->matrix.size() != other.matrix.size()) {
    throw DiffVecSpaceError();
  }
  if (this->matrix.at(0).size() != other.matrix.at(0).size()) {
    throw DiffVecSpaceError();
  }
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] -= other.matrix[i][j];
    }
  }
  return result;
}

Matrix Matrix::operator-(double d) {
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] -= d;
    }
  }
  return result;
}

Matrix Matrix::operator*(const Matrix &other) {
  if (this->matrix.size() != other.matrix.size()) {
    throw DiffVecSpaceError();
  }
  if (this->matrix.at(0).size() != other.matrix.at(0).size()) {
    throw DiffVecSpaceError();
  }
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] *= other.matrix[i][j];
    }
  }
  return result;
}

Matrix Matrix::operator*(double d) {
  Matrix result = Matrix(this->matrix);
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = 0; j < this->matrix.at(0).size(); j++) {
      result.matrix[i][j] *= d;
    }
  }
  return result;
}
