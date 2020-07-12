#include "menu_system.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

MenuSystem::MenuSystem (void) : BaseStructure ()
{
   hit_menuBar = false;
   active_menu_ind = -1;
   ul[0] = -0.8f;
   ul[1] =  0.8f;
};

void MenuSystem::reset (void)
{
   active_menu_ind = -1;
   ul[0] = -0.8f;
   ul[1] =  0.8f;
}

void MenuSystem::set_active_menu (int menu_ind)
{
   active_menu_ind = menu_ind;
}

int MenuSystem::get_menu_id (void)
{
   return active_menu_ind;
}

bool MenuSystem::is_active (void)
{
   if (active_menu_ind >= 0) return true;
   return false;
}

void MenuSystem::add_menu (float width, float height)
{
   menus.push_back (Menu (width, height));
}

int MenuSystem::lclick (float x, float y)
{
   auto menu = menus.begin ();
   for (int it = 0; menu != menus.end () && it < active_menu_ind; menu++, it++) {}

   float width  = menu->get_width ();
   float height = menu->get_height ();

   if (menuBar.hit (x, y, ul, width)) hit_menuBar = true;

   return menu->lclick (ul, x, y);
}

int MenuSystem::lunclick (float x, float y)
{
   hit_menuBar = false;

   auto menu = menus.begin ();
   for (int it = 0; menu != menus.end () && it < active_menu_ind; menu++, it++) {}
   return menu->lunclick (ul, x, y);
}

void MenuSystem::show (float *transform, float *translation)
{
   auto menu = menus.begin ();
   for (int it = 0; menu != menus.end () && it < active_menu_ind; menu++, it++) {}
   menu->show (ul, transform, translation);

   float width = menu->get_width ();
   menuBar.show (ul, width, transform, translation);
}

bool MenuSystem::translate (float dx, float dy)
{

   if (hit_menuBar)
   {
      ul[0] += dx;
      ul[1] += dy;
      return true;
   }
   return false;
}

void MenuSystem::add_button (int menu_ind, const std::string input_text)
{
   auto menu = menus.begin ();
   for (int it = 0; menu != menus.end () && it < menu_ind; menu++, it++) {}
   menu->add_button (input_text);
}
