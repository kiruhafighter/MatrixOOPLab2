#include "Matrix.h"
#include <iomanip>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
Matrix::Matrix() {
    m_rows = 0;
    m_cols = 0;
    m_values = nullptr;
}
Matrix::Matrix(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_values = new double[m_cols * m_rows];
}
Matrix::Matrix(const Matrix& other) {
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_values = new double[m_cols * m_rows];
    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_values[i] = other.m_values[i];
    }
}
Matrix::~Matrix() {
    if (nullptr != m_values)
        delete[] m_values;
}
void Matrix::generate_1() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (i == j) {
                m_values[i * m_cols + j] = 1;
            }
            else {
                m_values[i * m_cols + j] = 0;
            }
        }
    }
}
double Matrix::get(int i, int j)const {
    return m_values[i * m_cols + j];
}
bool Matrix::can_multiply(const Matrix& other) 
{
    return m_rows == other.m_cols;
}
Matrix Matrix::multiply(const Matrix& other) 
{
    if (false == can_multiply(other)) {
        Matrix empty;
        return empty;
    }
    Matrix result(m_rows, other.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < other.m_cols; j++) {
            result.m_values[i * m_cols + j] = 0;
            for (int k = 0; k < m_cols; k++) {
                result.m_values[i * m_cols + j] += get(i, k) * other.get(k, j);
            }
        }
    }
    return result;
}
bool Matrix::read_keyboard() {
    if (m_values == nullptr) {
        cout << "memory not allocated";
        return false;
    }
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cout << "[" << i << "]" << "[" << j << "] = ";
            cin >> m_values[i * m_cols + j];
        }
    }
    return true;
}
void Matrix::print_screen() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cout << fixed << setprecision(1) << m_values[i * m_cols + j] << " ";
        }
        cout << endl;
    }
}
void Matrix::write_to_file(string path)
{
    fstream myFile;
    myFile.open(path);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            myFile << fixed << setprecision(1) << m_values[i * m_cols + j] << " ";
        }
        myFile << endl;
    }
    cout << "Matrix has been succesfully written to the file " << endl;
    myFile.close();
}
void Matrix::read_from_file(string path)
{
    string matrix_output;
    ifstream MyReadFile(path);
    while (getline(MyReadFile, matrix_output)) {
        // Output the text from the file
        cout << matrix_output;
    }
    MyReadFile.close();
}
bool Matrix::equal_size(const Matrix& other) {
    return m_rows == other.m_rows && m_cols == other.m_cols;
}
void Matrix::add(const Matrix& other) {
    if (equal_size(other) == false)
        return;
    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_values[i] += other.m_values[i];
    }
}
void Matrix::sub(const Matrix& other) {
    if (equal_size(other) == false)
        return;
    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_values[i] -= other.m_values[i];
    }
}
Matrix Matrix::transpose() {
    Matrix other(m_cols, m_rows);
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            other.m_values[j * other.m_cols + i] = m_values[i * m_cols + j];
        }
    }
    return other;
}
int Matrix::rows() const {
    return m_rows;
}
int Matrix::cols() const {
    return m_cols;
}
void Matrix::resize(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    if (m_values)
        delete[] m_values;
    m_values = new double[m_rows * m_cols];
}
void Matrix::add(double value) {
    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_values[i] += value;
    }
}
void Matrix::sub(double value) {
    add(-value);
}
void Matrix::multiply(double value) {
    for (int i = 0; i < m_rows * m_cols; ++i) {
        m_values[i] *= value;
    }
}

void Matrix::operator()(int rows, int cols) {
    if (get(rows, cols) != NULL) {
        m_values[rows * m_cols + cols] = 9;
    }
    else {
        cout << "Err" << endl;
    }
}



