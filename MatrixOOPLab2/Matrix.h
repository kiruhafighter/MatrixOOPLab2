#ifndef MATRIX_H
#define Matrix_H
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Matrix {
    int m_rows, m_cols;
    double* m_values;
public:
    Matrix(); 
    Matrix(int rows, int cols); 
    Matrix(const Matrix& other);
    ~Matrix();
    bool can_multiply(const Matrix& other);
    Matrix multiply(const Matrix& other);
    void generate_1(); 
    double get(int i, int j)const; 
    bool read_keyboard();
    void print_screen();
    void write_to_file(string path);
    void read_from_file(string path);
    bool equal_size(const Matrix& other);
    void add(const Matrix& other);
    void sub(const Matrix& other);
    int rows() const;
    int cols() const;
    Matrix transpose();
    void resize(int rows, int cols);
    void add(double value);
    void sub(double value);
    void multiply(double value);
    void operator()(int rows, int cols);
    Matrix* operator->()const;
};




#endif


