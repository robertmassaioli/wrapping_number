#ifndef __WRAPPING_NUMBER__
#define __WRAPPING_NUMBER__

#include <cassert>
#include <ostream>

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

    void operator+=(int_type_ t) {
      value = keepValueInRange(value + t);
    }

    // pre-increment
    wrapped_int<int_type_, wrapped_min, wrapped_max>& operator++() { value = keepValueInRange(++value); return *this; }
    wrapped_int<int_type_, wrapped_min, wrapped_max>& operator--() { value = keepValueInRange(--value); return *this; }

    // post-increment
    const wrapped_int<int_type_, wrapped_min, wrapped_max> operator++(int);
    //const wrapped_int<int_type_, wrapped_min, wrapped_max> operator--(int);

    const wrapped_int<int_type_, wrapped_min, wrapped_max> operator++(int) { 
      wrapped_int<int_type_, wrapped_min, wrapped_max> new_w = *this; 
      ++(*this); 
      return new_w; 
    } 

    const wrapped_int<int_type_, wrapped_min, wrapped_max> operator--(int) { 
      wrapped_int<int_type_, wrapped_min, wrapped_max> new_w = *this; 
      --(*this); 
      return new_w; 
    }

    void operator-=(int_type_ t) {
      value = keepValueInRange(value - t);
    }

    int_type_ get() const { return value; }
      
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

template<typename int_type_, int_type_ wrapped_min, int_type_ wrapped_max>
std::ostream& operator<<(std::ostream& out, wrapped_int<int_type_, wrapped_min, wrapped_max>& wi) {
  return out << wi.get();
}
  
template<typename int_type_, int_type_ wrapped_min, int_type_ wrapped_max>
wrapped_int<int_type_, wrapped_min, wrapped_max> operator+(wrapped_int<int_type_, wrapped_min, wrapped_max>& wi, int_type_ t) {
  wrapped_int<int_type_, wrapped_min, wrapped_max> new_wi;
  new_wi = wi.get();
  new_wi += t;
  return new_wi;
}

template<typename int_type_, int_type_ wrapped_min, int_type_ wrapped_max>
wrapped_int<int_type_, wrapped_min, wrapped_max> operator+(int_type_ t, wrapped_int<int_type_, wrapped_min, wrapped_max>& wi) {
  wrapped_int<int_type_, wrapped_min, wrapped_max> new_wi;
  new_wi = wi.get();
  new_wi += t;
  return new_wi;
}

#endif
