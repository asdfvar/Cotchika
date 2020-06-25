#ifndef X01_H
#define X01_H

#include "unit.h"

class Squiggly : public Unit
{
   public:
      Squiggly (float position[3], MAP* Map);

      void draw (float *transform, float *translation) override;
};

class Wiggly : public Unit
{
   public:
      Wiggly (float position[3], MAP* Map);

      void draw (float *transform, float *translation) override;
};

#endif
