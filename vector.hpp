
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

/*
 * TODO: Add assertion for dimension
 * TODO: Add assertion for division
 */

template <typename T, int dimension>
class Vector {
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
  Vector(const Vector<U,dimension>& rhs);

  /**
   * @brief    Conversion from a vector type by assignment.
   */
  template <typename U>
  Vector<T,dimension>& operator=(const Vector<U,dimension>& rhs);

  /**
   * @brief    For assigning values to entries in a vector.
   */
  T& operator[] (int index);

  /**
   * @brief    For accessing entries in the vector.
   */
  T operator[] (int index) const;

  Vector<T,dimension> operator-() const;
  Vector<T,dimension>& operator+=(const Vector<T,dimension>& rhs);
  Vector<T,dimension>& operator-=(const Vector<T,dimension>& rhs);

  /**
   * @brief    Addition or subtraction of every
   *           entry by a constant.
   */
  Vector<T,dimension>& operator+=(const T rhs);
  Vector<T,dimension>& operator-=(const T rhs);

  /**
   * @brief    Scalar multiplication/division of vectors.
   */
  Vector<T,dimension>& operator*=(const T rhs);
  Vector<T,dimension>& operator/=(const T rhs);

 private:
  std::array<T,dimension> vector = {};

};

template <typename T, int dimension>
Vector<T,dimension>::Vector()
{
  for (int i=0; i<dimension; i++)
    this->vector[i] = 0;
}

template <typename T, int dimension>
Vector<T,dimension>::Vector(const T vector[])
{
  for (int i=0; i<dimension; i++)
    this->vector[i] = vector[i];
}

template <typename T, int dimension>
template <typename U>
Vector<T,dimension>::Vector(const Vector<U,dimension>& rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] = T(rhs[i]);
}

template <typename T, int dimension>
template <typename U>
Vector<T,dimension>& Vector<T,dimension>::operator=
(const Vector<U,dimension>& rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] = T(rhs[i]);
  return *this;
}

template <typename T, int dimension>
T& Vector<T,dimension>::operator[](int index)
{
  return this->vector[index];
}

template <typename T, int dimension>
T Vector<T,dimension>::operator[](int index) const
{
  return this->vector[index];
}

template <typename T, int dimension>
Vector<T,dimension> Vector<T,dimension>::operator-() const
{
  return (Vector<T,dimension>() - *this);
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator+=(const Vector<T,dimension>& rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] += rhs[i];
  return *this;
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator+=(const T rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] += rhs;
  return *this;
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator-=(const Vector<T,dimension>& rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] -= rhs[i];
  return *this;
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator-=(const T rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] -= rhs;
  return *this;
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator*=(const T rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] *= rhs;
  return *this;
}

template <typename T, int dimension>
Vector<T,dimension>& Vector<T,dimension>::operator/=(const T rhs)
{
  for (int i=0; i<dimension; i++)
    (*this)[i] /= rhs;
  return *this;
}

template <typename T1, typename T2, int dimension>
auto operator+(const Vector<T1,dimension>& lhs, const Vector<T2,dimension>& rhs)
  -> Vector<decltype(lhs[0]+rhs[0]),dimension>
{
  Vector<decltype(lhs[0]+rhs[0]),dimension> ans(lhs);
  ans += rhs;
  return ans;
}

template <typename T, int dimension>
Vector<T,dimension> operator+(Vector<T,dimension> lhs, const Vector<T,dimension>& rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T, int dimension>
Vector<T,dimension> operator+(Vector<T,dimension> lhs, const T rhs)
{
  lhs += rhs;
  return lhs;
}

template <typename T, int dimension>
Vector<T,dimension> operator+(const T lhs, Vector<T,dimension> rhs)
{
  rhs += lhs;
  return rhs;
}

template <typename T1, typename T2, int dimension>
auto operator-(const Vector<T1,dimension>& lhs, const Vector<T2,dimension>& rhs)
  -> Vector<decltype(lhs[0]-rhs[0]),dimension>
{
  Vector<decltype(lhs[0]-rhs[0]),dimension> ans(lhs);
  ans -= rhs;
  return ans;
}

template <typename T, int dimension>
Vector<T,dimension> operator-(Vector<T,dimension> lhs, const Vector<T,dimension>& rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T, int dimension>
Vector<T,dimension> operator-(Vector<T,dimension> lhs, const T rhs)
{
  lhs -= rhs;
  return lhs;
}

template <typename T, int dimension>
Vector<T,dimension> operator-(const T lhs, Vector<T,dimension> rhs)
{
  return (-rhs) += lhs;
}

template <typename T1, typename T2, int dimension>
auto operator*(const Vector<T1,dimension>& lhs, const T2 rhs)
  -> Vector<decltype(lhs[0]*rhs),dimension>
{
  Vector<decltype(lhs[0]*rhs),dimension> ans(lhs);
  ans *= rhs;
  return ans;
}

template <typename T, int dimension>
Vector<T,dimension> operator*(Vector<T,dimension> lhs, const T rhs)
{
  lhs *= rhs;
  return lhs;
}

template <typename T, int dimension>
Vector<T,dimension> operator*(const T lhs, Vector<T,dimension> rhs)
{
  rhs *= lhs;
  return rhs;
}

template <typename T1, typename T2, int dimension>
auto operator/(const Vector<T1,dimension>& lhs, const T2 rhs)
  -> Vector<decltype(lhs[0]*rhs),dimension>
{
  Vector<decltype(lhs[0]*rhs),dimension> ans(lhs);
  ans /= rhs;
  return ans;
}

template <typename T, int dimension>
Vector<T,dimension> operator/(Vector<T,dimension> lhs, const T rhs)
{
  lhs /= rhs;
  return lhs;
}

template <typename T1, typename T2, int dimension>
bool operator==(const Vector<T1,dimension>& lhs, const Vector<T2,dimension>& rhs)
{
  for (int i=0; i<dimension; i++)
    if (lhs[i] != rhs[i])
      return false;
  return true;
}

#endif // VECTOR_HPP_
