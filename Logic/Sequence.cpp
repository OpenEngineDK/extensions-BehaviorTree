// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/Sequence.h>

namespace OpenEngine {
namespace Logic {

  Sequence::Sequence() : CompositeTask() {
	
  }

  Sequence::~Sequence() {

  }

  Task::TaskStatus Sequence::Execute() {
    std::deque<Task*>::iterator taskIter;
    for (taskIter = tasks.begin(); taskIter != tasks.end(); taskIter++) {
      Task* task = *taskIter;
	  if (currentTask != NULL && task != currentTask) {
		  continue;
	  }

	  currentTask = NULL;
      TaskStatus status = task->Execute();
      switch (status) {
		case TASK_RUNNING: 
			currentTask = task;
			return status;
		case TASK_FAIL:
		case TASK_ERROR:
			return status;
		default:
			break;
      }
    }
	return TASK_SUCCESS;
  }

}
}
