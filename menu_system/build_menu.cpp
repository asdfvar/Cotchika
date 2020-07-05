#include "text.h"
#include "derivative_menus.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

BuildMenu::BuildMenu (void) : BaseMenu ()
{
   menu_id = menu::BUILD_MENU;

   width  = 0.3f;
   height = 0.3f;

   add_button ("material");
   add_button ("item"    );
}

BuildMenu::~BuildMenu (void) { /* pass */ }

int BuildMenu::get_menu_id (void)
{
   return menu_id;
};

void BuildMenu::show (void)
{
   BaseMenu::show_components (ul);

   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glColor4f (0.7f, 0.3f, 0.3f, alpha);

   // Draw the border
   glBegin (GL_POLYGON);
   glVertex3f (ul[0],         ul[1],          -0.2f);
   glVertex3f (ul[0] + width, ul[1],          -0.2f);
   glVertex3f (ul[0] + width, ul[1] - height, -0.2f);
   glVertex3f (ul[0],         ul[1] - height, -0.2f);
   glEnd ();
}

void BuildMenu::translate (float dx, float dy)
{
   if (hit_menuBar)
   {
      move (dx, dy);
      menuBar.move (dx, dy);
   }
}
