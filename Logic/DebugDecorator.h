// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _DEBUG_DECORATOR_H_
#define _DEBUG_DECORATOR_H_

#include <Logic/TaskDecorator.h>

namespace OpenEngine {
namespace Logic {


  class DebugDecorator : public TaskDecorator {
  public:
	  DebugDecorator(Task* task);
	  virtual ~DebugDecorator();
	  virtual TaskStatus Execute();
  };

}
}

#endif // _DEBUG_DECORATOR_H_
