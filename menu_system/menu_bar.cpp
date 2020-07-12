#include "menu_bar.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

MenuBar::MenuBar (void) : BaseStructure () { }

void MenuBar::show (float ul[2], float width, float *transform, float *translation)
{
   // draw the boundary of the button
   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glColor4f (0.1f, 0.1f, 0.1f, alpha);

   glBegin (GL_POLYGON);
   glVertex3f (ul[0]         + 0.01f, ul[1] - 0.01f, -0.3f);
   glVertex3f (ul[0] + width - 0.01f, ul[1] - 0.01f, -0.3f);
   glVertex3f (ul[0] + width - 0.01f, ul[1] - 0.04f, -0.3f);
   glVertex3f (ul[0]         + 0.01f, ul[1] - 0.04f, -0.3f);
   glEnd ();
}

bool MenuBar::hit (float x, float y, float ul[2], float width)
{
   if (ul[0] <= x && x <= ul[0] + width &&
         ul[1] - 0.04f <= y && y <= ul[1]) return true;

   return false;
}
