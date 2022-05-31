#include "assert.h"
#include "vector.cpp"
#include <iostream>
#include <ostream>

class TestVector {
public:
  TestVector();
  static void Add();
  static void AddConst();
  static void Sub();
  static void SubConst();
  static void Mult();
  static void MultConst();
  static void Div();
  static void DivConst();
};

void TestVector::Add() {
  Vector *vec_1 = new Vector(std::vector<double>({210, 210}));
  Vector *vec_2 = new Vector(std::vector<double>({210, 210}));
  Vector vec_3 = *vec_1 + *vec_2;
  std::cout << vec_3 << std::endl;
}

void TestVector::Sub() {
  Vector *vec_1 = new Vector(std::vector<double>({210, 210}));
  Vector *vec_2 = new Vector(std::vector<double>({210, 210}));
  Vector vec_3 = *vec_1 - *vec_2;
  std::cout << vec_3 << std::endl;
}

void TestVector::Mult() {
  Vector *vec_1 = new Vector(std::vector<double>({23, 23}));
  Vector *vec_2 = new Vector(std::vector<double>({3, 3}));
  Vector vec_3 = *vec_1 * *vec_2;
  std::cout << vec_3 << std::endl;
}

void TestVector::Div() {
  Vector *vec_1 = new Vector(std::vector<double>({840, 840}));
  Vector *vec_2 = new Vector(std::vector<double>({2, 2}));
  Vector vec_3 = *vec_1 / *vec_2;
  std::cout << vec_3 << std::endl;
}

void TestVector::AddConst() {
  Vector *vec_1 = new Vector(std::vector<double>({210, 210}));
  Vector vec_2 = *vec_1 + 210;
  std::cout << vec_2 << std::endl;
}
void TestVector::SubConst() {
  Vector *vec_1 = new Vector(std::vector<double>({630, 630}));
  Vector vec_2 = *vec_1 - 210;
  std::cout << vec_2 << std::endl;
}

void TestVector::MultConst() {
  Vector *vec_1 = new Vector(std::vector<double>({120, 120}));
  Vector vec_2 = *vec_1 * 4;
  std::cout << vec_2 << std::endl;
}

void TestVector::DivConst() {
  Vector *vec_1 = new Vector(std::vector<double>({840, 840}));
  Vector vec_2 = *vec_1 / 2;
  std::cout << vec_2 << std::endl;
}

int main() {

  // ADD
  std::cout << "ADD" << std::endl;
  TestVector::Add();
  std::cout << "ADD CONST" << std::endl;
  TestVector::AddConst();

  // SUB
  std::cout << "SUB" << std::endl;
  TestVector::Sub();
  std::cout << "SUB CONST" << std::endl;
  TestVector::SubConst();

  // MULT
  std::cout << "MULT" << std::endl;
  TestVector::Mult();
  std::cout << "MULT CONST" << std::endl;
  TestVector::MultConst();

  // DIV
  std::cout << "DIV" << std::endl;
  TestVector::Div();
  std::cout << "DIV CONST" << std::endl;
  TestVector::DivConst();
}
