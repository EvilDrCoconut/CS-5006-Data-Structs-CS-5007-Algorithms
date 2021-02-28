#include <stdio.h>
#include <time.h>
#include <stddef.h>

static time_t start;
static time_t end;
int counter = 0;
void __attribute__((destructor)) EndOfProgram();

__attribute__((constructor))
void time_start(){
	start = time(NULL);
}


__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){
	printf("Function entered %p from %p time: %lu\n", this_fn, call_site, time(NULL));

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){

	printf("Function exited %p from %p time: %lu\n", this_fn, call_site, time(NULL));
	counter ++;
}


void EndOfProgram(){
	end = time(NULL);
	printf("Total number of function calls: %d \n", counter);
	printf("Total program time elapsed: %lu \n", (time(NULL) - start));
}

