#include "text.h"
#include "button.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

Button::Button (const std::string input_text, float ul_in[2], float width_in, float height_in) : BaseStructure ()
{
   text.populate (input_text);

   ul[0]  = ul_in[0];
   ul[1]  = ul_in[1];

   width  = width_in;
   height = height_in;
}

bool Button::lclick (float x, float y, float menu_ul[2])
{
   if (menu_ul[0] + ul[0] + width >= x && x >= menu_ul[0] + ul[0] &&
         menu_ul[1] + ul[1] >= y && y >= menu_ul[1] + ul[1] - height)
      return true;

   return false;
}

bool Button::lunclick (float x, float y, float menu_ul[2])
{
   if (menu_ul[0] + ul[0] + width >= x && x >= menu_ul[0] + ul[0] &&
         menu_ul[1] + ul[1] >= y && y >= menu_ul[1] + ul[1] - height)
      return true;

   return false;
}

float Button::get_width (void)
{
   return text.get_width (1.0f);
}

void Button::show (float menu_ul[2], float *transform, float *translation)
{
   text.display_contents (
         menu_ul[0] + ul[0], // x
         menu_ul[1] + ul[1], // y
         alpha, // alpha
         1.0f); // scale

   // draw the boundary of the button
   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glColor4f (0.9f, 0.9f, 0.9f, alpha);

   glBegin (GL_POLYGON);
   glVertex3f (menu_ul[0] + ul[0],         menu_ul[1] + ul[1]          + 0.02f, -0.3f);
   glVertex3f (menu_ul[0] + ul[0] + width, menu_ul[1] + ul[1]          + 0.02f, -0.3f);
   glVertex3f (menu_ul[0] + ul[0] + width, menu_ul[1] + ul[1] - height + 0.02f, -0.3f);
   glVertex3f (menu_ul[0] + ul[0],         menu_ul[1] + ul[1] - height + 0.02f, -0.3f);
   glEnd ();
}
