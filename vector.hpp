
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

#include <type_traits>

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

template <typename T, int vector_size>
class Vector
{
public:
  static_assert((std::is_same<int, T>::value) ||
		(std::is_same<float, T>::value) ||
		(std::is_same<double, T>::value),
		"T must be of type int, float or double.");

  void set(int index, T value);

  /**
   * @brief    Constructors for the class for a zero vector.
   */
  Vector(){};

  /**
   * @brief    Type cast for other vectors of the same dimension.
   */
  Vector(Vector<int,N> &rhs);
  Vector(Vector<float,N> &rhs);
  Vector(Vector<double,N> &rhs);
  
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
  T vector[vector_size] = {};
};

template <typename T, int vector_size>
Vector<T,vector_size>::Vector(Vector<int,vector_size> &rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] = T(rhs.vector[i]);
}

template <typename T, int vector_size>
Vector<T,vector_size>::Vector(Vector<float,vector_size> &rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] = T(rhs.vector[i]);
}

template <typename T, int vector_size>
Vector<T,vector_size>::Vector(Vector<double,vector_size> &rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] = T(rhs.vector[i]);
}

template <typename T, int vector_size>
void Vector<T,vector_size>::set(int index, T value)
{
  this->vector[index] = value;
}

template <typename T, int vector_size>
Vector<T,vector_size> Vector<T,vector_size>::operator-() const
{
  return (Vector<T,vector_size>() - *this);
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator+=(const Vector<T,vector_size>& rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] += rhs.vector[i];
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator+=(const T rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] += rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator-=(const Vector<T,vector_size> &rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] += rhs.vector[i];
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator-=(const T rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] -= rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator*=(const T rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] *= rhs;
  return *this;
}

template <typename T, int vector_size>
Vector<T,vector_size> &Vector<T,vector_size>::operator/=(const T rhs)
{
  for(int i=0;i<vector_size;i++)
    this->vector[i] /= rhs;
  return *this;
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

template <typename T, int vector_size>
Vector<T,vector_size> operator/(Vector<T,vector_size> lhs, const T rhs)
{
  lhs /= rhs;
  return lhs;
}

template <typename T1, typename T2, int vector_size>
bool operator==(const Vector<T1,vector_size>& lhs, const Vector<T2,vector_size>& rhs)
{
  for(int i=0;i<vector_size;i++)
    if(lhs.vector[i] != rhs.vector[i])
      return false;
  return true;
}

#endif // VECTOR_HPP_
