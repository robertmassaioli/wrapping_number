#include "wrapping_number.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  wrapped_int<int, 4, 8> wn;

  wn = 10;

  cout << "WN is " << wn << endl;
  cout << (wn == 6) << endl;
  cout << (wn == 10) << endl;
  cout << (wn == 3) << endl;
  cout << (6 == wn) << endl;

  wn += 9;
  cout << "Add nine: " << wn << endl; 

  return 0;
}
