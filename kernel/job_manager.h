#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include "container.h"
#include "jobs.h"
#include <pthread.h>

// assess backlog jobs for inclusion in the accessible jobs list.

// given copies of: unit locations, accessibility map, job locations and type.

// for each job location that is backlogged:
// test if the job location is enclosed.
// test if the job location is accessible to any unit.
// if all tests pass, add to the list of candidate accessible jobs.

// for each candidate accessible job:
// test if completing the job makes any of the other candidate and currently existing accessible jobs no longer accessible. any that don't pass are added back to the backlog.

// for each remaining candidate accessible job:
// find the job closest to any unit (not necessarily unique) and push that to the front of the available jobs list (FIFO).

class Job_manager
{
   public:

      Job_manager (void)
      {
         jobs_limit = 4;
         active_job = 0;
         initialize ();
      };

      ~Job_manager (void)
      {
         pthread_mutex_destroy (&lock);
      }

      void initialize (void) {
         pthread_mutex_init (&lock, nullptr);
      };

      void assign_job (Job *job)
      {
         if (jobs_list.size () >= jobs_limit)
         {
            std::cout
               << "Not enough available job slots"
               << std::endl;
            return;
         }

         jobs_list.push_front (job);
      };

      bool available_job_slots (void)
      {
         if (jobs_list.size () >= jobs_limit)
            return false;

         return true;
      };

      int num_jobs (void)
      {
         return jobs_list.size ();
      };

      int num_return_jobs (void)
      {
         return return_jobs.size ();
      };

      int num_total_jobs (void)
      {
         return jobs_list.size () + return_jobs.size ();
      };

      Job *pop_return_job (void)
      {
         Job *job = nullptr;

         pthread_mutex_lock (&lock);

         if (return_jobs.size () > 0)
            job = return_jobs.pop_back ();

         pthread_mutex_unlock (&lock);

         return job;
      };

      Job *pop_active_job (void)
      {
         if (jobs_list.size () > 0) return jobs_list.pop_back ();
         else return nullptr;
      };

      void set_return_last_job (void)
      {
         if (jobs_list.size () > 0) return_jobs.push_front (jobs_list.pop_back ());
      };

      void set_return_all_jobs (void)
      {
         while (jobs_list.size () > 0) {
            Job *job = jobs_list.pop_back ();
            return_jobs.push_front (job);
         }
      };

      int get_active_job_position (int ind)
      {
         if (jobs_list.size () > 0) return jobs_list.back ()->get_position (ind);
         else return -1;
      };

      void active_job_action (float energy)
      {
         if (jobs_list.size () > 0) jobs_list.back ()->act (energy);
      };

      Job *access_job (int ind)
      {
         if (jobs_list.size () <= 0) {
            std::cout << "error: no jobs to access" << std::endl;
            return nullptr;
         }
         return jobs_list.access (ind);
      };

      Job *access_active_job (void)
      {
         if (jobs_list.size () <= 0) {
            std::cout << "error: no active jobs to access" << std::endl;
            return nullptr;
         }

         return jobs_list.back ();
      };

   private:

      pthread_mutex_t lock;

      Job            *active_job;
      int             jobs_limit;
      Container<Job>  jobs_list;
      Container<Job>  return_jobs;
};
#endif
