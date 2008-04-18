// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/LoopDecorator.h>

namespace OpenEngine {
namespace Logic {

	LoopDecorator::LoopDecorator(Task* task, int loops) : TaskDecorator(task) {
		this->loops = loops;
		count = 0;
	}

	LoopDecorator::~LoopDecorator() {};

	Task::TaskStatus LoopDecorator::Execute() {
	  if (loops == 0) return TASK_SUCCESS; // ensure no iterations if loop count is zero

	  TaskStatus status = TaskDecorator::Execute();
	  if (status == TASK_SUCCESS || status == TASK_FAIL) {
		  count++;
		  if (count >= loops) {
			  count = 0; // reset the counter
			  return TASK_SUCCESS;
		  }
	  } else if (status == TASK_ERROR) {
		  return TASK_ERROR;
	  }

	  return TASK_RUNNING;
	}

	int LoopDecorator::GetLoopCount() { 
		return loops; 
	}

	void LoopDecorator::SetLoopCount(int loops) { 
		this->loops = loops; 
	}

	int LoopDecorator::GetLoop() { 
		return count; 
	}

}
}
