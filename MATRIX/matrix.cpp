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
  Matrix(std::vector<double> vector, int nRows, int nCols);
  Matrix(std::vector<double> vector);
  friend std::ostream &operator<<(std::ostream &o, const Matrix &m);
  Matrix operator+(const Matrix &other);
  Matrix operator+(double d);
  Matrix operator-(const Matrix &other);
  Matrix operator-(double d);
  Matrix operator*(const Matrix &other);
  Matrix operator*(double d);
  Matrix transpose();
};

Matrix::Matrix(int nRows, int nCols) {
  std::vector<std::vector<double>> matrix =
      std::vector<std::vector<double>>(nRows);
  for (int i = 0; i < nRows; i++) {
    matrix[i] = std::vector<double>(nCols);
  }

  this->matrix = matrix;
}

Matrix::Matrix(std::vector<double> vector, int nRows, int nCols) {
  Matrix matrix = Matrix(nRows, nCols);
  int p = 0;
  for (int i = 0; i < nRows; i++) {
    for (int j = 0; j < nCols; j++) {
      matrix.matrix[i][j] = vector[p++];
    }
  }
  this->matrix = matrix.matrix;
}

Matrix::Matrix(std::vector<double> vector) {
  int nCols = vector.size();
  int nRows = vector.size();
  Matrix matrix = Matrix(nRows, nCols);
  for (int i = 0; i < nRows; i++) {
    matrix.matrix[i][0] = vector[i];
  }
  this->matrix = matrix.matrix;
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
// CHANGE THIS CODE ITS FUCKING WRONG YOU DUMB DUMB
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

Matrix Matrix::transpose() {
  int aux;
  for (int i = 0; i < this->matrix.size(); i++) {
    for (int j = i; j < this->matrix[0].size(); j++) {
      aux = this->matrix[i][j];
      this->matrix[i][j] = this->matrix[j][i];
      this->matrix[j][i] = aux;
    }
  }
  return *this;
}
