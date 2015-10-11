#ifndef brain_test_c
#define brain_test_c
#include "brain.h"
//---------
// Testing 
//---------
int brain_test_backprop();
int brain_test() {
 //if (brain_test_saveLoad() == 0)
 // return 0;
 if (brain_test_makeDecision() == 0) {
  printf("Failed: Brain Decision\n");
  return 0; }
 if (brain_test_seeding() == 0) {
  printf("Failed: Seeding\n");
  return 0; }
 if (brain_test_backprop() == 0) {
  return 0; }
 return 1;
}

//int brain_test_saveLoad() {
// return 0;
//}
int brain_test_backprop() {
 /*teachingData = data_loadLabeled("./test_teachingData.csv");
 testData = data_loadUnlabeled("./test_testData.csv");
 brain b;
 brain_makeFromScratch(&b);
 brain_train(&b,teachingData);
 results = brain_run(&b,testData);*/
 return 0; 
}

int brain_test_seeding() {
 //Make a simple brain and show that it can process and return a normal result
 brain b;
 brain_makeFromScratch(&b);
 return brain_test_checkIfNormalish(&b);
}
int brain_test_checkIfNormalish(brain *b) {
 int i;
 float average;
 int inputs[AG_INPUTS];
 for(i = 0; i < AG_INPUTS; i++) {
  inputs[i] = i; 
 }
 brain_makeDecision(b,inputs);
 for(i = 0; i < AG_OUTPUTS_DECISIONS; i++) {
  //printf("Brain: Output found was %i\t%f\n",i,b->outputs[i]/(float)AG_INT_CONVERSION);
  average += b->outputs[i]/(float)AG_INT_CONVERSION;
 }
 if(average /(float)AG_OUTPUTS_DECISIONS > 0.5 || average /(float)AG_OUTPUTS_DECISIONS < -0.5) {
  printf("Brain: Make from scratch failed average check with value of sum %f average %f\n",average,average/(float)AG_OUTPUTS_DECISIONS);
  return 0; //It should be around zeroish
 }
 return 1;
}

int brain_test_makeDecision()
{
 float o;
 int inputs[4];
 brain br;
 inputs[0] = 1.0*AG_INT_CONVERSION;
 //Inputs over the limit are no longer possible, the mult will be below a number and the input will be below a number
 inputs[1] = 0;//(0x7FFF+2)*AG_INT_CONVERSION;//This should be rtight over the limit
 inputs[2] = -1.0*AG_INT_CONVERSION;
 inputs[3] = 0;//(0x7FFF)*AG_INT_CONVERSION;//This should be at the limit, but will be multiplied
 //normal con
 br.inL1[0] = 0;
 br.outL1[0] = 2;
 br.multL1[0] = 1; 
 //normal con2
 br.inL1[1] = 2;
 br.outL1[1] = 2;
 br.multL1[1] = -1;
 //limit con
 br.inL1[2] = 1;
 br.outL1[2] = 0;
 br.multL1[2] = 1;
 //limit multiplier con
 br.inL1[3] = 3;
 br.outL1[3] = 1;
 br.multL1[3] = 2;
 br.inL1[4] = AG_CONN_END;
 //normal con
 br.inL2[0] = 2;
 br.outL2[0] = 1;
 br.multL2[0] = 1.0;
 //limit con
 br.inL2[1] = 0;
 br.outL2[1] = 0;
 br.multL2[1] = 1.0;
 //limit mult con
 br.inL2[2] = 1;
 br.outL2[2] = 2;
 br.multL2[2] = 1.0;
 br.inL2[3] = AG_CONN_END;
 brain_makeDecision(&br,inputs);
 //printf("input over limit %f\n",br.outputs[0]/(float)AG_INT_CONVERSION);
 //printf("mult over limit %f\n",br.outputs[2]/(float)AG_INT_CONVERSION);
 o = br.outputs[1]/(float)AG_INT_CONVERSION; 
 //if(o > 0.7615 && o < 0.7616)
 if(o > 0.3633 && o < 0.363379)
   return 1;
 //printf("%f\n",o);
 return 0;
}
#endif
