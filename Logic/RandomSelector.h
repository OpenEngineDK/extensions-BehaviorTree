// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _RANDOM_SELECTOR_H_
#define _RANDOM_SELECTOR_H_

#include <Logic/Selector.h>

namespace OpenEngine {
namespace Logic {

  class RandomSelector : public Selector {
  public:
	  RandomSelector();
	  virtual ~RandomSelector();
	  virtual TaskStatus Execute();
  };

}
}

#endif // _RANDOM_SELECTOR_H_
