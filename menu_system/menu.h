#ifndef MENU_H
#define MENU_H

#include "base_structure.h"
#include "menu_bar.h"
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

      Menu (void) : BaseStructure () { hit_menuBar = false; };

      int  lclick      (float x, float y);
      int  lunclick    (float x, float y);
      virtual int  get_menu_id (void) { return 0; };
      bool translate (float dx, float dy);
      void show (float *transform, float *translation);

   protected:

      float   width, height;
      int     menu_id;
      MenuBar menuBar;
      bool    hit_menuBar;

      void add_button (const std::string input_text);

      std::list<Button> buttons;
};

#endif
