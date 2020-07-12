#include "text.h"
#include "menu.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

Menu::Menu (void) : BaseStructure () { };

int Menu::lclick (float ul[2], float x, float y)
{
   int it = 1;
   for (auto button = buttons.begin (); button != buttons.end (); button++, it++)
   {
      if (button->lclick (x, y, ul)) return it;
   }

   return 0;
}

int Menu::lunclick (float ul[2], float x, float y)
{
   int it = 1;
   for (auto button = buttons.begin (); button != buttons.end (); button++, it++)
   {
      if (button->lunclick (x, y, ul)) return it;
   }

   return 0;
}

void Menu::show (float ul[2], float *transform, float *translation)
{
   // Show the buttons
   for (auto button = buttons.begin (); button != buttons.end (); button++)
      button->show (ul, transform, translation);

   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glColor4f (0.7f, 0.3f, 0.3f, alpha);

   float point[2];

   // Draw the border
   glBegin (GL_POLYGON);

   point[0] = ul[0];
   point[1] = ul[1];
   transformation (point, transform, translation);
   glVertex3f (point[0], point[1], -0.2f);

   point[0] = ul[0] + width;
   point[1] = ul[1];
   transformation (point, transform, translation);
   glVertex3f (point[0], point[1], -0.2f);

   point[0] = ul[0] + width;
   point[1] = ul[1] - height;
   transformation (point, transform, translation);
   glVertex3f (point[0], point[1], -0.2f);

   point[0] = ul[0];
   point[1] = ul[1] - height;
   transformation (point, transform, translation);
   glVertex3f (point[0], point[1], -0.2f);

   glEnd ();
}

void Menu::add_button (const std::string input_text)
{
   float button_width = 0.2f;
   float button_height = 0.1f;

   float button_ul[2];

   button_ul[0] =  0.02f;
   button_ul[1] = -0.09f;

   float step = -0.11f;

   button_ul[1] += (float)buttons.size () * step;

   Button button (input_text, button_ul, button_width, button_height);

   buttons.push_back (button);
}
