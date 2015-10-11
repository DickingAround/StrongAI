#ifndef level_h
#define level_h
/*  STRUCTURE
lvl 1 : inputs
lvl 2 : mids
lvl 3 : outputs
*/
typedef struct level
{
 //Values
 //int inputs[AG_INPUTS]; //Multiply by AG_INT_CONVERSION to make these, something else should
 int *outputsPreSigmoid; //numberOfOutputs;
 int *outputs;
 int *outputDeltas;
 unsigned int numberOfOutputs;
 unsigned int numberOfInputs;
 //Connections
 unsigned char *conIn; //numberOfConnetions
 unsigned char *conOut;
 float *conWeight;
 unsigned int numberOfConnections;
} level; 

void level_makeNew(level *newLvl);
void level_makeDecision(level *lvl, int *inputs);
void level_learn(level *lvl, int *idealOutputsPreSigmoid);
#endif
