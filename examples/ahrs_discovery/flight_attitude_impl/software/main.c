#include <activity.h>
#include <po_hi_task.h>
#include <po_hi_main.h>
#include <po_hi_time.h>
/*****************************************************/
/*  This file was automatically generated by Ocarina */
/*  Do NOT hand-modify this file, as your            */
/*  changes will be lost when you re-run Ocarina     */
/*****************************************************/

/*!
 * \fn __PO_HI_MAIN_TYPE __PO_HI_MAIN_NAME (void)
 * \brief Main function executed by the system
 *
 * Full function name and return types are available  in the PolyORB-HI-C 
 * runtime header files.
 */
__PO_HI_MAIN_TYPE __PO_HI_MAIN_NAME (void)
{
  
/*!
 * \var period
 * \brief Variable for task period
 *
 * This variable is used to store the valueof the period of a task when we 
 * create it. The value put in the variable is set according to AADL model 
 * description
 */
  __po_hi_time_t period;

  __po_hi_initialize_early ();
  
/*!
 * Initialize the runtime
 */
  __po_hi_initialize ();
  
/*!
 * Store the period time for task accelero_thread
 */
  __po_hi_milliseconds (&(period), 80);
  
/*!
 * \brief Making Periodic Task accelero_thread
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (software_accelero_thread_k) the second is the period defined in the AADL
 *  model. Third is the task priority ( 5), fourth is the stack size ( 512 
 * bytes) and last is the subprogram executed by the task
 */
  __po_hi_create_periodic_task (software_accelero_thread_k, &(period), 5, 512, 0, accelero_thread_job);
  
/*!
 * Store the period time for task magneto_thread
 */
  __po_hi_milliseconds (&(period), 80);
  
/*!
 * \brief Making Periodic Task magneto_thread
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (software_magneto_thread_k) the second is the period defined in the AADL 
 * model. Third is the task priority ( 4), fourth is the stack size ( 512 
 * bytes) and last is the subprogram executed by the task
 */
  __po_hi_create_periodic_task (software_magneto_thread_k, &(period), 4, 512, 0, magneto_thread_job);
  
/*!
 * Store the period time for task gyro_thread
 */
  __po_hi_milliseconds (&(period), 80);
  
/*!
 * \brief Making Periodic Task gyro_thread
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (software_gyro_thread_k) the second is the period defined in the AADL 
 * model. Third is the task priority ( 3), fourth is the stack size ( 512 
 * bytes) and last is the subprogram executed by the task
 */
  __po_hi_create_periodic_task (software_gyro_thread_k, &(period), 3, 512, 0, gyro_thread_job);
  
/*!
 * Store the period time for task attitude_calculation_thread
 */
  __po_hi_milliseconds (&(period), 80);
  
/*!
 * \brief Making Periodic Task attitude_calculation_thread
 *
 * Make a periodic task according to AADL model requirements. The first 
 * parameter is the task identifier defined in deployment.h 
 * (software_attitude_calculation_thread_k) the second is the period defined
 *  in the AADL model. Third is the task priority ( 1), fourth is the stack 
 * size ( 4096 bytes) and last is the subprogram executed by the task
 */
  __po_hi_create_periodic_task (software_attitude_calculation_thread_k, &(period), 1, 4096, 0, attitude_calculation_thread_job);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  
/*!
 * Used to switch the main task to sleep all the time
 */
  __po_hi_wait_for_tasks ();
  
/*!
 * Return Statement
 */
  return (__PO_HI_MAIN_RETURN);
}


