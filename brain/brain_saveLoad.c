#ifndef brain_saveload_c
#define brain_saveload_c
#include "brain.h"
//---------------------
// Saving and loading
//---------------------
void brain_print(brain *b) {
int i = 0;
 printf("L1");
 while(b->inL1[i] != AG_CONN_END) {
  printf(",%i:%f:%i",b->inL1[i],b->multL1[i],b->outL1[i]); 
  i++;
 }
 printf(" L1 had %i connections",i);
 printf(";L2");
 i = 0; 
 while(b->inL2[i] != AG_CONN_END) {
  printf(",%i:%f:%i",b->inL2[i],b->multL2[i],b->outL2[i]); 
  i++;
 }
 printf(" L2 had %i connections\n",i);
}
void brain_save(brain *b, FILE *file) {
 int i = 0;
 fprintf(file,"M%f;H%lu",b->mutationRate,b->speciesHash); 
 fprintf(file,";L1");
 while(b->inL1[i] != AG_CONN_END) {
  fprintf(file,";%i:%f:%i",b->inL1[i],b->multL1[i],b->outL1[i]); 
  i++;
  if(i >= AG_CONNS_L1) {
   printf("Saving: Too many conns in this agent in L1 %i\n",i);
   getchar();
  }
 }
 fprintf(file,";L2");
 i = 0; 
 while(b->inL2[i] != AG_CONN_END) {
  fprintf(file,";%i:%f:%i",b->inL2[i],b->multL2[i],b->outL2[i]); 
  i++;
  if(i >= AG_CONNS_L2) {
   printf("Saving: Too many conns in this agent in L2 %i\n",i);
   getchar();
  }
 }
 fprintf(file,";ME");
 for( i = 0; i < AG_MEM_NUMB; i++) {
  fprintf(file,";%i",b->mem[i]); 
 }
}
void brain_load(brain *b, char *str, int strLength) {
 int ptr, lvl, in, out, brainPtr;
 float mult;
 brain_fillRestWithNoOps(b->inL1,b->outL1,AG_CONNS_L1,0);
 brain_fillRestWithNoOps(b->inL2,b->outL2,AG_CONNS_L2,0);
 b->mutationRate = AG_MUTATION_RATE;
 ptr = 0;
 while(str[ptr] != '\n' && ptr < strLength) { //This is clearly the beginning of a designator
  if(str[ptr] == 'M') {
   ptr += 1;
   b->mutationRate = atof(str+ptr);
   while(str[ptr] != ';')
    ptr++;
  }
  else if(str[ptr] == ';' && str[ptr+1] == 'H') {
   ptr += 2;
   b->speciesHash = atoi(str+ptr); 
   while(str[ptr] != ';')
    ptr++;
  }
  else if(str[ptr] == ';' && str[ptr+1] == 'L' && str[ptr+2] == '1' ) { 
   lvl = 1;
   ptr += 3; //Advance the pointer to the ';' character
   brainPtr = 0;
  }
  else if(str[ptr] == ';' && str[ptr+1] == 'L' && str[ptr+2] == '2') {
   lvl = 2;
   brain_fillRestWithNoOps(b->inL1,b->outL1,AG_CONNS_L1,brainPtr);
   ptr += 3;
   brainPtr = 0;
   //printf("Starting L2");
  }
  else if(str[ptr] == ';' && str[ptr+1] == 'M' && str[ptr+2] == 'E') {
   lvl = 3; //This is all memory, not actuall a new level
   brain_fillRestWithNoOps(b->inL2,b->outL2,AG_CONNS_L2,brainPtr);
   ptr += 3;
   brainPtr = 0;
   //printf("The memory seciton is '%s'",str+ptr);
  }
  else if(str[ptr] == ';' && lvl == 3) { //Memory 
   ptr++;
   b->mem[brainPtr] = atoi(str+ptr);
   //printf("Loaded Mem con %i, %i from pt %i\n",brainPtr,b->mem[brainPtr],ptr);
   while(str[ptr] != ';' && str[ptr] != '\n')
    ptr++;
   brainPtr++;
   if(brainPtr > AG_MEM_NUMB) {
    printf("The brain you loaded had too much memory, it is being compacted foolishly\n");
   }
  }
  else if(str[ptr] == ';' && (lvl == 1 || lvl == 2)) { //This is clearly the beginning of a connection
   ptr++;
   in = atoi(str+ptr);
   while(str[ptr] != ':')
    ptr++;
   ptr++;
   mult = atof(str+ptr);
   while(str[ptr] != ':')
    ptr++;
   ptr++;
   out = atoi(str+ptr);
   while(str[ptr] != ';')
    ptr++; 
   if(lvl == 1) {
    b->inL1[brainPtr] = in;
    b->multL1[brainPtr] = mult;
    b->outL1[brainPtr] = out; 
   }
   else { 
    b->inL2[brainPtr] = in;
    b->multL2[brainPtr] = mult;
    b->outL2[brainPtr] = out; 
    //printf("The brain has conn %i,%f,%i\n",in,mult,out);
   }
   brainPtr++;
   if(lvl == 1 && brainPtr >= AG_CONNS_L1 - 1) {
    printf("The brain you loaded was too big in L1, it is being compacted foolishly\n");
    printf(str);
    getchar();
    brainPtr = AG_CONNS_L1;
   } 
   if(lvl == 2 && brainPtr >= AG_CONNS_L2 - 1) {
    printf("The brain you loaded was too big in L2, it is being compacted foolishly\n");
    printf(str);
    getchar();
    brainPtr = AG_CONNS_L2;
   }
  }
  else {//Not sure why we're getting these characters...
   printf("Brain loading: Not sure why I got this random char: %c\n",str[ptr]);  
   ptr++;
  }
 } 
 //printf("LMemSize:%i\n",brainPtr);
 //brain_fillRestWithNoOps(b->inL2,b->outL2,AG_CONNS_L2,brainPtr);
 //brain_computeHash(b); We no longer compute the function, since it's a variable not basedo n the brain but based on geneology
}
#endif
