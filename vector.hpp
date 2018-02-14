/*
  TODO: Add hyped header comments
  TODO: stackoverflow.com/questions/874298/c-templates-that-accept-only-certain-types
*/

#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T, int N>
class Vector
{
  public:
  T vector[N] = {};
  int vectorSize = N;

  Vector() {}

  int size();
  void set(int index, T value);
  
  Vector<T,N> operator-() const;
  
  Vector<T,N> &operator+=(const Vector<T,N> &rhs);
  Vector<T,N> &operator+=(const T rhs);
  
  Vector<T,N> &operator-=(const Vector<T,N> &rhs);
  Vector<T,N> &operator-=(const T rhs);
  
  Vector<T,N> &operator*=(const T rhs); //scalar multiplication  
  Vector<T,N> &operator/=(const T rhs); // scalar division
};

template<typename T, int N>
int Vector<T,N>::size()
{
  return this->vectorSize;
}

template <typename T,int N>
void Vector<T,N>::set(int index, T value)
{
  this->vector[index] = value;
}

template <typename T,int N>
Vector<T,N> Vector<T,N>::operator-() const
{
  return (Vector<T,N>() - *this);
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator+=(const Vector<T,N>& rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] += rhs.vector[i];
  return *this;
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator+=(const T rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] += rhs;
  return *this;
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator-=(const Vector<T,N> &rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] += rhs.vector[i];
  return *this;
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator-=(const T rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] -= rhs;
  return *this;
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator*=(const T rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] *= rhs;
  return *this;
}

template <typename T,int N>
Vector<T,N> &Vector<T,N>::operator/=(const T rhs)
{
  for(int i=0;i<N;i++)
    this->vector[i] /= rhs;
  return *this;
}


template <typename T,int N>
Vector<T,N> operator+(Vector<T,N> lhs, const Vector<T,N> &rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T,int N>
Vector<T,N> operator+(Vector<T,N> lhs, const T rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T,int N>
Vector<T,N> operator+(const T lhs, Vector<T,N> rhs)
{
  rhs += lhs;
  return rhs;
}

template <typename T,int N>
Vector<T,N> operator-(Vector<T,N> lhs, const Vector<T,N> &rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T,int N>
Vector<T,N> operator-(Vector<T,N> lhs, const T rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T,int N>
Vector<T,N> operator-(const T lhs, Vector<T,N> rhs)
{
  return (-rhs) += lhs;
}

template <typename T,int N>
Vector<T,N> operator*(Vector<T,N> lhs, const T rhs)
{
  lhs *= rhs;
  return lhs;
}

template <typename T,int N>
Vector<T,N> operator*(const T lhs, Vector<T,N> rhs)
{
  rhs *= lhs;
  return rhs;
}

template <typename T,int N>
Vector<T,N> operator/(Vector<T,N> lhs, const T rhs)
{
  lhs /= rhs;
  return lhs;
}

template <typename T1, typename T2,int N>
bool operator==(const Vector<T1,N>& lhs, const Vector<T2,N>& rhs)
{
  for(int i=0;i<N;i++)
    if(lhs.vector[i] != rhs.vector[i])
      return false;
  return true;
}

#endif // VECTOR_H_
