#pragma once
#include "miTaskBase.h"
namespace mitasks
{
	class miTaskManager
	{
	private:
		std::list<mitasks::miTaskBase*> _TaskList;
	public:
		miTaskManager()
		{

		}
		void AddTask(mitasks::miTaskBase* task);
		void Start();
		void Stop();
	};
}

