#ifndef brain_c
#define brain_c
#include "brain.h"
void brain_makeNew(brain *newBr, int inputs, int outputs, int levels, int midNodes, int connections) {
 int i;
 newBr = (brain*) malloc(sizeof(brain));
 newBr->numberOfLevels = numberOfLevels;
 newBr->levels = (level**) malloc(sizeof(level *));
 //The first node is different; no pointer to the previous and needs special inputs
 newBr->levels[0] = level_makeNew(inputs,midNodes,connections,NULL);
 newBr->levels[0]->numberOfFirstInputs = inputs;
 newBr->levels[0]->firstInputs = (int*) malloc(sizeof(int)*inputs);
 //Fill in the rest of the nodes
 for(i=1; i < newBr->numberOfLevels-1 ;i++) {
  newBr->levels[i] = level_makeNew(midNodes,midNodes,connections,newBr->levels[i-1]);
 }
 newBr->levels[newBr->numberOfLevels-1] = level_makeNew(midNodes,outputs,connections,newBr->levels[newBr->numberOfLevels-2]);
}
void brain_makeDecision(brain *br, float *inputs) {
 int i;
 //Translate the new inputs
 for(i=0; i < br->levels[0]->numberOfFirstInputs ;i++) {
  br->levels[0]->firstInputs = (int)inputs[i]*AG_INT_CONVERSION;
 }
 //Run the system
 for(i=0; i < br->numberOfLevels ;i++) {
  level_makeDecision(br->levels[i]);
 }
}
void brain_learn(brain *br, int *idealOutput, float speed) {
 int i;
 //Copy the ideal output into the last level
 for(i=0; i < br->levels[br->numberOfLevels-1]->numberOfOutputs ;i++) {
  br->levels[br->numberOfLevels-1]->outputsIdealsPostSigmoid[i] = idealOutput[i];
 } 
 //Run each level starting with the last
 for(i = br->numberOfLevels-1 ; i >= 0; i--) {
  level_learn(br->levels[i],speed); 
 }
}

#endif
