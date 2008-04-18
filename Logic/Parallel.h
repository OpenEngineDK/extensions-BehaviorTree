// A structure that executes tasks in parallel
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _PARALLEL_H_
#define _PARALLEL_H_

#include <Logic/CompositeTask.h>

namespace OpenEngine {
namespace Logic {

  /**
   * A structure that executes tasks in parallel.
   * 
   * @see http://aigamedev.com/hierarchical-logic/parallel
   */
  class Parallel : public CompositeTask {
  private:
	bool succeedOnOne;
	bool failOnOne;

  public:
	/**
	 * @param succeedOnOne true if the parallel terminates successfully on the first successfully executed task
	 * @param failOnOne true if the parallel terminates unsuccessfully on the first executed task that failed
	 */
    Parallel(bool succeedOnOne = false, bool failOnOne = true);
    virtual ~Parallel();
    virtual TaskStatus Execute();
  };

}
}

#endif // _PARALLEL_H_
