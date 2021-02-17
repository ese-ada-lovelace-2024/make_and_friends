#include <iostream>
#include <Eigen/Dense>
 
using namespace Eigen;
 
int main()
{
  MatrixXd A(2,2), B(2,2);
  A(0,0) = 3;
  A(1,0) = 2.5;
  A(0,1) = -1;
  A(1,1) = A(1,0) + A(0,1);

  B << 1, 2,
       0, 1,
        

  std::cout << "Here is the matrix A:\n" << A << std::endl;
  std::cout << "Here is the matrix B:\n" << B << std::endl;
  VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
  std::cout << "Here is  AB:\n" << A*B << std::endl;
  std::cout << "Here is  (A+B)v:\n" << (A+B)*v << std::endl;
}