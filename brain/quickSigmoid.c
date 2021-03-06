#include <math.h>
#include <stdio.h>
int*	quickSigmoid_SigTab;
#define R  32767
#define RR 65556               //65534 + 22

#ifndef GPUEnable
//i:3, d:13
void quickSigmoid_init(void) {
  int i;
  quickSigmoid_SigTab = (int*) malloc(sizeof(int) * 1025);
  for(i = 0; i < 1024; i++)
    quickSigmoid_SigTab[i] = 0x20000 / (1 + exp(-((double)i/(double)0x80))) - 0x10000;
}

int quickSigmoid_Sigmoid(int x) {
  int r,s,j;
  if(x < -0x7FFFF)
    return -0x10000;
  if(x > 0x7FFFF)
    return 0x10000;
  if((s = x) < 0)
    x = -x;
  r = quickSigmoid_SigTab[ (j = x >> 9)]; //16+3-10
  r += ((quickSigmoid_SigTab[ j + 1] - r) * (x&0x1FF)) >> 9;//remaining bitsafter indexing off the fist 10
  if(s < 0)
    return -r;
  else
    return r;
}
int quickSigmoid_inverseSigmoid(int x) {
 double r = (((float)x/(float)0x10000) + 1.0)/2.0;
 return (int)(log(r/(1.0-r))*0x10000); 
}
int quickSigmoid_test() {
 if(quickSigmoid_inverseSigmoid(quickSigmoid_Sigmoid(0x5000)) <= 0x5001 &&
    quickSigmoid_inverseSigmoid(quickSigmoid_Sigmoid(0x5000)) >= 0x4999) {
  return 1;
 }
 printf("%i\n",quickSigmoid_inverseSigmoid(quickSigmoid_Sigmoid(0x5000))); 
 return 0;
}
#endif
