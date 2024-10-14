#pragma once
namespace mitasks
{
	class miTaskSync
	{
	public:
		virtual void lock() = 0;
		virtual void unlock() = 0;
	};
}
