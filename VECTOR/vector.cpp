#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <math.h>
#include <ostream>
#include <stdexcept>
#include <vector>

class DiffVecSpaceError : std::exception {};

class Vector {
private:
  std::vector<double> vec;

public:
  Vector(std::vector<double> vec);
  double get(size_t index);
  void set(size_t index, double value);
  std::vector<double> &getVector();
  friend std::ostream &operator<<(std::ostream &o, const Vector &vec);
  Vector operator+(const Vector &other);
  Vector operator-(const Vector &other);
  Vector operator*(const Vector &other);
  Vector operator+(const double d);
  Vector operator-(const double d);
  Vector operator*(const double d);
  Vector operator/(const double d);
  Vector operator^(const double d);
  Vector sqrt(const double d);
  double norm();
  double innerProduct(const Vector &other);
  double angle(Vector &other);
};

Vector::Vector(std::vector<double> vec) { this->vec = vec; }

std::ostream &operator<<(std::ostream &out, const Vector &vec) {
  std::vector<double> temp_vec = vec.vec;
  out << "(";
  for (int i = 0; i < temp_vec.size(); i++) {
    (i == temp_vec.size() - 1) ? out << temp_vec.at(i)
                               : out << temp_vec.at(i) << ", ";
  }
  out << ")";
  return out;
}

std::vector<double> &Vector::getVector() { return this->vec; }

double Vector::get(size_t index) { return this->vec.at(index); }

void Vector::set(size_t index, double value) {
  this->getVector()[index] = value;
}

Vector Vector::operator+(const Vector &other) {

  if (this->vec.size() != other.vec.size()) {
    throw DiffVecSpaceError();
  }

  Vector temp = Vector(other.vec);
  int i = 0;
  for (double d : this->getVector()) {
    temp.vec[i] += d;
    i++;
  }
  return temp;
}

Vector Vector::operator+(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] += d;
  }
  return result;
}

Vector Vector::operator-(const Vector &other) {
  if (this->vec.size() != other.vec.size()) {
    throw DiffVecSpaceError();
  }
  Vector result = Vector(other.vec);
  int i = 0;
  for (double d : this->getVector()) {
    result.vec[i] -= d;
    i++;
  }
  return result;
}

Vector Vector::operator-(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] -= d;
  }
  return result;
}

Vector Vector::operator*(const Vector &other) {
  if (this->vec.size() != other.vec.size()) {
    throw DiffVecSpaceError();
  }
  Vector result = Vector(other.vec);
  int i = 0;
  for (double d : this->getVector()) {
    result.vec[i] *= d;
    i++;
  }
  return result;
}

Vector Vector::operator*(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] *= d;
  }
  return result;
}

Vector Vector::operator^(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] = std::pow(result.vec[i], d);
  }
  return result;
}

Vector Vector::operator/(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] /= d;
  }
  return result;
}

Vector Vector::sqrt(const double d) {
  Vector result = Vector(this->vec);
  for (int i = 0; i < this->vec.size(); i++) {
    result.vec[i] = pow(result.vec[i], (double)1 / d);
  }
  return result;
}

double Vector::norm() {
  double norm = 0;
  for (int i = 0; i < this->vec.size(); i++) {
    norm += std::pow(this->vec[i], 2);
  }
  return std::sqrt(norm);
}

double Vector::innerProduct(const Vector &other) {
  int innerProduct = 0;
  if (this->vec.size() != other.vec.size()) {
    throw DiffVecSpaceError();
  }
  for (int i = 0; i < this->vec.size(); i++) {
    innerProduct += this->vec[i] * other.vec[i];
  }
  return innerProduct;
}

double Vector::angle(Vector &other) {
  double dotProduct = this->innerProduct(other);
  double thisNorm = this->norm();
  double otherNorm = other.norm();
  return acos(dotProduct / (thisNorm * otherNorm));
}
