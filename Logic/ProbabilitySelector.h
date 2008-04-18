// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _PROBABILITY_SELECTOR_H_
#define _PROBABILITY_SELECTOR_H_

#include <Logic/Task.h>

#include <vector>
using std::vector;

namespace OpenEngine {
namespace Logic {

  class ProbabilitySelector : public Task {
  protected:
      struct WeightedTask {
        Task* task;
        unsigned int weight;
        WeightedTask(Task* t, unsigned int w) {task = t; weight = w;}
      };
      vector<WeightedTask> weightedTasks;
      unsigned int totalWeight;
      
      Task* currentTask;
    
  public:
	  ProbabilitySelector();
	  virtual ~ProbabilitySelector();
	  virtual TaskStatus Execute();
      
      virtual void AddTask(Task* task, unsigned int weight);
  };

}
}

#endif // _PROBABILITY_SELECTOR_H_
