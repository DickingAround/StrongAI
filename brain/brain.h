#ifndef brain_h
#define brain_h
typedef struct brain
{
 //Values
 int *inputs;
 int numberOflevels;
 level *levels;
} brain; 

void brain_makeNew(brain *newBr);
void brain_makeDecision(brain *br);
void brain_learn(brain *br, int *idealOutput);
#endif
