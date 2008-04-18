// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/DebugDecorator.h>
#include <typeinfo>
#include <string>

namespace OpenEngine {
namespace Logic {

	DebugDecorator::DebugDecorator(Task* task) : TaskDecorator(task) {

	}

	DebugDecorator::~DebugDecorator() {
	
	}

	Task::TaskStatus DebugDecorator::Execute() {
		TaskStatus status = TaskDecorator::Execute();
		std::string statusStr = "";
		switch (status) {
			case TASK_SUCCESS: statusStr = "success"; break;
			case TASK_RUNNING: statusStr = "running"; break;
			case TASK_FAIL: statusStr = "failed (cleanly)"; break;
			case TASK_ERROR: statusStr = "failed (erroneous)"; break;
			default: statusStr = "unknown status";
		}
		printf("Executed task '%s' with status: %s.\n", typeid(*decoratedTask).name(), statusStr.c_str());
		return status;
	}

}
}
