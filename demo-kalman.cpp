#include "kalman.hpp"
#include <iostream>
using namespace std;

int main()
{
  Kalman<float> kalman(0,1,1);
  for(int i=0;i<100;i++)
    cout << kalman.filter(i) << '\t';
  cout << '\n';
}
