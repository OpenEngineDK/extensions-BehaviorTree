// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/LoopOnSuccessDecorator.h>
#include <typeinfo>
#include <string>

namespace OpenEngine {
namespace Logic {

	LoopOnSuccessDecorator::LoopOnSuccessDecorator(Task* task) : TaskDecorator(task) {

	}

	LoopOnSuccessDecorator::~LoopOnSuccessDecorator() {
	
	}

	Task::TaskStatus LoopOnSuccessDecorator::Execute() {
		TaskStatus status = TaskDecorator::Execute();
		if (status == TASK_SUCCESS || status == TASK_RUNNING) {
			return TASK_RUNNING;
		}
		if (status == TASK_FAIL) {
			return TASK_SUCCESS; // We're done looping, thus we end successfully
		}
		return status;
	}

}
}
