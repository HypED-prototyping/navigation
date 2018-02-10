/*
 * Author:
 * Organisation: HYPED
 * Date:
 * Description:
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

#ifndef HYPED_NAVIGATION_NAVIGATION_HPP_
#define HYPED_NAVIGATION_NAVIGATION_HPP_

#include "kalman.hpp"

class Navigation {
 public:

  // TODO: Change the return values for the private methods to vector/quaternion

  void update();
  float get_accleration();
  float get_velocity();
  float get_displacement();

 private:
  // TODO: Add the arguements for the private methods

  void gyro_update();  // Point number 1
  void acclerometer_update();  // Point number 3, 4, 5 and 6
  void proximity_orientation_update();  // Point number 7
  void proximity_displacement_update();  // Point number 7
  void stripe_counter_update(); // Point number 7
  //float velocity_update();  // Point number 4 and 5

  // TODO: Change the data types of the data members

  float accleration_;
  float velocity_;
  float displacement_;
  float orientation_;
  int stripe_count_;
  Kalman acclerometer_filter_;
  Kalman gyro_filter_;
  Kalman proximity_filter_;
};

#endif // HYPED_NAVIGATION_NAVIGATION_HPP_