// A structure that executes tasks sequentially
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <Logic/CompositeTask.h>

namespace OpenEngine {
namespace Logic {

  /**
   * A structure that executes tasks sequentially.
   *
   * @see http://aigamedev.com/hierarchical-logic/sequence
   */
  class Sequence : public CompositeTask {
  public:
    Sequence();
    virtual ~Sequence();
    virtual TaskStatus Execute();
  };

}
}

#endif // _SEQUENCE_H_
