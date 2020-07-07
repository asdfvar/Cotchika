#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include "text.h"
#include "utils.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <list>

class MenuSystem
{
   public:

      MenuSystem (void)
      {
         alpha = 0.8f;

         ul[0] = -0.8f;
         ul[1] =  0.8f;
      }

      void reset (void)
      {
         ul[0] = -0.8f;
         ul[1] =  0.8f;
      }

      void move (float dx, float dy)
      {
         ul[0] += dx;
         ul[1] += dy;
      }

      virtual void show (float *tranform, float *translation) { };

   protected:

      float alpha;
      float ul[2];
      float width;
      float height;
};

class Button : public MenuSystem
{
   public:

      Button (const std::string input_text, float ul_in[2], float width_in, float height_in);
      bool lclick   (float x, float y, float ul[2]);
      bool lunclick (float x, float y, float ul[2]);
      void show     (float ul[2], float *transform, float *translation);

  private:

      Text  text;
      float width, height;
};

class MenuBar : public MenuSystem
{
   public:

      MenuBar (void);
      void show (float ul[2], float width, float *transform, float *translation);
      bool hit  (float x, float y, float ul[2], float width);
};

class BaseMenu : public MenuSystem
{
   public:

      BaseMenu (void) : MenuSystem () { hit_menuBar = false; };

      int  lclick      (float x, float y);
      int  lunclick    (float x, float y);
      virtual int  get_menu_id (void) { return 0; };
      bool translate (float dx, float dy);
      void show (float *transform, float *translation);

   protected:

      float   width, height;
      int     menu_id;
      MenuBar menuBar;
      bool    hit_menuBar;

      void add_button (const std::string input_text);

      std::list<Button> buttons;
};

#endif
