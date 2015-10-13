#ifndef brain_h
#define brain_h
typedef struct brain
{
 //Values
 int *inputs;
 int numberOfLevels;
 level **levels;
} brain; 

void brain_makeNew(brain *newBr, int numberOfLevels);
void brain_makeDecision(brain *br);
void brain_learn(brain *br, int *idealOutput, float speed);
int brain_test();
#endif
