// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _COMPOSITE_TASK_H_
#define _COMPOSITE_TASK_H_

#include <Logic/Task.h>

#include <deque>
using std::deque;

namespace OpenEngine {
namespace Logic {

  class CompositeTask : public Task {
  protected:
	deque<Task*> tasks;
    //! The currently running task
	Task* currentTask;

  public:
    CompositeTask();
	virtual ~CompositeTask();
	virtual TaskStatus Execute() = 0;
	
    virtual void PrependTask(Task* task);
	virtual void AppendTask(Task* task);
  };

}
}

#endif // _COMPOSITE_TASK_H_
