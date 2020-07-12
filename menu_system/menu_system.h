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

class MenuSystem : public BaseStructure
{
   public:

      MenuSystem (void) : BaseStructure ();

      void reset (void);
      int  lclick      (float x, float y);
      int  lunclick    (float x, float y);
      virtual int  get_menu_id (void) { return 0; };
      bool translate (float dx, float dy);
      void add_menu (void);
      void show (float *transform, float *translation);

   protected:

      MenuBar menuBar;
      bool    hit_menuBar;
      float   ul[2];


      std::list<Menu> menus;
};

#endif
