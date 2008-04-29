// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Logic/ProbabilitySelector.h>

namespace OpenEngine {
namespace Logic {

  ProbabilitySelector::ProbabilitySelector() : Task() {
    totalWeight = 0;
    currentTask = NULL;
  }

  ProbabilitySelector::~ProbabilitySelector() {

  }

  Task::TaskStatus ProbabilitySelector::Execute() {
    if (currentTask != NULL) {
      TaskStatus status = currentTask->Execute();
      if (status != TASK_RUNNING) {
      	currentTask = NULL;
      }
      if (status != TASK_FAIL) {
        return status;
      }
    }
    
    int selectedWeight = (int)(((float)std::rand()/RAND_MAX)*totalWeight);
    int weightCounter = 0;
    
    std::vector<WeightedTask>::iterator weightedTaskIter;
    for (weightedTaskIter = weightedTasks.begin(); weightedTaskIter != weightedTasks.end(); weightedTaskIter++) {
      WeightedTask weightedTask = *weightedTaskIter;
	  weightCounter += weightedTask.weight;
      if (weightedTask.weight > 0 && weightCounter > selectedWeight) {
        TaskStatus status = weightedTask.task->Execute();
        if (status == TASK_RUNNING) {
          currentTask = weightedTask.task;
        }
        // TODO: Handle fallback on a failing task!!!!!!
        return status;
      }
    }
    
    return TASK_FAIL;
  }
  
  void ProbabilitySelector::AddTask(Task* task, unsigned int weight) {
    weightedTasks.push_back(WeightedTask(task, weight));
    totalWeight += weight;
  }

}
}
