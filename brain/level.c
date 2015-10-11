#ifndef level_c
#define level_c
#include "level.h"
//Returns the newLvl
//Inputs are not within the class
void level_makeNew(level *newLvl, int inputs, int outputs, int connections) {
 int i;
 newLvl = (level *)malloc(sizeof(level));
 newLvl->numberOfInputs = inputs;
 newLvl->numberOfOutputs = outputs; 
 newLvl->numberOfConnections = connections;
 newLvl->conIn = (unsigned char *)malloc(sizeof(unsigned char)*connections);
 newLvl->conOut = (unsigned char *)malloc(sizeof(unsigned char)*connections);
 newLvl->conWeight = (float *)malloc(sizeof(float)*connections);
 newLvl->outputsPreSigmoid = (int *)malloc(sizeof(int)*outputs);
 newLvl->outputs = (int *)malloc(sizeof(int)*outputs);
 newLvl->outputsDeltas = (int *)malloc(sizeof(int)*outputs);
 for(i=0; i < connections ;i++) {
  newLvl->conIn[i] = rand() / (float)RAND_MAX * inputs;
  newLvl->conOut[i] = rand() / (float)RAND_MAX * outputs;
  newLvl->conWeight[i] = (rand() / (float)RAND_MAX - 0.5) * AG_MULT_INIT_RANGE;
 } 
}

void level_makeDecision(level *lvl, int *inputs) {
 int i;
 int outputs, outputsPreSigmoid; 
 unsigned char *conIn, *conOut;
 float *conWeight;
 unsigned int numberOfInputs, numberOfOutputs;
 outputs = lvl->outputs;
 outputsPreSigmoid = lvl->outputsPreSigmoid;
 conIn = lvl->conIn;
 conOut = lvl->conOut;
 conWeight = lvl->conWeight;
 numberOfInputs = lvl->numberOfInputs;
 numberOfOutputs = lvl->numberOfOutputs;
 for(i = 0; i < numberOfInputs; i++) {
  outputs[i] = 0;
 } 
 for(i = 0; i < numberOfConnections; i++) {
  outputsPreSigmoid[conOut[i]] += inputs[conIn[i]] * conWeight[i];
 }
 for(i = 0; i < numberOfOutputs; i++ ) {
  outputs[i] = quickSigmoid_Sigmoid(outputsPreSigmoid[i]);
 }
}
//Inputs can be NULL, and should be when this is level 1
void level_learn(level *lvl, int *idealOutputsPreSigmoid, int *inputs, float speed) {
 int i;
 unsigned int numberOfOutputs, numberOfConnections, 
 int *outputDeltas, *outputsPreSigmoid, *outputs;
 float *conWeight; 
 for(i=0; i < numberOfOutputs ;i++) {
  outputDeltas[i] = idealOutputsPreSigmoid[i] - outputsPreSigmoid[i];
 }
 for(i=0; i < numberOfConnections ;i++) {
  conWeight[i] += outputDeltas[i]/inputs[i] * speed; 
 } 
 if( inputs == NULL) {
  for(i=0; i < numberOfInputs ;i++) {
   inputs[i] += outputDeltas[i]/conWeight[i] * speed;
  }
 } 
}
#endif
