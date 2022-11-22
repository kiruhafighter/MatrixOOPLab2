#include <iostream>
#include <string>
#include <iomanip>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    cout << "enter m1 matrix: " << endl;
    m1.read_keyboard();
    cout << "enter m2 matrix: " << endl;
    m2.read_keyboard();
    cout << "your m1 matrix: " << endl;
    m1.print_screen();
    cout << "your m2 matrix: " << endl;
    m2.print_screen();

    Matrix mul = m1.multiply(m2);
    cout << "m1 * m2:" << endl;
    mul.print_screen();
    mul.write_to_file("C:\\Users\\kiruhafighter\\Desktop\\2.txt");
    mul.read_from_file("C:\\Users\\kiruhafighter\\Desktop\\1.txt");
    return 0;
}