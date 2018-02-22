
/*
 * Author: Branislav Pilnan, Uday Patel
 * Organisation: HYPED
 * Date: 17 February 2018
 * Description: K-dimensional vector class that supports 
 *              addition, substraction, scalar multiplication,
 *              scalar division.
 *
 *    Copyright 2018 HYPED
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <array>

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template <typename T, int vector_size>
class Vector
{
public:
  
  /**
   * @brief    Constructors for the class for a zero vector.
   */
  Vector();

  /**
   * @brief    Constructors for the class for a particular vector.
   */
  Vector(const T vector[]);

  /**
   * @brief    Conversion from a vector type to another.
   */
  template <typename U>
  Vector(const Vector<U,vector_size> &rhs);

  /**
   * @brief    Conversion from a vector type by assignment.
   */
  template <typename U>
  Vector<T,vector_size> &operator=(const Vector<U,vector_size> &rhs);

  /**
   * @brief    For assigning values to entries in a vector.
   */
  T &operator[] (int index);
  
  /**
   * @brief    For accessing entries in the vector.
   */
  T operator[] (int index) const;
  
  Vector<T,vector_size> operator-() const;

  Vector<T,vector_size> &operator+=(const Vector<T,vector_size> &rhs);
  Vector<T,vector_size> &operator-=(const Vector<T,vector_size> &rhs);

  /**
   * @brief    Addition or subtraction of every 
   *           entry by the parameter.
   */  
  Vector<T,vector_size> &operator+=(const T rhs);
  Vector<T,vector_size> &operator-=(const T rhs);

  /**
   * @brief    Scalar multiplication/division of vectors.
   */
  Vector<T,vector_size> &operator*=(const T rhs);
  Vector<T,vector_size> &operator/=(const T rhs);

private:
  std::array<T,vector_size> vector = {};
  
};

template <typename T, int vector_size>
Vector<T,vector_size>::Vector()
{
  for(int i=0; i<vector_size; i++)
    this->vector[i] = 0;
}

template <typename T, int vector_size>
Vector<T,vector_size>::Vector(const T vector[])
{
  for(int i=0; i<vector_size; i++)
    this->vector[i] = vector[i];
}

template <typename T, int vector_size>
template <typename U>
Vector<T,vector_size>::Vector(const Vector<U,vector_size> &rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] = T(rhs[i]);
}

template <typename T, int vector_size>
template <typename U>
Vector<T,vector_size> &Vector<T,vector_size>::operator=
(const Vector<U,vector_size> &rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] = T(rhs[i]);
  return *this;
}

template <typename T, int vector_size>
T &Vector<T,vector_size>::operator[](int index)
{
  return this->vector[index];
}

template <typename T, int vector_size>
T Vector<T,vector_size>::operator[](int index) const
{
  return this->vector[index];
}

template <typename T, int vector_size>
Vector<T,vector_size> Vector<T,vector_size>::operator-() const
{
  return (Vector<T,vector_size>() - *this);
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator+=(const Vector<T,vector_size>& rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] += rhs[i];
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator+=(const T rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] += rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator-=(const Vector<T,vector_size> &rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] -= rhs[i];
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator-=(const T rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] -= rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator*=(const T rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] *= rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator/=(const T rhs)
{
  for(int i=0; i<vector_size; i++)
    (*this)[i] /= rhs;
  return *this;
}

template <typename T1, typename T2, int vector_size>
auto operator+(const Vector<T1,vector_size> &lhs, const Vector<T2,vector_size> &rhs)
  -> Vector<decltype(lhs[0]+rhs[0]),vector_size>
{
  Vector<decltype(lhs[0]+rhs[0]),vector_size> ans(lhs);
  ans += rhs;
  return ans;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator+(Vector<T,vector_size> lhs, const Vector<T,vector_size> &rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator+(Vector<T,vector_size> lhs, const T rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator+(const T lhs, Vector<T,vector_size> rhs)
{
  rhs += lhs;
  return rhs;
}

template <typename T1, typename T2, int vector_size>
auto operator-(const Vector<T1,vector_size> &lhs, const Vector<T2,vector_size> &rhs)
  -> Vector<decltype(lhs[0]-rhs[0]),vector_size>
{
  Vector<decltype(lhs[0]-rhs[0]),vector_size> ans(lhs);
  ans -= rhs;
  return ans;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator-(Vector<T,vector_size> lhs, const Vector<T,vector_size> &rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator-(Vector<T,vector_size> lhs, const T rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator-(const T lhs, Vector<T,vector_size> rhs)
{
  return (-rhs) += lhs;
}

template <typename T1, typename T2, int vector_size>
Vector<double,vector_size> operator*(const Vector<T1,vector_size> &lhs, const T2 rhs)
{
  Vector<double,vector_size> ans(lhs);
  ans *= double(rhs);
  return ans;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator*(Vector<T,vector_size> lhs, const T rhs)
{
  lhs *= rhs;
  return lhs;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator*(const T lhs, Vector<T,vector_size> rhs)
{
  rhs *= lhs;
  return rhs;
}

template <typename T1, typename T2, int vector_size>
Vector<double,vector_size> operator/(const Vector<T1,vector_size> &lhs, const T2 rhs)
{
  Vector<double,vector_size> ans(lhs);
  ans /= double(rhs);
  return ans;
}

template <typename T, int vector_size>
Vector<T,vector_size> operator/(Vector<T,vector_size> lhs, const T rhs)
{
  lhs /= rhs;
  return lhs;
}

template <typename T1, typename T2, int vector_size>
bool operator==(const Vector<T1,vector_size>& lhs, const Vector<T2,vector_size>& rhs)
{
  for(int i=0; i<vector_size; i++)
    if(lhs[i] != rhs[i])
      return false;
  return true;
}

#endif // VECTOR_HPP_
