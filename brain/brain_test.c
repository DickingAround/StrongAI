#ifndef brain_test_c
#define brain_test_c
#include "brain.h"
//---------
// Testing 
//---------
int brain_test_makeDecision();
int brain_test() {
 if (brain_test_makeDecision() == 0) {
  printf("Failed: Brain Decision\n");
  return 0; }
 return 1;
}

int brain_test_makeDecision() {
 brain *br;
 brain_makeNew(br, 2);
}
#endif
