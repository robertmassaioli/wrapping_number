#include "wrapping_number.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  wrapped_int<int, 4, 80> wn;

  wn = 10;

  cout << "WN is " << wn << endl;
  cout << (wn == 6) << endl;
  cout << (wn == 10) << endl;
  cout << (wn == 3) << endl;
  cout << (6 == wn) << endl;

  wrapped_int<int, 4, 80> new_wn = wn + 9;
  wn += 9;
  cout << "Add nine: " << wn << endl; 
  cout << "New: " << new_wn << endl; 
  //cout << "Add nine: " << (wn + 9) << endl; 
  
  for(int i = 0; i < 100; ++i) {
    //cout << wn-- << endl;
  }

  return 0;
}
