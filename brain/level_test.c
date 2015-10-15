#ifndef level_test_c
#define level_test_c
#include "level.h"
//---------
// Testing 
//---------
int level_test_makeDecision() {
 int i;
 level *lvl = level_makeNew(4,4,2,NULL);
 for(i=0; i < 4 ;i++) {
  lvl->firstInputs[i] = i*AG_INT_CONVERSION;
 }
 level_makeDecision(lvl); 
 for(i=0; i < 4 ;i++) {
  printf("%f\n",(float)lvl->outputs[i]/(float)AG_INT_CONVERSION);
 }
 level_print(lvl);
 return 1;
}
int level_test() {
 if (level_test_makeDecision() == 0) {
  printf("Failed: Level Decision\n");
  return 0; }
 return 1;
}
#endif
