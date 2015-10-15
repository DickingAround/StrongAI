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
 int *outputsIdealPostSigmoid; //The ideals post sigmoid
 int *outputsDeltas; //The delta between
 unsigned int numberOfOutputs;
 level *previousLevel;
 unsigned int numberOfFirstInputs; //NULL and 0 unless this is the very first level, in which case previous level is null
 int *firstInputs;
 //Connections
 unsigned char *conIn; //numberOfConnetions
 unsigned char *conOut;
 float *conWeight;
 unsigned int numberOfConnections;
}; 

level *level_makeNew(int firstInputs, int outputs, int connections, level* previousLevel);
void level_makeDecision(level *lvl);
void level_learn(level *lvl, float speed);
void level_print(level *lvl);
void level_printOutputs(level *lvl);
#endif
