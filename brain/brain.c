#ifndef brain_c
#define brain_c
#include "brain.h"
void brain_makeNew(brain *newBr, int numberOfLevels) {
 int i;
 newBr = (brain*) malloc(sizeof(brain));
 newBr->numberOfLevels = numberOfLevels;
 newBr->levels = (level**) malloc(sizeof(level *));
 for(i=0; i < newBr->numberOfLevels ;i++) {
  newBr->levels[i] = (level*) malloc(sizeof(level));
 }
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
 //Run the inverse learning
 level_learn(br->levels[br->numberOfLevels-1],idealOutput,speed);
 for(i = br->numberOfLevels - 2; i > 0; i++) {
  level_learn(br->levels[i],br->levels[i-1]->outputs,speed);
 }
 level_learn(br->levels[0],NULL,speed);
}

#endif
