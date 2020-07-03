#include "job_manager.h"

Job_manager::Job_manager (void)
{
   jobs_limit = 4;
   active_job = 0;
   initialize ();
};

Job_manager::~Job_manager (void)
{
   pthread_mutex_destroy (&lock);
}

void Job_manager::initialize (void) {
   pthread_mutex_init (&lock, nullptr);
};

void Job_manager::assign_job (Job *job)
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

bool Job_manager::available_job_slots (void)
{
   if (jobs_list.size () >= jobs_limit)
      return false;

   return true;
};

int Job_manager::num_jobs (void)
{
   return jobs_list.size ();
};

int Job_manager::num_return_jobs (void)
{
   return return_jobs.size ();
};

int Job_manager::num_total_jobs (void)
{
   return jobs_list.size () + return_jobs.size ();
};

Job *Job_manager::pop_return_job (void)
{
   Job *job = nullptr;

   pthread_mutex_lock (&lock);

   if (return_jobs.size () > 0)
      job = return_jobs.pop_back ();

   pthread_mutex_unlock (&lock);

   return job;
};

Job *Job_manager::pop_active_job (void)
{
   if (jobs_list.size () > 0) return jobs_list.pop_back ();
   else return nullptr;
};

void Job_manager::set_return_last_job (void)
{
   if (jobs_list.size () > 0) return_jobs.push_front (jobs_list.pop_back ());
};

void Job_manager::set_return_all_jobs (void)
{
   while (jobs_list.size () > 0) {
      Job *job = jobs_list.pop_back ();
      return_jobs.push_front (job);
   }
};

int Job_manager::get_active_job_position (int ind)
{
   if (jobs_list.size () > 0) return jobs_list.back ()->get_position (ind);
   else return -1;
};

void Job_manager::active_job_action (float energy)
{
   if (jobs_list.size () > 0) jobs_list.back ()->act (energy);
};

Job *Job_manager::access_job (int ind)
{
   if (jobs_list.size () <= 0) {
      std::cout << "error: no jobs to access" << std::endl;
      return nullptr;
   }
   return jobs_list.access (ind);
};

Job *Job_manager::access_active_job (void)
{
   if (jobs_list.size () <= 0) {
      std::cout << "error: no active jobs to access" << std::endl;
      return nullptr;
   }

   return jobs_list.back ();
};
