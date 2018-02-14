/*
  TODO: Add hyped header comments
  TODO: stackoverflow.com/questions/874298/c-templates-that-accept-only-certain-types
  TODO: Check if array can be used.
  TODO: How to handle if array if of different size?
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>

template<typename T>
class Vector
{
  public:
  std::vector<T> vector;

  Vector<T>(int n)
  {
    vector.resize(n,0);
  }

  int size() const;
  void set(int index, T value);
  
  Vector<T> operator-(Vector<T> rhs);
  
  Vector<T> &operator+=(const Vector<T> &rhs);
  Vector<T> &operator+=(const T rhs);
  
  Vector<T> &operator-=(const Vector<T> &rhs);
  Vector<T> &operator-=(const T rhs);
  
  Vector<T> &operator*=(const T rhs); //scalar multiplication  
  Vector<T> &operator/=(const T rhs); // scalar division
};

template<typename T>
int Vector<T>::size() const
{
  return this->vector.size();
}

template<typename T>
void Vector<T>::set(int index, T value)
{
  this->vector[index] = value;
}

template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> rhs)
{
  for(int i=0;i<rhs.size();i++)
    rhs.vector[i] = -rhs.vector[i];
  return rhs;
}

template<typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T>& rhs)
{
  for(int i=0;i<rhs.size();i++)
    {
      this->vector[i] += rhs.vector[i];
    }
  return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator+=(const T rhs)
{
  int vectorSize = this->vector.size();
  for(int i=0;i<vectorSize;i++)
    {
      this->vector[i] += rhs;
    }
  return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &rhs)
{
  *this += -rhs;
  return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator-=(const T rhs)
{
  *this += -rhs;
  return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator*=(const T rhs)
{
  int vectorSize = this->vector.size();
  for(int i=0;i<vectorSize;i++)
    {
      this->vector[i] *= rhs;
    }
  return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator/=(const T rhs)
{
  int vectorSize = this->vector.size();
  for(int i=0;i<vectorSize;i++)
    {
      this->vector[i] /= rhs;
    }
  return *this;
}


template<typename T>
Vector<T> operator+(Vector<T> lhs, const Vector<T> &rhs)
{
  lhs += rhs;
  return lhs;
}

template<typename T>
Vector<T> operator+(Vector<T> lhs, const T rhs)
{
  lhs += rhs;
  return lhs;
}

template<typename T>
Vector<T> operator+(const T lhs, Vector<T> rhs)
{
  rhs += lhs;
  return rhs;
}

template<typename T>
Vector<T> operator-(Vector<T> lhs, const Vector<T> &rhs)
{
  lhs -= rhs;
  return lhs;
}

template<typename T>
Vector<T> operator-(Vector<T> lhs, const T rhs)
{
  lhs -= rhs;
  return lhs;
}

template<typename T>
Vector<T> operator-(const T lhs, Vector<T> rhs)
{
  return (-rhs) += lhs;
}

template<typename T>
Vector<T> operator*(Vector<T> lhs, const T rhs)
{
  lhs *= rhs;
  return lhs;
}

template<typename T>
Vector<T> operator*(const T lhs, Vector<T> rhs)
{
  rhs *= lhs;
  return rhs;
}

template<typename T>
Vector<T> operator/(Vector<T> lhs, const T rhs)
{
  lhs /= rhs;
  return lhs;
}

template<typename T1, typename T2>
bool operator==(const Vector<T1>& lhs, const Vector<T2>& rhs)
{
  if(lhs.size() == rhs.size())
    {
      for(int i=0;i<lhs.size();i++)
	if(lhs.vector[i] != rhs.vector[i])
	  return false;
      return true;
    }
  return false;
}

// TODO: Consider cleaning this up.
/*template<typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &v)
{
  out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return out;
}//*/

#endif // VECTOR_H_
