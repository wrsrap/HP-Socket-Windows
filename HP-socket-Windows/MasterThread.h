#ifndef MASTER_THREAD_H__
#define MASTER_THREAD_H__

#include "defines.h"

class CWorkerThread;

class CMasterThread
{
public:
	CMasterThread();
	virtual ~CMasterThread();

public:

	bool InitMasterThread();

	void Run();

private:

	bool CheckLibeventVersion();

	bool InitRemoteListenSocket(event_base *main_base);

	static void AccepCb(struct evconnlistener *listener, evutil_socket_t fd,
						struct sockaddr *sa, int socklen, void *user_data);

private:

	struct event_base 	*main_base_;
	evutil_socket_t 	remote_listen_socket_;
	struct evconnlistener		*listen_event_;

	CWorkerThread		*worker_thread_ptr_;
};

#endif