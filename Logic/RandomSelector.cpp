// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include <Logic/RandomSelector.h>
#include <set>

#include <stdio.h>
#include <stdlib.h>


using std::set;

namespace OpenEngine {
namespace Logic {

  RandomSelector::RandomSelector() : Selector() {

  }

  RandomSelector::~RandomSelector() {

  }

  Task::TaskStatus RandomSelector::Execute() {
    TaskStatus status = TASK_FAIL;

    // Handle the current task, if one exists
    if (currentTask != NULL) {
        status = currentTask->Execute();
        if (status == TASK_RUNNING) {
            return TASK_RUNNING;
      } else {
            currentTask = NULL;
            if (status != TASK_FAIL) {
                return status;
            }
      }
    }

    deque<Task*> tasksCopy;

    // Create a copy of the task list
    deque<Task*>::iterator taskIter;
    for (taskIter = tasks.begin(); taskIter != tasks.end(); taskIter++) {
        Task* task = *taskIter;
        tasksCopy.push_back(task);
    }

    // Iterate randomly through the list of tasks
    while (!tasksCopy.empty()) {
        int index = (int)(((float)rand()/RAND_MAX)*tasksCopy.size());
        Task* task = tasksCopy[index];

        status = task->Execute();
        if (status == TASK_RUNNING) {
            currentTask = task;
            return TASK_RUNNING;
        } else {
            currentTask = NULL;
            if (status != TASK_FAIL) {
                return status;
            }
        }

        tasksCopy.erase(tasksCopy.begin()+index);
    }

    // All tasks failed
    return TASK_FAIL;
  }

}
}
