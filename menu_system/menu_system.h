#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include "base_structure.h"
#include "menu_bar.h"
#include "menu.h"
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
      MenuSystem (void);
      void reset (void);
      void set_active_menu (int);
      int get_menu_id (void);
      bool is_active (void);
      int  lclick      (float x, float y);
      int  lunclick    (float x, float y);
      bool translate (float dx, float dy);
      void add_menu (float width, float height);
      void add_button (int menu_ind, const std::string input_text);
      void show (float *transform, float *translation);

   private:
      int active_menu_ind;

   protected:
      MenuBar menuBar;
      bool    hit_menuBar;
      float   ul[2];

      std::list<Menu> menus;
};

#endif
