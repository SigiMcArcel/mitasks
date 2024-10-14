#include "miTaskManager.h"
void mitasks::miTaskManager::AddTask(mitasks::miTaskBase* task)
{
	_TaskList.push_back(task);
}

void mitasks::miTaskManager::Start()
{
	for (auto task : _TaskList)
	{
		//init and open all drivers
		task->init();
		task->start();
	}
}

void mitasks::miTaskManager::Stop()
{
	for (auto task : _TaskList)
	{
		//deinit and stop all drivers
		task->stop();
		task->deinit();
	}
}