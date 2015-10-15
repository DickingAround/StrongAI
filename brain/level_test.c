#ifndef level_test_c
#define level_test_c
#include "level.h"
//---------
// Testing 
//---------
int level_test_makeDecision() {
 int i;
 level *lvl = level_makeNew(4,4,2,NULL);
 printf("The decision tests are not complete \n"); 
 for(i=0; i < 4 ;i++) {
  lvl->firstInputs[i] = i*AG_INT_CONVERSION;
 }
 level_makeDecision(lvl); 
 for(i=0; i < 4 ;i++) {
  1 == 1; 
  //printf("%f\n",(float)lvl->outputs[i]/(float)AG_INT_CONVERSION);
 }
 //level_print(lvl);
 return 1;
}
int level_test_learn() {
 int i;
 float ideal[4] = {0.0,0.0,0.0,0.5}; 
 level *lvl = level_makeNew(4,4,2,NULL);
 //First test: does it learn a basic thing
 for(i=0; i < 4 ;i++) {
  lvl->firstInputs[i] = (i+1)*AG_INT_CONVERSION;
  lvl->outputsIdealPostSigmoid[i] = (int)(ideal[i]*AG_INT_CONVERSION);
 }
 lvl->conIn[0] = 0;
 lvl->conOut[0] = 0;
 lvl->conWeight[0] = 1.0;
 lvl->conIn[1] = 3;
 lvl->conOut[1] = 3;
 lvl->conWeight[1] = 0.01;
 for(i=0; i < 1000 ;i++) {
  level_makeDecision(lvl);
  level_learn(lvl,0.1);
 }
 if(lvl->outputs[0]/(float)AG_INT_CONVERSION < -0.01 || 
    lvl->outputs[0]/(float)AG_INT_CONVERSION > 0.01 || 
    lvl->outputs[3]/(float)AG_INT_CONVERSION < 0.4 || 
    lvl->outputs[3]/(float)AG_INT_CONVERSION > 0.6) {
  printf("Failed: Learning test 1\n"); 
  level_print(lvl);
  for(i=0; i < 4 ;i++) {
   printf("%f\n",(float)lvl->outputs[i]/(float)AG_INT_CONVERSION);
  } 
  return 0;
 }
 //Next test
 ideal[0] = 0.1;ideal[1]=0.3;ideal[2]=-1.0;ideal[3]=10.0; 
 srand(0);
 lvl = level_makeNew(4,4,100,NULL);
 //First test: does it learn a basic thing
 for(i=0; i < 4 ;i++) {
  lvl->firstInputs[i] = (i+1)*AG_INT_CONVERSION;
  lvl->outputsIdealPostSigmoid[i] = (int)(ideal[i]*AG_INT_CONVERSION);
 }
 level_print(lvl);
 for(i=0; i < 3 ;i++) {
  level_makeDecision(lvl);
  level_learn(lvl,0.1);
  level_print(lvl); 
  level_printOutputs(lvl);
 }
 //if(lvl->outputs[0]/(float)AG_INT_CONVERSION < -0.01 || 
  //  lvl->outputs[0]/(float)AG_INT_CONVERSION > 0.01 || 
   // lvl->outputs[3]/(float)AG_INT_CONVERSION < 0.4 || 
   // lvl->outputs[3]/(float)AG_INT_CONVERSION > 0.6) {
  //printf("Failed: Learning test 1\n"); 
  //level_print(lvl);
  for(i=0; i < 4 ;i++) {
   printf("%f\n",(float)lvl->outputs[i]/(float)AG_INT_CONVERSION);
  } 
  //return 0;
 return 1;
}
int level_test() {
 if (level_test_makeDecision() == 0) {
  printf("Failed: Level Decision\n");
  return 0; }
 if (level_test_learn() == 0) {
  printf("Failed: Level Learn\n");
  return 0; }
 return 1;
}
#endif
