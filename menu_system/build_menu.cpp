#include "text.h"
#include "menu_system.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

BuildMenu::BuildMenu (void) : BaseMenu ()
{
   menu_id = 2;

   width  = 0.3f;
   height = 0.3f;

   float button_width = 0.25f;
   float button_height = 0.1f;

   float button_ul[2];

   button_ul[0] =  0.02f;
   button_ul[1] = -0.09f;

   button_material = new Button ("material", button_ul, button_width, button_height);

   button_ul[0] =  0.02f;
   button_ul[1] = -0.2f;

   button_item  = new Button ("item", button_ul, button_width, button_height);

   add_button ("material");
   add_button ("item"    );
}

BuildMenu::~BuildMenu (void)
{
   delete button_material;
   delete button_item;
}

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
