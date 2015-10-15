#ifndef level_c
#define level_c
#include "level.h"
//Returns the newLvl
//Inputs are not within the class
level *level_makeNew(int firstInputs, int outputs, int connections, level *previousLevel) {
 int i,inputs;
 level *newLvl;
 newLvl = (level *)malloc(sizeof(level));
 if(previousLevel == NULL) { //Is this the first level or not?
  newLvl->numberOfFirstInputs = firstInputs;
  inputs = firstInputs; //Used only in this function to fill out connections
  newLvl->firstInputs = (int *)malloc(sizeof(int)*firstInputs);
  newLvl->previousLevel = NULL;
 } else {
  newLvl->numberOfFirstInputs = 0;
  newLvl->firstInputs = NULL;
  inputs = previousLevel->numberOfOutputs;
  newLvl->previousLevel = previousLevel;
 } 
 newLvl->numberOfOutputs = outputs; 
 newLvl->numberOfConnections = connections;
 newLvl->conIn = (unsigned char *)malloc(sizeof(unsigned char)*connections);
 newLvl->conOut = (unsigned char *)malloc(sizeof(unsigned char)*connections);
 newLvl->conWeight = (float *)malloc(sizeof(float)*connections);
 newLvl->outputsPreSigmoid = (int *)malloc(sizeof(int)*outputs);
 newLvl->outputs = (int *)malloc(sizeof(int)*outputs);
 newLvl->outputsDeltas = (int *)malloc(sizeof(int)*outputs);
 newLvl->previousLevel = previousLevel; 
 for(i=0; i < connections ;i++) {
  newLvl->conIn[i] = rand() / (float)RAND_MAX * inputs;
  newLvl->conOut[i] = rand() / (float)RAND_MAX * outputs;
  newLvl->conWeight[i] = (rand() / (float)RAND_MAX - 0.5) * AG_MULT_INIT_RANGE;
 } 
 return newLvl;
}
void level_makeDecision(level *lvl) {
 int i;
 int *outputs, *outputsPreSigmoid, *inputs; 
 unsigned char *conIn, *conOut;
 float *conWeight;
 unsigned int numberOfInputs, numberOfOutputs, numberOfConnections;
 outputs = lvl->outputs;
 outputsPreSigmoid = lvl->outputsPreSigmoid;
 conIn = lvl->conIn;
 conOut = lvl->conOut;
 conWeight = lvl->conWeight;
 numberOfOutputs = lvl->numberOfOutputs;
 numberOfConnections = lvl->numberOfConnections;
 //Check the input source
 if(lvl->previousLevel == NULL) {
  inputs = lvl->firstInputs;
  numberOfInputs = lvl->numberOfFirstInputs;
 } else {
  inputs = lvl->previousLevel->outputs;
  numberOfInputs = lvl->previousLevel->numberOfOutputs;
 } 
 //Clear all current output data
 for(i = 0; i < numberOfOutputs; i++) {
  outputs[i] = 0;
 }
 //Run each connection
 for(i = 0; i < numberOfConnections; i++) {
  outputsPreSigmoid[conOut[i]] += inputs[conIn[i]] * conWeight[i];
 }
 //Apply sigmoids
 for(i = 0; i < numberOfOutputs; i++ ) {
  outputs[i] = quickSigmoid_Sigmoid(outputsPreSigmoid[i]);
 }
}
void level_learn(level *lvl, float speed) {
 int i;
 unsigned int numberOfOutputs, numberOfInputs, numberOfConnections;
 int *outputsDeltas, *outputsPreSigmoid, *outputs, *inputs, *outputsIdealPostSigmoid;
 float *conWeight; 
 outputsPreSigmoid = lvl->outputsPreSigmoid;
 outputsDeltas = lvl->outputsDeltas;
 conWeight = lvl->conWeight;
 numberOfConnections = lvl->numberOfConnections;
 numberOfOutputs = lvl->numberOfOutputs;
 outputsIdealPostSigmoid = lvl->outputsIdealPostSigmoid;
 //Figure out which inputs to use? (the very first, or from the previous level?)
 if(lvl->previousLevel == NULL) {
  inputs = lvl->firstInputs;
  numberOfInputs = lvl->numberOfFirstInputs;
 } else {
  inputs = lvl->previousLevel->outputs;
  numberOfInputs = lvl->previousLevel->numberOfOutputs;
 }
 //Compute the delta from the ideals we've been given
 for(i=0; i < numberOfOutputs ;i++) {
  outputsDeltas[i] = quickSigmoid_inverseSigmoid(outputsIdealPostSigmoid[i]) - outputsPreSigmoid[i];
 }
 //Train the weights
 for(i=0; i < numberOfConnections ;i++) {
  conWeight[i] += outputsDeltas[i]/inputs[i] * speed; 
 } 
 //Produce the next down set of ideal outputs
 if(lvl->previousLevel != NULL) { 
  outputsIdealPostSigmoid = lvl->previousLevel->outputsIdealPostSigmoid;
  for(i=0; i < numberOfInputs ;i++) { 
    outputsIdealPostSigmoid[i] += inputs[i] + outputsDeltas[i]/conWeight[i] * speed;
  }
 } 
}

#endif
