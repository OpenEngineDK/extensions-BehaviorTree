// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _TASK_DECORATOR_H_
#define _TASK_DECORATOR_H_

#include <Logic/Task.h>

namespace OpenEngine {
namespace Logic {

  /**
   * Task decorator. Allows for filtering tasks and enforcing specific behavior. Follows the Decorator Pattern.
   *
   * @see http://aigamedev.com/hierarchical-logic/decorator
   */
  class TaskDecorator : public Task {
  protected:
	  //! The decorated task
	  Task* decoratedTask;

  public:
	  TaskDecorator(Task* task) {
		decoratedTask = task;
	  }
	  virtual ~TaskDecorator() {};
	  //! Invokes the Execute()-method of the decorated task.
	  virtual TaskStatus Execute() {
		return decoratedTask->Execute();
	  }
  };

}
}

#endif // _TASK_DECORATOR_H_
