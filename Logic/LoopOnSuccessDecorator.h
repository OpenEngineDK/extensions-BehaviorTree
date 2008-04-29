// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _LOOP_ON_SUCCESS_DECORATOR_H_
#define _LOOP_ON_SUCCESS_DECORATOR_H_

#include <Logic/TaskDecorator.h>

namespace OpenEngine {
namespace Logic {


  class LoopOnSuccessDecorator : public TaskDecorator {
  public:
	  LoopOnSuccessDecorator(Task* task);
	  virtual ~LoopOnSuccessDecorator();
	  virtual TaskStatus Execute();
  };

}
}

#endif // _LOOP_ON_SUCCESS_DECORATOR_H_
