#include "posix.h"

int main(void){

	PosixQueue p("/test_queue");

	p.create();
	p.send("hello");

	return 0;
}

