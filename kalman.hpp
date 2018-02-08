// TODO: Add hyped header comments

template<typename T>
class Kalman {
  
public:

  // TODO: Check if static is needed
  // TODO: Decide the process noise value
  // TODO: Check if estimation_error is needed as an arguement
  
  // TODO: Add hyped header comments
  
  // TODO: Check if static is needed
  // TODO: Decide the process noise value
  // TODO: Check if estimation_error is needed as an arguement
  
  Kalman (T input_value, T measurement_noise,
		  T estimation_error = 0) {
    filtered_value_ = input_value;
    estimation_error_covariance_ = estimation_error;
    measurement_noise_covariance_ = measurement_noise;
  }
  
  T filter (T input) {
    estimation_error_covariance_ += k_process_noise_;
    kalman_gain_ = estimation_error_covariance_ /
      (estimation_error_covariance_ + measurement_noise_covariance_);
    filtered_value_ += kalman_gain_ * (input - filtered_value_);
    estimation_error_covariance_ = (1 - kalman_gain_) *
      estimation_error_covariance_;
    
    return filtered_value_;
  }
  
private:
  // TODO: Convert to vector class
  // TODO: Make this a constant T
  T k_process_noise_;
  
  T measurement_noise_covariance_;
  T estimation_error_covariance_;
  T kalman_gain_;
  T filtered_value_;
  
};
