#include "vector.hpp"
#include <iostream>

template <typename T,int N>
void print(Vector<T,N> &v)
{
  for(int i=0;i<N;i++)
    std::cout << v.vector[i] << '\t';
  std::cout << '\n';
}

int main()
{
  Vector<int,10> vector1;
  Vector<int,10> vector2;
  Vector<int,10> vector3;
  Vector<double,10> vector4;
    
  print(vector1);
  print(vector2);
  print(vector3);

  for(int i=0;i<10;i++)
    vector1.set(i,i+1),
      vector4.set(i,1.1);
  
  print(vector4);

  vector2 += 1;
  vector3 = vector1 + vector2;

  vector2 = vector2 - 2;
  vector3 = vector1 - vector2;

  vector3 = vector1 * 5;
  vector3 = vector1 / 5;

  vector4 = vector4 + Vector<double,10>(vector1);
  
  (vector1 == vector3) ? std::cout << "False" :
    std::cout << "True"; std :: cout << '\n';
      
  print(vector1);
  print(vector2);
  print(vector3);
  print(vector4);

}
