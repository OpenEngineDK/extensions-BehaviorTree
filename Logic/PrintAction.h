// ?
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _PRINT_ACTION_H_
#define _PRINT_ACTION_H

#include <Logic/Task.h>
#include <string>

namespace OpenEngine {
namespace Logic {

  using std::string;

  class PrintAction : public Task {
  private:
    string text;

  public:
    PrintAction(string text) {
      this->text = text;
    }

    virtual ~PrintAction() {}

    virtual TaskStatus Execute() {
      printf((text + "\n").c_str());
      return TASK_SUCCESS;
    }
  };

}
}

#endif // _PRINT_ACTION_H_
