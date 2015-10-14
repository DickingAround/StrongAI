#ifndef level_h
#define level_h
/*  STRUCTURE
lvl 1 : inputs
lvl 2 : mids
lvl 3 : outputs
*/
typedef struct level level;

struct level
{
 //Values
 //int inputs[AG_INPUTS]; //Multiply by AG_INT_CONVERSION to make these, something else should
 int *outputsPreSigmoid; //Summed weight before sigmoid is used
 int *outputs; //Final output after sigmoid
 int *outputsIdealsPostSigmoid; //The ideals post sigmoid
 int *outputsDeltas; //The delta between
 unsigned int numberOfOutputs;
 level *previousLevel;
 unsigned int numberOfFirstInputs; //NULL unless this is the very first level, in which case previous level is null
 int *firstInputs;
 //Connections
 unsigned char *conIn; //numberOfConnetions
 unsigned char *conOut;
 float *conWeight;
 unsigned int numberOfConnections;
}; 

level *level_makeNew(int inputs, int outputs, int connections, level* previousLevel);
void level_makeDecision(level *lvl, int *inputs);
void level_learn(level *lvl, float speed);
#endif
