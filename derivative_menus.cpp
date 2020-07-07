#include "derivative_menus.h"
#include "text.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

/******************************************************************************
 * Main menu                                                                  *
 *****************************************************************************/

MainMenu::MainMenu (void) : BaseMenu ()
{
   menu_id = menu::MAIN_MENU;

   width  = 0.25f;
   height = 0.3f;

   add_button ("remove");
   add_button ("build" );
}

MainMenu::~MainMenu (void) { /* pass */ }

int MainMenu::get_menu_id (void)
{
   return menu_id;
};

void MainMenu::show (float *transform, float *translation)
{
   BaseMenu::show_components (ul, transform, translation);

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

/******************************************************************************
 * Build-materials menu                                                       *
 *****************************************************************************/

BuildMaterialMenu::BuildMaterialMenu (void) : BaseMenu ()
{
   menu_id = menu::BUILD_MATERIAL_MENU;

   width  = 0.3f;
   height = 0.3f;

   add_button ("dirt" );
   add_button ("stone");
}

BuildMaterialMenu::~BuildMaterialMenu (void) { /* pass */ }

int BuildMaterialMenu::get_menu_id (void)
{
   return menu_id;
};

void BuildMaterialMenu::show (float *transform, float *translation)
{
   BaseMenu::show_components (ul, transform, translation);

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

/******************************************************************************
 * Build menu                                                                 *
 *****************************************************************************/

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

void BuildMenu::show (float *transform, float *translation)
{
   BaseMenu::show_components (ul, transform, translation);

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
