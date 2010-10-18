#ifndef __WRAPPING_NUMBER__
#define __WRAPPING_NUMBER__

#include <cassert>

// the range is [wrapped_min, wrapped_max)
template<typename int_type_, int_type_ wrapped_min, int_type_ wrapped_max>
class wrapped_int {
  public:
    void operator=(int_type_ t) {
      assert(wrapped_max > wrapped_min);
      value = keepValueInRange(t);
    }

    bool operator==(int_type_ t) {
      return value == keepValueInRange(t);
    }
      
  private:
    int_type_ value;

    int_type_ keepValueInRange(int_type_ val) {
      int_type_ range = wrapped_max - wrapped_min;
      while(val >= wrapped_max) val -= range;
      while(val < wrapped_min) val += range;
      return val;
    }
};

template<typename int_type_, int_type_ wrapped_min, int_type_ wrapped_max>
bool operator==(int_type_ t, wrapped_int<int_type_, wrapped_min, wrapped_max>& wi) {
  return wi == t;
}

#endif
