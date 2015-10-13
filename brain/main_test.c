// includes, system
#include "config.c"
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "level.h"
#include "brain.h"
#include "fastRand.h"
fastRand fr;
void error_handler(int sig); 
#include "quickSigmoid.c"
#include "fastRand.c"
#include "level.c"
#include "brain.c"
#include "brain_test.c"
void runTests();
void run();
int main(int argc, char** argv)
{
 srand(138159158); //9);
 srand(time(NULL));
 quickSigmoid_init();
 fastRand_init(&fr);
 signal(SIGSEGV,error_handler);
 if(argc != 2) //Assume we're running tests now
  runTests();
 else
  switch (argv[1][1])
  {
   case 't': //Run tests
    runTests();
    break;
   case 'r': //Run
    printf("Nothing to run\n");
    break;
  }
}
void runTests()
{
 if(brain_test() == 1)
   printf("Passed: Brain tests\n");
 else
   printf("Failed: Brain tests\n");
 if(quickSigmoid_test() == 1)
   printf("Passed: QuickSigmoid tests\n");
 else
   printf("Failed: QuickSigmoid tests\n");
}
void error_handler(int sig) {
  void *array[40];
  size_t size;
  // get void*'s for all entries on the stack
  size = backtrace(array, 40);
  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, 1);
  exit(1); //-- Keep going if possible
}
