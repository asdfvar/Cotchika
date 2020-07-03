#include "derivative_units.h"

Wiggly::Wiggly (float position[3], MAP* Map) : Unit { position, Map }
{
   max_weight = 20000000;
}

Squiggly::Squiggly (float position[3], MAP* Map) : Unit { position, Map }
{
   max_weight = 10000000;
}
