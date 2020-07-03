#ifndef ITEM_H
#define ITEM_H

namespace mid
{
  enum Type {
     empty,
     dry_dirt,
     wet_dirt,
     dry_clay,
     wet_clay,
     dry_gravel,
     wet_gravel,
     limestone,
     loam,
     mud,
     dry_sand,
     wet_sand,
     grass,
     stone,
     num_types };

   // Density in g/m^3
   static int get_density (const unsigned int item)
   {
      int density = 0;

      if      (item == mid::dry_dirt  ) density = 1220000;
      else if (item == mid::wet_dirt  ) density = 1250000;
      else if (item == mid::dry_clay  ) density = 1600000;
      else if (item == mid::wet_clay  ) density = 1600000;
      else if (item == mid::dry_gravel) density = 1680000;
      else if (item == mid::wet_gravel) density = 2000000;
      else if (item == mid::limestone ) density = 2560000;
      else if (item == mid::loam      ) density = 1280000;
      else if (item == mid::mud       ) density = 1730000;
      else if (item == mid::dry_sand  ) density = 1555000;
      else if (item == mid::wet_sand  ) density = 1905000;
      else if (item == mid::grass     ) density = 1250000;
      else if (item == mid::stone     ) density = 2480000;

      return density;
   }

   // Energy in J/m^3
   static int get_energy (const unsigned int item)
   {
      float density = get_density (item);

      // Convert to kg/m^3 then multiply by 1 to get J/m^3
      // (Energy to move 1 kg by 1 m)
      float energy = (float)density / 1000.0f;

      return energy;
   }
};

#endif
