#include "miTaskBase.h"

void mitasks::miTaskBase::timerEventOccured(miutils::TimerEventListenerObject, const std::string& name)
{
	for (auto module : _ModuleList)
	{
		module->readInputs(false);
	}
	for (auto component : _ComponentList)
	{
		component->componentProcess(_TaskIntervall, _Time.getMsTickCount());
	}
	for (auto module : _ModuleList)
	{
		module->writeOutputs();
	}
}

void mitasks::miTaskBase::init()
{
	for (auto module : _ModuleList)
	{
		module->init();
	}
}

void mitasks::miTaskBase::deinit()
{
	for (auto module : _ModuleList)
	{
		module->deinit();
	}
}

void mitasks::miTaskBase::start()
{
	for (auto module : _ModuleList)
	{
		module->open();
	}
	for (auto component : _ComponentList)
	{
		component->componentStart();
	}
	_Timer.Start();
}

void mitasks::miTaskBase::stop()
{
	_Timer.Stop();
	for (auto module : _ModuleList)
	{
		module->close();
	}
	for (auto component : _ComponentList)
	{
		component->componentStop();
	}
}

void mitasks::miTaskBase::addComponent(micomponents::miComponentBase* component)
{
	if (component == nullptr)
	{
		return;
	}
	_ComponentList.push_back(component);
}

void mitasks::miTaskBase::addIOModul(mimodule::ModuleInterface* module)
{
	if (module == nullptr)
	{
		return;
	}
	_ModuleList.push_back(module);
}

void mitasks::miTaskBase::lock()
{
	_Timer.Lock();
}
void mitasks::miTaskBase::unlock()
{
	_Timer.Unlock();
}

const std::string mitasks::miTaskBase::name() const
{
	return _Timer.name();
}