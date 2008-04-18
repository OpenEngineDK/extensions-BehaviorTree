// A task that relies on a callback function for execution
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _CALLBACK_TASK_H_
#define _CALLBACK_TASK_H_

#include <Logic/Task.h>
#include <EventSystem/Listener.h>

using namespace OpenEngine::EventSystem;

namespace OpenEngine {
namespace Logic {

  /**
   * A task that relies on a callback function for execution
   */
  template <class T>
  class CallbackTask : public Task {
  private:
    //! Reference to handler instance
    T& instance;
    //! Pointer to callback method
    Task::TaskStatus (T::*memberFunc)();

  public:
	CallbackTask(T& ins, Task::TaskStatus (T::*ptr)()): instance(ins) {
		SetCallback(ptr);
	}

    virtual ~CallbackTask() {
	
	}

	//! Change the callback method called upon execution
	void SetCallback(Task::TaskStatus (T::*ptr)()) {
		memberFunc = ptr;
	}

    virtual TaskStatus Execute() {
      return (instance.*memberFunc)();
    }
  };


}
}

#endif // _CALLBACK_TASK_H_
