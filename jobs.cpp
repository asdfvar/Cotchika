#include "jobs.h"
#include "material.h"
#include <iostream>

Job::Job (int flattened_index_in, int location_in[3])
{
   init (flattened_index_in, location_in);
}

void Job::init (int flattened_index_in, int location_in[3])
{
   flattened_loc_index = flattened_index_in;

   location[0] = location_in[0];
   location[1] = location_in[1];
   location[2] = location_in[2];

   energy     = 0.2f;
   work       = 0.0f;
   complete   = false;
}

void Job::act (float Qin)
{
   work += Qin;

   if (work >= energy) complete = true;
}

int Job::get_weight (void)
{
   int density = mid::get_density (material);

   return density * 1;
}

JobRemove::JobRemove (
      int flattened_index_in,
      int location_in[3],
      unsigned int material_in) : Job (flattened_index_in, location_in)
{
   job_type = jid::REMOVE;

   material = material_in;

   energy = mid::get_energy (material);
}

JobBuild::JobBuild (
      int flattened_index_in,
      int location_in[3],
      unsigned int material_in) : Job (flattened_index_in, location_in)
{
   job_type = jid::BUILD;

   material = material_in;

   energy = mid::get_energy (material);
}
