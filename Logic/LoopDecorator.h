// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _LOOP_DECORATOR_H_
#define _LOOP_DECORATOR_H_

#include <Logic/TaskDecorator.h>

namespace OpenEngine {
namespace Logic {

  class LoopDecorator : public TaskDecorator {
  protected:
	  int loops;
	  int count;

  public:
	  LoopDecorator(Task* task, int loops);
	  virtual ~LoopDecorator();

	  virtual TaskStatus Execute();
	  int GetLoopCount();
	  void SetLoopCount(int loops);
	  int GetLoop();
  };

}
}

#endif // _LOOP_DECORATOR_H_
