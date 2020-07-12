#ifndef BASE_STRUCTURE_H
#define BASE_STRUCTURE_H

#include "text.h"
#include "utils.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <list>

class BaseStructure
{
   public:

      BaseStructure (void)
      {
         alpha = 0.8f;
      }

   protected:

      float alpha;
};

#endif
