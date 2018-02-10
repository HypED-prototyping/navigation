#include "kalman.hpp"
#include <iostream>

int main()
{
  Kalman<float> kalman(0,1,1);
  for(int i=0;i<100;i++)
    std::cout << kalman.filter(i) << '\t';
  std::cout << '\n';
}
