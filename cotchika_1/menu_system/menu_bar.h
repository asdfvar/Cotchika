#ifndef MENU_BAR_H
#define MENU_BAR_H

#include "base_structure.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <list>

class MenuBar : public BaseStructure
{
   public:

      MenuBar (void);
      void show (float ul[2], float width, float *transform, float *translation);
      bool hit  (float x, float y, float ul[2], float width);
};

#endif
