#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <mqueue.h>
#include <errno.h>
#include <signal.h>
#include <string>

class PosixQueue
{
	public:

	std::string name;
	mqd_t mqdes;
	struct mq_attr attr;

	void create();
	void remove();

	void send(std::string msg);
	std::string receive();
	PosixQueue(std::string namestr);

	void listen();
	void contSend(std::string msg);

};

