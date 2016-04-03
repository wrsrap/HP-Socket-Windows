#include "defines.h"
#include "config_file.h"
#include "init_configure.h"
#include "utils.h"
#include "global_settings.h"
#include "MasterThread.h"

void InitConfigure();
void SettingsAndPrint();
void Run();

int main()
{
	string path;
	utils::GetCurrentPath(path);
	std::cout << path << endl;
	InitConfigure();
	SettingsAndPrint();
	//while (1)
	//{
	//};

	Run();
	return 0;
}

void InitConfigure()
{
	CInitConfig initConfObj;
	std::string current_path;
	if (!utils::GetCurrentPath(current_path))
	{
		cout << "GetCurrentPath failed." << endl;
		//LOG4CXX_FATAL(g_logger, "GetCurrentPath failed.");
		exit(EXIT_FAILURE);
	}
	initConfObj.SetConfigFilePath(current_path);
	initConfObj.InitLog4cplus("config.ini");
	if (!initConfObj.LoadConfiguration())
	{
		//LOG4CXX_FATAL(g_logger, "LoadConfiguration failed.");
		exit(EXIT_FAILURE);
	}
}

void SettingsAndPrint()
{
	utils::G<CGlobalSettings>().remote_listen_port_ = utils::G<ConfigFile>().read<int>("remote.listen.port", 12006);
	cout << "******remote.listen.port=" << utils::G<CGlobalSettings>().remote_listen_port_ << endl;

	utils::G<CGlobalSettings>().thread_num_ = utils::G<ConfigFile>().read<int>("worker.thread.num", 4);
	cout << "******remote.listen.port=" << utils::G<CGlobalSettings>().thread_num_ << "******" << endl;

	utils::G<CGlobalSettings>().client_heartbeat_timeout_ = utils::G<ConfigFile>().read<int>("client.heartbeat.timeout.s", 70);
	cout << "******remote.listen.port=" << utils::G<CGlobalSettings>().client_heartbeat_timeout_ << "******" << endl;

	/*LOG4CXX_INFO(g_logger, "******remote.listen.port=" << utils::G<CGlobalSettings>().remote_listen_port_ << "******");
	LOG4CXX_INFO(g_logger, "******worker.thread.num =" << utils::G<CGlobalSettings>().thread_num_ << "******");
	LOG4CXX_INFO(g_logger, "******client.heartbeat.timeout.s =" << utils::G<CGlobalSettings>().client_heartbeat_timeout_ << "******");*/
}

void Run()
{
	CMasterThread masterThread;
	if (!masterThread.InitMasterThread())
	{
		//LOG4CXX_FATAL(g_logger, "InitNetCore failed.");
		exit(EXIT_FAILURE);
	}

	masterThread.Run();
}