#include "derivative_units.h"

Squiggly::Squiggly (float position[3], MAP* Map) : Unit { position, Map }
{
   max_weight = 100000;
}

Wiggly::Wiggly (float position[3], MAP* Map) : Unit { position, Map }
{
   max_weight = 200000;
}
