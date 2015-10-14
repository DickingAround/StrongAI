#ifndef brain_c
#define brain_c
#include "brain.h"
void brain_makeNew(brain *newBr, int inputs, int outputs, int levels, int midNodes, int connections) {
 int i;
 newBr = (brain*) malloc(sizeof(brain));
 newBr->numberOfLevels = numberOfLevels;
 newBr->levels = (level**) malloc(sizeof(level *));
 newBr->levels[0] = level_makeNew(inputs,midNodes,connections,NULL);
 for(i=1; i < newBr->numberOfLevels-1 ;i++) {
  newBr->levels[i] = level_makeNew(midNodes,midNodes,connections,newBr->levels[i-1]);
 }
 newBr->levels[newBr->numberOfLevels-1] = level_makeNew(midNodes,outputs,connections,newBr->levels[newBr->numberOfLevels-2]);
}
void brain_makeDecision(brain *br) {
 int i;
 level_makeDecision(br->levels[0],br->inputs);
 for(i=1; i < br->numberOfLevels ;i++) {
  level_makeDecision(br->levels[i],br->levels[i-1]->outputs);
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
