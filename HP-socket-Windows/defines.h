/*
 * defines.h
 *
 *  Created on: 2012-9-12
 *      Author: yaowei
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include <assert.h>
//#include <arpa/inet.h>
#include <errno.h>
//#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include "event2/listener.h"
#include "event2/util.h"
#include "event2/event.h"

#include "CLog4cplus.h"
using namespace Log4cplus;


extern CLog4cplus *g_pLogger;
//#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>
//#include <boost/thread/thread.hpp>

//#include <event.h>

//#include <log4cxx/logger.h>
//#include <log4cxx/logstring.h>
//#include <log4cxx/propertyconfigurator.h>
//using namespace log4cxx;
//extern LoggerPtr g_logger;
//
//#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
//            TypeName(const TypeName&); \
//            void operator=(const TypeName&)


#define CRLF "\r\n"

//#define TOKEN_LENGTH 5
//#define TOKEN_STR	 "12345"

#endif /* DEFINES_H_ */
