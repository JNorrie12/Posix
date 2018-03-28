#include "posix.h"
#include <cstring>

PosixQueue::PosixQueue(std::string namestr){

	name = namestr;

	attr.mq_msgsize = 1024;
	attr.mq_maxmsg = 100;
	attr.mq_flags = 0;
	attr.mq_curmsgs = 0;

};

void PosixQueue::create(){

	mqdes = mq_open( name.c_str() , O_CREAT|O_RDWR, 0664, &attr);

};

void PosixQueue::send(std::string msg){

	int i;
	unsigned int prio = 0;

	if (mq_send(mqdes, msg.c_str(), 1024, 0) == -1){
		std::cout << std::strerror(errno) << std::endl ;
		};
};

std::string PosixQueue::receive(){

	int j;
	char buf[1024];

	if(mq_receive(mqdes, &buf[0], 1024, 0) ==-1){
		std::cout << std::strerror(errno) << std::endl;
		return "error";
		};
	return std::string(buf);
};

void PosixQueue::remove(){
	mq_close(mqdes);
	mq_unlink(name.c_str());
};

void PosixQueue::listen(){
	while(1){
		std::cout << this->receive() << std::endl;
	}
};

void PosixQueue::contSend(std::string msg){
	while(1){
		this->send(msg);
		sleep(1);

	}
};



