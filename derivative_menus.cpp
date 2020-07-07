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
