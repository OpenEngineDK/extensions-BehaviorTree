// A structure that executes tasks the order of which is choosen according to some critia
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/Selector.h>

namespace OpenEngine {
namespace Logic {

  Selector::Selector() : CompositeTask() {
	
  }

  Selector::~Selector() {

  }

  Task::TaskStatus Selector::Execute() {
    std::deque<Task*>::iterator taskIter;
    for (taskIter = tasks.begin(); taskIter != tasks.end(); taskIter++) {
      Task* task = *taskIter;
	  if (currentTask != NULL && task != currentTask) {
		  continue;
	  }

      TaskStatus status = task->Execute();
      if (status != TASK_FAIL) {
          if (status == TASK_RUNNING) {
            currentTask = task;
          } else {
            currentTask = NULL;
          }
          return status;
      }
    }
	return TASK_FAIL;
  }
  
}
}
