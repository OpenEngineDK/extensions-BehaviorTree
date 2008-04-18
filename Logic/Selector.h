// A structure that executes tasks the order of which is choosen according to some critia
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _SELECTOR_H_
#define _SELECTOR_H_

#include <Logic/CompositeTask.h>

namespace OpenEngine {
namespace Logic {

  /**
   * A structure that executes tasks the order of which is choosen according to some critia.
   *
   * @see http://aigamedev.com/hierarchical-logic/selector
   */
  class Selector : public CompositeTask {
  public:
    Selector();
    virtual ~Selector();
    virtual TaskStatus Execute();
  };

}
}

#endif // _SELECTOR_H_
