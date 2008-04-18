// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/Parallel.h>

namespace OpenEngine {
namespace Logic {

  Parallel::Parallel(bool succeedOnOne, bool failOnOne) {
	this->succeedOnOne = succeedOnOne;
	this->failOnOne = failOnOne;
  }

  Parallel::~Parallel() {

  }

  Task::TaskStatus Parallel::Execute() {
    std::deque<Task*>::iterator taskIter;
	bool allSucceeded = true;
	bool allFailed = true;
	bool isRunning = false;

    for (taskIter = tasks.begin(); taskIter != tasks.end(); taskIter++) {
      Task* task = *taskIter;
      
      TaskStatus status = task->Execute();
	  if (status == TASK_SUCCESS) {
		  if (succeedOnOne) return TASK_SUCCESS;
		  allFailed = false;
	  } else if (status == TASK_FAIL) {
		  if (failOnOne || !succeedOnOne) return TASK_FAIL;
		  allSucceeded = false;
	  } else if (status == TASK_ERROR) {
		  return TASK_ERROR;
	  } else if (status == TASK_RUNNING) {
		  allFailed = false;
		  allSucceeded = false;
		  isRunning = true;
	  }
    }
	
	if (isRunning) return TASK_RUNNING;
	if (allSucceeded) return TASK_SUCCESS;
	if (allFailed) return TASK_FAIL;
	return TASK_ERROR;
  }

}
}
