#ifndef brain_h
#define brain_h
typedef struct brain
{
 //Values
 int *inputs;
 int numberOfLevels;
 level **levels;
} brain; 

brain *brain_makeNew(int intputs, int outputs, int levels, int midNodes, int connections);
void brain_makeDecision(brain *br, float *inputs);
void brain_learn(brain *br, int *idealOutput, float speed);
int brain_test();
#endif
