#include "vector.hpp"
#include <iostream>

void print(Vector<int> &v)
{
  for(int x : v)
    std::cout << x << '\t';
  std::cout << '\n';
}

int main()
{
  Vector<int> vector1(10);
  Vector<int> vector2(10);
  Vector<int> vector3(10);

  for(int i=0;i<10;i++)
    vector1.set(i,i+1);

  vector3 = vector2 + 1;
  vector3 = vector1 + vector2;

  vector3 = vector2 - 2;
  vector3 = vector1 - vector2;

  vector3 = vector1 * 5;
  vector3 = vector1 / 5;

  (vector1 == vector3) ? std::cout << "False" : std::cout << "True";
  
  print(vector1);
  print(vector2);
  print(vector3);
}
