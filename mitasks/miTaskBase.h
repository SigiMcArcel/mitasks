#pragma once
#include <memory>
#include <list>
#include <mi/miutils/Time.h>
#include <mi/miutils/Timer.h>
#include <mi/mimodules/ModuleInterface.h>
#include <mi/micomponents/miComponentBase.h>
#include "miTaskSync.h"

namespace mitasks
{
	typedef enum class  TaskType_e
	{
		IO,
		PRG,
		None
	}TaskType;

	class miTaskBase
		: public miutils::TimerEventListener
		, public mitasks::miTaskSync
	{
	private:
		std::list< micomponents::miComponentBase*> _ComponentList;
		std::list<mimodule::ModuleInterface*> _ModuleList;
		miutils::Timer _Timer;
		miutils::Time _Time;
		int _TaskIntervall;

	public:
		miTaskBase(const std::string& name)
			:_Timer(name, this)
			, _Time()
		{

		}

		miTaskBase(const std::string& name, int intervall)
			:_Timer(name, this, intervall)
			, _Time()
			, _TaskIntervall(intervall)
		{

		}

		miTaskBase(const std::string& name, int intervall, int cpuAffinity,
			int priority, miutils::SchedulerType schedulerType)
			:_Timer(name, intervall, cpuAffinity, priority, schedulerType, this)
			, _Time()
			, _TaskIntervall(intervall)
		{

		}

		virtual void timerEventOccured(miutils::TimerEventListenerObject, const std::string& name) override;
		void init();
		void deinit();
		void start();
		void stop();
		void addComponent(micomponents::miComponentBase* component);
		void addIOModul(mimodule::ModuleInterface* module);
		virtual void lock();
		virtual void unlock();
		const std::string name() const;
	};
}

