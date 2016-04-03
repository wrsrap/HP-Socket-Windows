/*
 * init_log4cxx.h
 *
 *  Created on: 2012-9-12
 *      Author: yaowei
 */

#ifndef INIT_LOG4CPLUS_H_
#define INIT_LOG4CPLUS_H_

#include "defines.h"

class CInitConfig
{
public:
	CInitConfig();
	virtual ~CInitConfig();

public:

	void InitLog4cplus(std::string log_config_file);

	bool LoadConfiguration();

	void SetConfigFilePath(const std::string& config_file_path)
	{
		config_file_path_ = config_file_path;
	}

private:

	//DISALLOW_COPY_AND_ASSIGN(CInitConfig);
	std::string config_file_path_;
};

#endif /* INIT_LOG4CPP_H_ */
