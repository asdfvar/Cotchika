#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include "container.h"
#include "jobs.h"
#include <pthread.h>

class Job_manager
{
   public:

      Job_manager (void);
      ~Job_manager (void);

      void initialize (void);
      void assign_job (Job *job);
      bool available_job_slots (void);
      int num_jobs (void);
      int num_return_jobs (void);
      int num_total_jobs (void);
      Job *pop_return_job (void);
      Job *pop_active_job (void);
      void set_return_last_job (void);
      void set_return_all_jobs (void);
      int get_active_job_position (int ind);
      void active_job_action (float energy);
      Job *access_job (int ind);
      Job *access_active_job (void);

   private:

      pthread_mutex_t lock;

      Job            *active_job;
      int             jobs_limit;
      Container<Job>  jobs_list;
      Container<Job>  return_jobs;
};
#endif
