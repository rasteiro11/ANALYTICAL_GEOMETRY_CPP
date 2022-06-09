#include "matrix.cpp"
#include <iostream>
#include <iterator>
#include <vector>
class TestMatrix {
public:
  TestMatrix();
  static void Add();
  static void AddConst();
  static void Sub();
  static void SubConst();
  static void Mult();
  static void MultConst();
  static void EmptyMatrix();
  static void ColumnMatrix();
  static void VecFromMatrix();
};

void TestMatrix::Add() {
  std::cout << Matrix({{1, 2}, {3, 4}}) + Matrix({{1, 2}, {3, 4}}) << std::endl;
}
void TestMatrix::AddConst() {
  std::cout << Matrix({{1, 2}, {3, 4}}) + 1 << std::endl;
}

void TestMatrix::Sub() {
  std::cout << Matrix({{1, 2}, {3, 4}}) - Matrix({{1, 2}, {3, 4}}) << std::endl;
}
void TestMatrix::SubConst() {
  std::cout << Matrix({{1, 2}, {3, 4}}) - 1 << std::endl;
}

void TestMatrix::Mult() {
  std::cout << Matrix({{1, 2}, {3, 4}}) * Matrix({{1, 2}, {3, 4}}) << std::endl;
}
void TestMatrix::MultConst() {
  std::cout << Matrix({{1, 2}, {3, 4}}) * 2 << std::endl;
}

void TestMatrix::EmptyMatrix() { std::cout << Matrix(3, 3) << std::endl; }

int main() {
  // ADD
  std::cout << "ADD" << std::endl;
  TestMatrix::Add();

  // ADD CONST
  std::cout << "ADD CONST" << std::endl;
  TestMatrix::AddConst();

  // SUB
  std::cout << "SUB" << std::endl;
  TestMatrix::Sub();

  // SUB CONST
  std::cout << "SUB CONST" << std::endl;
  TestMatrix::SubConst();

  // MULT
  std::cout << "MULT" << std::endl;
  TestMatrix::Mult();

  // MULT CONST
  std::cout << "MULT CONST" << std::endl;
  TestMatrix::MultConst();

  // CREATE EMPTY MATRIX
  std::cout << "CREATE EMPTY MATRIX" << std::endl;
  std::cout << Matrix(3, 3) << std::endl;

  // CREATE COLUMN MATRIX
  std::cout << "COLUMN EMPTY MATRIX" << std::endl;
  std::cout << Matrix({1, 2, 3}) << std::endl;

  // VEC TO MATRIX
  std::cout << "VEC TO MATRIX" << std::endl;
  std::cout << Matrix({1, 2, 3, 4, 5, 6}, 2, 3) << std::endl;
}
