/*
  TODO: Add hyped header comments
  TODO: Check if static is needed
  TODO: Decide the process noise value
  TODO: Check if estimation_error is needed as an arguement
  TODO: Add hyped header comments
  TODO: Check if static is needed
  TODO: Decide the process noise value
  TODO: Check if estimation_error is needed as an arguement
  TODO: Decide value of process noise
*/

#ifndef HYPED_NAVIGATION_KALMAN_HPP_
#define HYPED_NAVIGATION_KALMAN_HPP_

template<typename T>
class Kalman {
  
 public:
  
  Kalman (T input_value, T measurement_noise, T estimation_error = 0)
    : measurement_noise_covariance_(measurement_noise),
    estimation_error_covariance_(estimation_error),
    filtered_value_(input_value)
    {}
  
  T filter (T input) {
    estimation_error_covariance_ += k_process_noise_;
    kalman_gain_ = estimation_error_covariance_ /
      (estimation_error_covariance_ + measurement_noise_covariance_);
    filtered_value_ += kalman_gain_ * (input - filtered_value_);
    estimation_error_covariance_ = (1 - kalman_gain_) * estimation_error_covariance_;
    
    return filtered_value_;
  }
  
 private:
  const T k_process_noise_{0.01};
  
  T measurement_noise_covariance_;
  T estimation_error_covariance_;
  T kalman_gain_;
  T filtered_value_;
  
};

#endif  // HYPED_NAVIGATION_KALMAN_HPP_
