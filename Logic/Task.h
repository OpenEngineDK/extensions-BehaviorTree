// Task primitive
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _TASK_H_
#define _TASK_H_

namespace OpenEngine {
namespace Logic {

  /**
   * Task primitive for the behavior tree.
   * Follows the Command Pattern.
   *
   * @see http://aigamedev.com/programming-tips/tasks
   */
  class Task {
  public:
    //! Specifies the data type for the status of the execution of a task
	enum TaskStatus {
		TASK_RUNNING, //! Task is not finished executing
		TASK_SUCCESS, //! Task finished successfully
		TASK_FAIL,    //! Task finished unsuccessfully
		TASK_ERROR    //! An error caused the task to terminate
	};

	//! Destructor
	virtual ~Task() {}

	/**
	 * Execute a step in the task.
	 * @return status of the execution
	 * @see TaskStatus
	 */
	virtual TaskStatus Execute() = 0;
  };

}
}

#endif // _TASK_H_
