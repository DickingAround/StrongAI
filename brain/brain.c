#ifndef brain_c
#define brain_c
#include "brain.h"
#include "brain_saveLoad.c"
#include "brain_test.c"
#include <limits.h>
extern fastRand fr;
void brain_makeDecision(brain *br, int *data)
{
 int i,max;
 int *ins, *outs, *mids;
 float *multL1, *multL2;
 unsigned char *inL1, *outL1, *inL2, *outL2;
 //ins = br->inputs; 
 ins = data;
 mids = br->mids;
 outs = br->outputs;
 inL1 = br->inL1;
 outL1 = br->outL1;
 inL2 = br->inL2;
 outL2 = br->outL2;
 multL1 = br->multL1;
 multL2 = br->multL2;
 for(i = 0; i < AG_MID_NODES; i++) { //Reset the middle nodes to zero
  mids[i] = 0;
 } 
 i = 0;
 while(inL1[i] != AG_CONN_END) {
  mids[outL1[i]] += ins[inL1[i]] * multL1[i];
  i++;
 } //NOTE: The mutation script is expected to assure we don't have backward connections (mid to in, for exmaple)
 for(i = 0; i < AG_MID_NODES; i++) {
  mids[i] = quickSigmoid_Sigmoid(mids[i]); //NOTE: The mutation script needs to also assure the value doesn't exceed the maxes that the simoid function can handle
 }
 for(i = 0; i < AG_OUTPUTS; i++) {
  outs[i] = 0;
 } 
 i = 0;
 while(inL2[i] != AG_CONN_END) {
  outs[outL2[i]] += mids[inL2[i]] * multL2[i]; 
  outs[i] = quickSigmoid_Sigmoid(outs[i]);// Conversion must be done outsidethe brain, since this is an int/(float)AG_INT_CONVERSION;
  i++;
 }
  //if((float)outs[i]/(float)AG_INT_CONVERSION > 0.001 || (float)outs[i]/(float)AG_INT_CONVERSION < -0.001)
  //printf("Finally found a brain outputting %i, %i\n",i,outs[i]);
 //}
 //-------- Memory ------
 for(i = 0; i < AG_MEM_NUMB; i++) {
  br->mem[i] = outs[AG_MEM_OUT + i]; //Saved in their raw form because they're consumed in the raw formed
 }
 //-------- Decision ----
 max = INT_MIN;
 for(i = 0; i < AG_OUTPUTS_DECISIONS; i++) {
  if(outs[i] > max) {
   max = outs[i];
   br->latestDecision = i; 
  } 
 }
}

int brain_learnDecision(brain *br, int decision, float speed) {
  
}

int brain_computeBrainSize(brain *b) {
 int i = 0;
 while(b->inL1[i] != AG_CONN_END) {
  i++;
 }
 while(b->inL2[i] != AG_CONN_END) {
  i++;
 } 
 b->brainSize = i;
}

//----------------------
// Replication: Seeding 
//----------------------
void brain_fillRestWithNoOps(unsigned char *in, unsigned char *out, int connMax, int i) {
 for( ; i < connMax && in[i] != AG_CONN_END; i++) {
  in[i] = AG_CONN_END;
 }
}
void brain_makeFromScratch(brain *newB) {
 newB->mutationRate = AG_MUTATION_RATE;
 brain_makeConnLvlFromScratch(newB->inL1,AG_INPUTS_INIT,newB->outL1,AG_MIDS_INIT,newB->multL1,newB->mutationRate,AG_CONNS_L1);  
 brain_makeConnLvlFromScratch(newB->inL2,AG_MIDS_INIT,newB->outL2,AG_OUTPUTS_INIT,newB->multL2,newB->mutationRate,AG_CONNS_L2);  
 brain_computeBrainSize(newB);
}
void brain_makeConnLvlFromScratch(unsigned char *in, unsigned char inMax, unsigned char *out, unsigned char outMax, float *mult, float mutationRate, int connMax) {
 int i;
 for(i = 0; i < AG_CONNS_INIT; i++) {
  out[i] = rand() / (float)RAND_MAX * outMax;
  in[i] = rand() / (float)RAND_MAX * inMax;
  mult[i] = ((rand() / (float)RAND_MAX) -0.5) * AG_MULT_INIT_RANGE; 
 }
 brain_fillRestWithNoOps(in,out,connMax,i);
}

#endif
