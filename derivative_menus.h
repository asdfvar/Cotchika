#ifndef DERIVATIVE_MENUS_H
#define DERIVATIVE_MENUS_H

#include "menu_system.h"

namespace menu {
   enum menuID {
      MAIN_MENU,
      BUILD_MENU,
      BUILD_MATERIAL_MENU
   };
};

class MainMenu : public BaseMenu
{
   public:

      MainMenu (void);
      ~MainMenu (void);

      int  get_menu_id (void)               override;

   private:

      Button *button_remove;
      Button *button_build;
};

class BuildMenu : public BaseMenu
{
   public:

      BuildMenu (void);
      ~BuildMenu (void);

      int  get_menu_id (void)               override;

   private:

      Button *button_material;
      Button *button_item;
};

class BuildMaterialMenu : public BaseMenu
{
   public:

      BuildMaterialMenu (void);
      ~BuildMaterialMenu (void);

      int  get_menu_id (void)               override;

   private:

      Button *button_dirt;
      Button *button_stone;
};

#endif
