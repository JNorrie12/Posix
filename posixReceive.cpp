#include "posix.h"

int main(void){

	PosixQueue p("/test_queue");

	p.create();
	p.listen();

	return 0;
}

