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

         ul[0] = -0.8f;
         ul[1] =  0.8f;
      }

      void reset (void)
      {
         ul[0] = -0.8f;
         ul[1] =  0.8f;
      }

      void move (float dx, float dy)
      {
         ul[0] += dx;
         ul[1] += dy;
      }

      virtual void show (float *tranform, float *translation) { };

   protected:

      float alpha;
      float ul[2];
      float width;
      float height;
};

#endif
