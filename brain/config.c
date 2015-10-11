//We have a range of initalization that's different from the max in an effort to collect the values
#define AG_INPUTS_INIT 100 //Don't need to do signals or memory
#define AG_MIDS_INIT 100 //Don't  need to use most middle connections
#define AG_MID_NODES 100
#define AG_OUTPUTS_INIT 2 //Don't need to use memory or signal
#define AG_CONNS_INIT 50
#define AG_CONNS_L1 500
#define AG_CONNS_L2 500
#define AG_CONN_END 255 //AG_CONN_END must be larger than the number of inputs or outputs, maxes at 255 for u-char

#define AG_MUTATION_RATE 0.10

//Simulation settings
#define NUMBER_OF_THREADS 4
#define LESS_METRICS //Define this to remove most per-agent metrics and accelerate the simulation
#define LESS_TIMERS //Define this to remove most timers 

//Outputs from the brain
#define AG_OUTPUTS 2
#define AG_OUTPUTS_DECISIONS 2
#define AG_MEM_OUT 0
#define AG_MEM_NUMB 0
//Remmber, total options is 0-based

#define AG_INPUTS 100
#define AG_IN_MEM 1000

#define AG_INPUT_MAX 0xFF
//#define AG_INPUT_MIN -- No inputs are possible to be lower numbers
#define AG_MULT_MAX 0x7F
#define AG_MULT_MIN -0x7F
#define AG_MULT_INIT_RANGE 0x2F

//Values for making decisions
#define AG_INT_CONVERSION 0xFFFF
//Fast rand settings

// Note that fast rand array length is 100 longer because we're allowing space for multi-threading issues we've intentionally allowed for the sake of speed.
#define FAST_RAND_LEN 1000000
#define FAST_RAND_ARRAY_LEN 1000100

