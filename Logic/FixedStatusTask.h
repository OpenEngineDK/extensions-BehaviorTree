// Task that always returns a fixed status
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _FIXED_STATUS_TASK_H_
#define _FIXED_STATUS_TASK_H_

#include <Logic/Task.h>

namespace OpenEngine {
namespace Logic {

  class FixedStatusTask : public Task {
  private:
  	TaskStatus status;
  
  public:
	FixedStatusTask(TaskStatus status) : Task() { 
		this->status = status;
	}
	virtual ~FixedStatusTask() {}

	virtual TaskStatus Execute() {
		return status;
	}
	
	TaskStatus GetStatus() {
		return status;
	}
	
	void SetStatus(TaskStatus status) {
		this->status = status;
	}
  };

}
}

#endif // _FIXED_STATUS_TASK_H_
