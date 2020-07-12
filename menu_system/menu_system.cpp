#include "text.h"
#include "menu.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

MenuSystem::MenuSystem (void) : BaseStructure ()
{
   hit_menuBar = false;
   ul[0] = -0.8f;
   ul[1] =  0.8f;
};

void MenuSystem::reset (void)
{
   ul[0] = -0.8f;
   ul[1] =  0.8f;
}

void MenuSystem::add_menu (float width, float height)
{
   menus.push_back (Menu (width, height));
}

int MenuSystem::lclick (int menu_ind, float x, float y)
{
   auto menu = menus.begin ();
   for (int it = 0; menu != menus.end () && it < menu_ind; menu++, it++) {}

   menu = menus[menu_ind];
   menu.lclick (ul, x, y);

   float width  = menu.get_width ();
   float height = menu.get_height ();

   if (menuBar.hit (x, y, ul, width)) hit_menuBar = true;

   return 0;
}

int MenuSystem::lunclick (int menu_ind, float x, float y)
{
   hit_menuBar = false;

   auto menu = menus[menu_ind];
   menu.lunclick (ul, x, y);

   return 0;
}

void MenuSystem::show (int menu_ind, float *transform, float *translation)
{
   menuBar.show (ul, width, transform, translation);

   auto menu = menus[menu_ind];
   menu.show (transform, translation);
}

bool MenuSystem::translate (float dx, float dy)
{

   if (hit_menuBar)
   {
      ul[0] += dx;
      ul[1] += dy;
      menuBar.move (dx, dy);
      return true;
   }
   return false;
}

void MenuSystem::add_button (int menu_ind, const std::string input_text)
{
   auto menu = menus[menu_ind];
   menu.add_button (input_text);
}
