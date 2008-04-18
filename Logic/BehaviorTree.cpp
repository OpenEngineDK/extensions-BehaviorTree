// Task that encapsulates an behavior tree of tasks.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/BehaviorTree.h>
#include <stdio.h>

namespace OpenEngine {
namespace Logic {

  BehaviorTree::BehaviorTree(Task* task) : TaskDecorator(task) {
	
  }

  BehaviorTree::~BehaviorTree() {

  }

  Task::TaskStatus BehaviorTree::Execute() {
	  Task::TaskStatus status = TaskDecorator::Execute();
	  if (status == Task::TASK_ERROR) {
		  printf("[BehaviorTree::Execute] An error occured in a task causing the behavior tree to terminate execution.\n");
		  return Task::TASK_ERROR;
	  }
	  return Task::TASK_RUNNING;
  }

}
}
