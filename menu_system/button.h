#ifndef BUTTON_H
#define BUTTON_H

#include "text.h"
#include "base_structure.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <list>

class Button : public BaseStructure
{
   public:

      Button (const std::string input_text, float ul_in[2], float width_in, float height_in);
      bool lclick   (float x, float y, float ul[2]);
      bool lunclick (float x, float y, float ul[2]);
      void show     (float ul[2], float *transform, float *translation);

  private:

      Text  text;
      float width, height;
      float ul[2];
};

#endif
