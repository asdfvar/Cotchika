#ifndef MENU_H
#define MENU_H

#include "base_structure.h"
#include "button.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <list>

class Menu : public BaseStructure
{
   public:

      Menu (float width_in, float height_in);

      int  lclick      (float ul[2], float x, float y);
      int  lunclick    (float ul[2], float x, float y);
      virtual int  get_menu_id (void) { return 0; };
      void add_button (const std::string input_text);
      void show (float ul[2], float *transform, float *translation);
      float get_width  (void) { return width;  };
      float get_height (void) { return height; };

   protected:

      float width;
      float height;
      std::list<Button> buttons;
};

#endif
