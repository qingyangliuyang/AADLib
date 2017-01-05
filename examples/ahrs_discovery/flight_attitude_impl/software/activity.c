#include <po_hi_gqueue.h>
#include <deployment.h>
#include <po_hi_types.h>
#include <request.h>
#include <types.h>
#include "subprograms.h"
#include <activity.h>
#include <po_hi_task.h>
#include <po_hi_main.h>
#include <po_hi_transport.h>
/*****************************************************/
/*  This file was automatically generated by Ocarina */
/*  Do NOT hand-modify this file, as your            */
/*  changes will be lost when you re-run Ocarina     */
/*****************************************************/
__po_hi_port_t __po_hi_accelero_thread_acc_out_data_x_local_destinations[1] = {attitude_calculation_thread_global_acc_in_data_x};
__po_hi_port_t __po_hi_accelero_thread_acc_out_data_y_local_destinations[1] = {attitude_calculation_thread_global_acc_in_data_y};
__po_hi_port_t __po_hi_accelero_thread_acc_out_data_z_local_destinations[1] = {attitude_calculation_thread_global_acc_in_data_z};
__po_hi_uint8_t __po_hi_accelero_thread_woffsets[__po_hi_accelero_thread_nb_ports];
__po_hi_uint8_t __po_hi_accelero_thread_offsets[__po_hi_accelero_thread_nb_ports];
__po_hi_uint8_t __po_hi_accelero_thread_used_size[__po_hi_accelero_thread_nb_ports];
__po_hi_uint8_t __po_hi_accelero_thread_empties[__po_hi_accelero_thread_nb_ports];
__po_hi_uint8_t __po_hi_accelero_thread_first[__po_hi_accelero_thread_nb_ports];
__po_hi_request_t __po_hi_accelero_thread_recent[__po_hi_accelero_thread_nb_ports];
__po_hi_port_t __po_hi_accelero_thread_queue[0 * sizeof (__po_hi_request_t)];
__po_hi_uint16_t __po_hi_accelero_thread_total_fifo_size = 0;
__po_hi_local_port_t __po_hi_accelero_thread_history[0];
__po_hi_uint8_t __po_hi_accelero_thread_n_dest[__po_hi_accelero_thread_nb_ports] = {0,0,0,1,1,1};
__po_hi_int8_t __po_hi_accelero_thread_fifo_size[__po_hi_accelero_thread_nb_ports] = {__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT};
__po_hi_port_t* __po_hi_accelero_thread_destinations[__po_hi_accelero_thread_nb_ports] = {NULL,NULL,NULL,__po_hi_accelero_thread_acc_out_data_x_local_destinations,__po_hi_accelero_thread_acc_out_data_y_local_destinations,__po_hi_accelero_thread_acc_out_data_z_local_destinations};

/*!
 * \fn void accelero_thread_deliver (__po_hi_request_t* request)
 * \brief Function that delivers requests to the task accelero_thread
 *
 * When the generated application received a request, it calls a main delivery
 *  function that redirects to localfunctions for each task. This function 
 * (accelero_thread_deliver) stores the incoming request for the 
 * taskaccelero_thread
 */
void accelero_thread_deliver 
    (__po_hi_request_t* request)
{

  switch (request->port)
  {
    case accelero_thread_global_acc_in_data_x:
    {
      __po_hi_gqueue_store_in (software_accelero_thread_k, accelero_thread_local_acc_in_data_x, request);

      break;
    }
    case accelero_thread_global_acc_in_data_y:
    {
      __po_hi_gqueue_store_in (software_accelero_thread_k, accelero_thread_local_acc_in_data_y, request);

      break;
    }
    case accelero_thread_global_acc_in_data_z:
    {
      __po_hi_gqueue_store_in (software_accelero_thread_k, accelero_thread_local_acc_in_data_z, request);

      break;
    }
    default:
    {
      break;
    }
  }
}


/*!
 * \fn void* accelero_thread_job (void)
 * \brief Function executed by the task accelero_thread
 *
 * This function is executed as soon as the task  is created. It performs the 
 * following operations:  Receive incoming data,  Execute tasks subprograms,  
 * Send output data.
 */
/*  Periodic task : accelero_thread*/
/*  Get the IN ports values*/
void* accelero_thread_job (void)
{
  __po_hi_request_t static acc_in_data_x_request;
  __po_hi_request_t static acc_in_data_y_request;
  __po_hi_request_t static acc_in_data_z_request;
  ahrs__data_types__float32_type_aadl acc_out_data_x_request_var;
  ahrs__data_types__float32_type_aadl acc_out_data_y_request_var;
  ahrs__data_types__float32_type_aadl acc_out_data_z_request_var;
  __po_hi_request_t acc_out_data_x_request;
  __po_hi_request_t acc_out_data_y_request;
  __po_hi_request_t acc_out_data_z_request;
  __po_hi_int32_t error;

  __po_hi_gqueue_init (software_accelero_thread_k, __po_hi_accelero_thread_nb_ports, __po_hi_accelero_thread_queue, __po_hi_accelero_thread_fifo_size, __po_hi_accelero_thread_first, __po_hi_accelero_thread_offsets, __po_hi_accelero_thread_woffsets, __po_hi_accelero_thread_n_dest, __po_hi_accelero_thread_destinations, __po_hi_accelero_thread_used_size, __po_hi_accelero_thread_history, __po_hi_accelero_thread_recent, __po_hi_accelero_thread_empties, __po_hi_accelero_thread_total_fifo_size);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  __po_hi_compute_next_period (software_accelero_thread_k);
  
/*!
 * Waiting for the first dispatch instant
 */
  __po_hi_wait_for_next_period (software_accelero_thread_k);
  
/*!
 * Task body
 */
  while (1)
  {
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_accelero_thread_k, accelero_thread_local_acc_in_data_x))
    {
          __po_hi_gqueue_get_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_x, &(acc_in_data_x_request));
      __po_hi_gqueue_next_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_accelero_thread_k, accelero_thread_local_acc_in_data_y))
    {
          __po_hi_gqueue_get_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_y, &(acc_in_data_y_request));
      __po_hi_gqueue_next_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_accelero_thread_k, accelero_thread_local_acc_in_data_z))
    {
          __po_hi_gqueue_get_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_z, &(acc_in_data_z_request));
      __po_hi_gqueue_next_value (software_accelero_thread_k, accelero_thread_local_acc_in_data_z);

    }
    /*  Call implementation*/
    ahrs__subprograms__accelero_sub (&(acc_out_data_x_request_var), &(acc_out_data_y_request_var), &(acc_out_data_z_request_var));
    /*  Set the OUT port values*/
    acc_out_data_x_request.vars.accelero_thread_global_acc_out_data_x.accelero_thread_global_acc_out_data_x = acc_out_data_x_request_var;
    acc_out_data_x_request.port = accelero_thread_global_acc_out_data_x;
    __po_hi_gqueue_store_out (software_accelero_thread_k, accelero_thread_local_acc_out_data_x, &(acc_out_data_x_request));
    acc_out_data_y_request.vars.accelero_thread_global_acc_out_data_y.accelero_thread_global_acc_out_data_y = acc_out_data_y_request_var;
    acc_out_data_y_request.port = accelero_thread_global_acc_out_data_y;
    __po_hi_gqueue_store_out (software_accelero_thread_k, accelero_thread_local_acc_out_data_y, &(acc_out_data_y_request));
    acc_out_data_z_request.vars.accelero_thread_global_acc_out_data_z.accelero_thread_global_acc_out_data_z = acc_out_data_z_request_var;
    acc_out_data_z_request.port = accelero_thread_global_acc_out_data_z;
    __po_hi_gqueue_store_out (software_accelero_thread_k, accelero_thread_local_acc_out_data_z, &(acc_out_data_z_request));
    /*  Send the OUT ports*/
    error =
     __po_hi_send_output (software_accelero_thread_k, accelero_thread_global_acc_out_data_x);
    error =
     __po_hi_send_output (software_accelero_thread_k, accelero_thread_global_acc_out_data_y);
    error =
     __po_hi_send_output (software_accelero_thread_k, accelero_thread_global_acc_out_data_z);
    __po_hi_wait_for_next_period (software_accelero_thread_k);
  }
}

__po_hi_port_t __po_hi_magneto_thread_mag_out_data_x_local_destinations[1] = {attitude_calculation_thread_global_mag_in_data_x};
__po_hi_port_t __po_hi_magneto_thread_mag_out_data_y_local_destinations[1] = {attitude_calculation_thread_global_mag_in_data_y};
__po_hi_port_t __po_hi_magneto_thread_mag_out_data_z_local_destinations[1] = {attitude_calculation_thread_global_mag_in_data_z};
__po_hi_uint8_t __po_hi_magneto_thread_woffsets[__po_hi_magneto_thread_nb_ports];
__po_hi_uint8_t __po_hi_magneto_thread_offsets[__po_hi_magneto_thread_nb_ports];
__po_hi_uint8_t __po_hi_magneto_thread_used_size[__po_hi_magneto_thread_nb_ports];
__po_hi_uint8_t __po_hi_magneto_thread_empties[__po_hi_magneto_thread_nb_ports];
__po_hi_uint8_t __po_hi_magneto_thread_first[__po_hi_magneto_thread_nb_ports];
__po_hi_request_t __po_hi_magneto_thread_recent[__po_hi_magneto_thread_nb_ports];
__po_hi_port_t __po_hi_magneto_thread_queue[0 * sizeof (__po_hi_request_t)];
__po_hi_uint16_t __po_hi_magneto_thread_total_fifo_size = 0;
__po_hi_local_port_t __po_hi_magneto_thread_history[0];
__po_hi_uint8_t __po_hi_magneto_thread_n_dest[__po_hi_magneto_thread_nb_ports] = {0,0,0,1,1,1};
__po_hi_int8_t __po_hi_magneto_thread_fifo_size[__po_hi_magneto_thread_nb_ports] = {__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT};
__po_hi_port_t* __po_hi_magneto_thread_destinations[__po_hi_magneto_thread_nb_ports] = {NULL,NULL,NULL,__po_hi_magneto_thread_mag_out_data_x_local_destinations,__po_hi_magneto_thread_mag_out_data_y_local_destinations,__po_hi_magneto_thread_mag_out_data_z_local_destinations};

/*!
 * \fn void magneto_thread_deliver (__po_hi_request_t* request)
 * \brief Function that delivers requests to the task magneto_thread
 *
 * When the generated application received a request, it calls a main delivery
 *  function that redirects to localfunctions for each task. This function 
 * (magneto_thread_deliver) stores the incoming request for the 
 * taskmagneto_thread
 */
void magneto_thread_deliver 
    (__po_hi_request_t* request)
{

  switch (request->port)
  {
    case magneto_thread_global_mag_in_data_x:
    {
      __po_hi_gqueue_store_in (software_magneto_thread_k, magneto_thread_local_mag_in_data_x, request);

      break;
    }
    case magneto_thread_global_mag_in_data_y:
    {
      __po_hi_gqueue_store_in (software_magneto_thread_k, magneto_thread_local_mag_in_data_y, request);

      break;
    }
    case magneto_thread_global_mag_in_data_z:
    {
      __po_hi_gqueue_store_in (software_magneto_thread_k, magneto_thread_local_mag_in_data_z, request);

      break;
    }
    default:
    {
      break;
    }
  }
}


/*!
 * \fn void* magneto_thread_job (void)
 * \brief Function executed by the task magneto_thread
 *
 * This function is executed as soon as the task  is created. It performs the 
 * following operations:  Receive incoming data,  Execute tasks subprograms,  
 * Send output data.
 */
/*  Periodic task : magneto_thread*/
/*  Get the IN ports values*/
void* magneto_thread_job (void)
{
  __po_hi_request_t static mag_in_data_x_request;
  __po_hi_request_t static mag_in_data_y_request;
  __po_hi_request_t static mag_in_data_z_request;
  ahrs__data_types__float32_type_aadl mag_out_data_x_request_var;
  ahrs__data_types__float32_type_aadl mag_out_data_y_request_var;
  ahrs__data_types__float32_type_aadl mag_out_data_z_request_var;
  __po_hi_request_t mag_out_data_x_request;
  __po_hi_request_t mag_out_data_y_request;
  __po_hi_request_t mag_out_data_z_request;
  __po_hi_int32_t error;

  __po_hi_gqueue_init (software_magneto_thread_k, __po_hi_magneto_thread_nb_ports, __po_hi_magneto_thread_queue, __po_hi_magneto_thread_fifo_size, __po_hi_magneto_thread_first, __po_hi_magneto_thread_offsets, __po_hi_magneto_thread_woffsets, __po_hi_magneto_thread_n_dest, __po_hi_magneto_thread_destinations, __po_hi_magneto_thread_used_size, __po_hi_magneto_thread_history, __po_hi_magneto_thread_recent, __po_hi_magneto_thread_empties, __po_hi_magneto_thread_total_fifo_size);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  __po_hi_compute_next_period (software_magneto_thread_k);
  
/*!
 * Waiting for the first dispatch instant
 */
  __po_hi_wait_for_next_period (software_magneto_thread_k);
  
/*!
 * Task body
 */
  while (1)
  {
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_magneto_thread_k, magneto_thread_local_mag_in_data_x))
    {
          __po_hi_gqueue_get_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_x, &(mag_in_data_x_request));
      __po_hi_gqueue_next_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_magneto_thread_k, magneto_thread_local_mag_in_data_y))
    {
          __po_hi_gqueue_get_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_y, &(mag_in_data_y_request));
      __po_hi_gqueue_next_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_magneto_thread_k, magneto_thread_local_mag_in_data_z))
    {
          __po_hi_gqueue_get_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_z, &(mag_in_data_z_request));
      __po_hi_gqueue_next_value (software_magneto_thread_k, magneto_thread_local_mag_in_data_z);

    }
    /*  Call implementation*/
    ahrs__subprograms__magneto_sub (&(mag_out_data_x_request_var), &(mag_out_data_y_request_var), &(mag_out_data_z_request_var));
    /*  Set the OUT port values*/
    mag_out_data_x_request.vars.magneto_thread_global_mag_out_data_x.magneto_thread_global_mag_out_data_x = mag_out_data_x_request_var;
    mag_out_data_x_request.port = magneto_thread_global_mag_out_data_x;
    __po_hi_gqueue_store_out (software_magneto_thread_k, magneto_thread_local_mag_out_data_x, &(mag_out_data_x_request));
    mag_out_data_y_request.vars.magneto_thread_global_mag_out_data_y.magneto_thread_global_mag_out_data_y = mag_out_data_y_request_var;
    mag_out_data_y_request.port = magneto_thread_global_mag_out_data_y;
    __po_hi_gqueue_store_out (software_magneto_thread_k, magneto_thread_local_mag_out_data_y, &(mag_out_data_y_request));
    mag_out_data_z_request.vars.magneto_thread_global_mag_out_data_z.magneto_thread_global_mag_out_data_z = mag_out_data_z_request_var;
    mag_out_data_z_request.port = magneto_thread_global_mag_out_data_z;
    __po_hi_gqueue_store_out (software_magneto_thread_k, magneto_thread_local_mag_out_data_z, &(mag_out_data_z_request));
    /*  Send the OUT ports*/
    error =
     __po_hi_send_output (software_magneto_thread_k, magneto_thread_global_mag_out_data_x);
    error =
     __po_hi_send_output (software_magneto_thread_k, magneto_thread_global_mag_out_data_y);
    error =
     __po_hi_send_output (software_magneto_thread_k, magneto_thread_global_mag_out_data_z);
    __po_hi_wait_for_next_period (software_magneto_thread_k);
  }
}

__po_hi_port_t __po_hi_gyro_thread_gyro_out_data_x_local_destinations[1] = {attitude_calculation_thread_global_gyro_in_data_x};
__po_hi_port_t __po_hi_gyro_thread_gyro_out_data_y_local_destinations[1] = {attitude_calculation_thread_global_gyro_in_data_y};
__po_hi_port_t __po_hi_gyro_thread_gyro_out_data_z_local_destinations[1] = {attitude_calculation_thread_global_gyro_in_data_z};
__po_hi_uint8_t __po_hi_gyro_thread_woffsets[__po_hi_gyro_thread_nb_ports];
__po_hi_uint8_t __po_hi_gyro_thread_offsets[__po_hi_gyro_thread_nb_ports];
__po_hi_uint8_t __po_hi_gyro_thread_used_size[__po_hi_gyro_thread_nb_ports];
__po_hi_uint8_t __po_hi_gyro_thread_empties[__po_hi_gyro_thread_nb_ports];
__po_hi_uint8_t __po_hi_gyro_thread_first[__po_hi_gyro_thread_nb_ports];
__po_hi_request_t __po_hi_gyro_thread_recent[__po_hi_gyro_thread_nb_ports];
__po_hi_port_t __po_hi_gyro_thread_queue[0 * sizeof (__po_hi_request_t)];
__po_hi_uint16_t __po_hi_gyro_thread_total_fifo_size = 0;
__po_hi_local_port_t __po_hi_gyro_thread_history[0];
__po_hi_uint8_t __po_hi_gyro_thread_n_dest[__po_hi_gyro_thread_nb_ports] = {0,0,0,1,1,1};
__po_hi_int8_t __po_hi_gyro_thread_fifo_size[__po_hi_gyro_thread_nb_ports] = {__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_INDATA,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT,__PO_HI_GQUEUE_FIFO_OUT};
__po_hi_port_t* __po_hi_gyro_thread_destinations[__po_hi_gyro_thread_nb_ports] = {NULL,NULL,NULL,__po_hi_gyro_thread_gyro_out_data_x_local_destinations,__po_hi_gyro_thread_gyro_out_data_y_local_destinations,__po_hi_gyro_thread_gyro_out_data_z_local_destinations};

/*!
 * \fn void gyro_thread_deliver (__po_hi_request_t* request)
 * \brief Function that delivers requests to the task gyro_thread
 *
 * When the generated application received a request, it calls a main delivery
 *  function that redirects to localfunctions for each task. This function 
 * (gyro_thread_deliver) stores the incoming request for the taskgyro_thread
 */
void gyro_thread_deliver 
    (__po_hi_request_t* request)
{

  switch (request->port)
  {
    case gyro_thread_global_gyro_in_data_x:
    {
      __po_hi_gqueue_store_in (software_gyro_thread_k, gyro_thread_local_gyro_in_data_x, request);

      break;
    }
    case gyro_thread_global_gyro_in_data_y:
    {
      __po_hi_gqueue_store_in (software_gyro_thread_k, gyro_thread_local_gyro_in_data_y, request);

      break;
    }
    case gyro_thread_global_gyro_in_data_z:
    {
      __po_hi_gqueue_store_in (software_gyro_thread_k, gyro_thread_local_gyro_in_data_z, request);

      break;
    }
    default:
    {
      break;
    }
  }
}


/*!
 * \fn void* gyro_thread_job (void)
 * \brief Function executed by the task gyro_thread
 *
 * This function is executed as soon as the task  is created. It performs the 
 * following operations:  Receive incoming data,  Execute tasks subprograms,  
 * Send output data.
 */
/*  Periodic task : gyro_thread*/
/*  Get the IN ports values*/
void* gyro_thread_job (void)
{
  __po_hi_request_t static gyro_in_data_x_request;
  __po_hi_request_t static gyro_in_data_y_request;
  __po_hi_request_t static gyro_in_data_z_request;
  ahrs__data_types__float32_type_aadl gyro_out_data_x_request_var;
  ahrs__data_types__float32_type_aadl gyro_out_data_y_request_var;
  ahrs__data_types__float32_type_aadl gyro_out_data_z_request_var;
  __po_hi_request_t gyro_out_data_x_request;
  __po_hi_request_t gyro_out_data_y_request;
  __po_hi_request_t gyro_out_data_z_request;
  __po_hi_int32_t error;

  __po_hi_gqueue_init (software_gyro_thread_k, __po_hi_gyro_thread_nb_ports, __po_hi_gyro_thread_queue, __po_hi_gyro_thread_fifo_size, __po_hi_gyro_thread_first, __po_hi_gyro_thread_offsets, __po_hi_gyro_thread_woffsets, __po_hi_gyro_thread_n_dest, __po_hi_gyro_thread_destinations, __po_hi_gyro_thread_used_size, __po_hi_gyro_thread_history, __po_hi_gyro_thread_recent, __po_hi_gyro_thread_empties, __po_hi_gyro_thread_total_fifo_size);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  __po_hi_compute_next_period (software_gyro_thread_k);
  
/*!
 * Waiting for the first dispatch instant
 */
  __po_hi_wait_for_next_period (software_gyro_thread_k);
  
/*!
 * Task body
 */
  while (1)
  {
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_gyro_thread_k, gyro_thread_local_gyro_in_data_x))
    {
          __po_hi_gqueue_get_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_x, &(gyro_in_data_x_request));
      __po_hi_gqueue_next_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_gyro_thread_k, gyro_thread_local_gyro_in_data_y))
    {
          __po_hi_gqueue_get_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_y, &(gyro_in_data_y_request));
      __po_hi_gqueue_next_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_gyro_thread_k, gyro_thread_local_gyro_in_data_z))
    {
          __po_hi_gqueue_get_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_z, &(gyro_in_data_z_request));
      __po_hi_gqueue_next_value (software_gyro_thread_k, gyro_thread_local_gyro_in_data_z);

    }
    /*  Call implementation*/
    ahrs__subprograms__gyro_sub (&(gyro_out_data_x_request_var), &(gyro_out_data_y_request_var), &(gyro_out_data_z_request_var));
    /*  Set the OUT port values*/
    gyro_out_data_x_request.vars.gyro_thread_global_gyro_out_data_x.gyro_thread_global_gyro_out_data_x = gyro_out_data_x_request_var;
    gyro_out_data_x_request.port = gyro_thread_global_gyro_out_data_x;
    __po_hi_gqueue_store_out (software_gyro_thread_k, gyro_thread_local_gyro_out_data_x, &(gyro_out_data_x_request));
    gyro_out_data_y_request.vars.gyro_thread_global_gyro_out_data_y.gyro_thread_global_gyro_out_data_y = gyro_out_data_y_request_var;
    gyro_out_data_y_request.port = gyro_thread_global_gyro_out_data_y;
    __po_hi_gqueue_store_out (software_gyro_thread_k, gyro_thread_local_gyro_out_data_y, &(gyro_out_data_y_request));
    gyro_out_data_z_request.vars.gyro_thread_global_gyro_out_data_z.gyro_thread_global_gyro_out_data_z = gyro_out_data_z_request_var;
    gyro_out_data_z_request.port = gyro_thread_global_gyro_out_data_z;
    __po_hi_gqueue_store_out (software_gyro_thread_k, gyro_thread_local_gyro_out_data_z, &(gyro_out_data_z_request));
    /*  Send the OUT ports*/
    error =
     __po_hi_send_output (software_gyro_thread_k, gyro_thread_global_gyro_out_data_x);
    error =
     __po_hi_send_output (software_gyro_thread_k, gyro_thread_global_gyro_out_data_y);
    error =
     __po_hi_send_output (software_gyro_thread_k, gyro_thread_global_gyro_out_data_z);
    __po_hi_wait_for_next_period (software_gyro_thread_k);
  }
}

__po_hi_uint8_t __po_hi_attitude_calculation_thread_woffsets[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_uint8_t __po_hi_attitude_calculation_thread_offsets[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_uint8_t __po_hi_attitude_calculation_thread_used_size[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_uint8_t __po_hi_attitude_calculation_thread_empties[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_uint8_t __po_hi_attitude_calculation_thread_first[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_request_t __po_hi_attitude_calculation_thread_recent[__po_hi_attitude_calculation_thread_nb_ports];
__po_hi_port_t __po_hi_attitude_calculation_thread_queue[144 * sizeof (__po_hi_request_t)];
__po_hi_uint16_t __po_hi_attitude_calculation_thread_total_fifo_size = 144;
__po_hi_local_port_t __po_hi_attitude_calculation_thread_history[144];
__po_hi_uint8_t __po_hi_attitude_calculation_thread_n_dest[__po_hi_attitude_calculation_thread_nb_ports] = {0,0,0,0,0,0,0,0,0};
__po_hi_int8_t __po_hi_attitude_calculation_thread_fifo_size[__po_hi_attitude_calculation_thread_nb_ports] = {16,16,16,16,16,16,16,16,16};
__po_hi_port_t* __po_hi_attitude_calculation_thread_destinations[__po_hi_attitude_calculation_thread_nb_ports] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

/*!
 * \fn void attitude_calculation_thread_deliver (__po_hi_request_t* request)
 * \brief Function that delivers requests to the task attitude_calculation_thread
 *
 * When the generated application received a request, it calls a main delivery
 *  function that redirects to localfunctions for each task. This function 
 * (attitude_calculation_thread_deliver) stores the incoming request for the 
 * taskattitude_calculation_thread
 */
void attitude_calculation_thread_deliver 
    (__po_hi_request_t* request)
{

  switch (request->port)
  {
    case attitude_calculation_thread_global_acc_in_data_x:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_x, request);

      break;
    }
    case attitude_calculation_thread_global_acc_in_data_y:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_y, request);

      break;
    }
    case attitude_calculation_thread_global_acc_in_data_z:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_z, request);

      break;
    }
    case attitude_calculation_thread_global_mag_in_data_x:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_x, request);

      break;
    }
    case attitude_calculation_thread_global_mag_in_data_y:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_y, request);

      break;
    }
    case attitude_calculation_thread_global_mag_in_data_z:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_z, request);

      break;
    }
    case attitude_calculation_thread_global_gyro_in_data_x:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_x, request);

      break;
    }
    case attitude_calculation_thread_global_gyro_in_data_y:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_y, request);

      break;
    }
    case attitude_calculation_thread_global_gyro_in_data_z:
    {
      __po_hi_gqueue_store_in (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_z, request);

      break;
    }
    default:
    {
      break;
    }
  }
}


/*!
 * \fn void* attitude_calculation_thread_job (void)
 * \brief Function executed by the task attitude_calculation_thread
 *
 * This function is executed as soon as the task  is created. It performs the 
 * following operations:  Receive incoming data,  Execute tasks subprograms,  
 * Send output data.
 */
/*  Periodic task : attitude_calculation_thread*/
/*  Get the IN ports values*/
void* attitude_calculation_thread_job (void)
{
  __po_hi_request_t static acc_in_data_x_request;
  __po_hi_request_t static acc_in_data_y_request;
  __po_hi_request_t static acc_in_data_z_request;
  __po_hi_request_t static mag_in_data_x_request;
  __po_hi_request_t static mag_in_data_y_request;
  __po_hi_request_t static mag_in_data_z_request;
  __po_hi_request_t static gyro_in_data_x_request;
  __po_hi_request_t static gyro_in_data_y_request;
  __po_hi_request_t static gyro_in_data_z_request;

  __po_hi_gqueue_init (software_attitude_calculation_thread_k, __po_hi_attitude_calculation_thread_nb_ports, __po_hi_attitude_calculation_thread_queue, __po_hi_attitude_calculation_thread_fifo_size, __po_hi_attitude_calculation_thread_first, __po_hi_attitude_calculation_thread_offsets, __po_hi_attitude_calculation_thread_woffsets, __po_hi_attitude_calculation_thread_n_dest, __po_hi_attitude_calculation_thread_destinations, __po_hi_attitude_calculation_thread_used_size, __po_hi_attitude_calculation_thread_history, __po_hi_attitude_calculation_thread_recent, __po_hi_attitude_calculation_thread_empties, __po_hi_attitude_calculation_thread_total_fifo_size);
  
/*!
 * Waiting for other tasks initialization
 */
  __po_hi_wait_initialization ();
  __po_hi_compute_next_period (software_attitude_calculation_thread_k);
  
/*!
 * Waiting for the first dispatch instant
 */
  __po_hi_wait_for_next_period (software_attitude_calculation_thread_k);
  
/*!
 * Task body
 */
  while (1)
  {
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_x))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_x, &(acc_in_data_x_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_y))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_y, &(acc_in_data_y_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_z))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_z, &(acc_in_data_z_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_acc_in_data_z);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_x))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_x, &(mag_in_data_x_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_y))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_y, &(mag_in_data_y_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_z))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_z, &(mag_in_data_z_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_mag_in_data_z);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_x))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_x, &(gyro_in_data_x_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_x);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_y))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_y, &(gyro_in_data_y_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_y);

    }
    /* :: Yes if commentary :: */if (__po_hi_gqueue_get_count (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_z))
    {
          __po_hi_gqueue_get_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_z, &(gyro_in_data_z_request));
      __po_hi_gqueue_next_value (software_attitude_calculation_thread_k, attitude_calculation_thread_local_gyro_in_data_z);

    }
    /*  Call implementation*/
    ahrs__subprograms__attitude_sub (acc_in_data_x_request.vars.attitude_calculation_thread_global_acc_in_data_x.attitude_calculation_thread_global_acc_in_data_x, mag_in_data_x_request.vars.attitude_calculation_thread_global_mag_in_data_x.attitude_calculation_thread_global_mag_in_data_x, gyro_in_data_x_request.vars.attitude_calculation_thread_global_gyro_in_data_x.attitude_calculation_thread_global_gyro_in_data_x, acc_in_data_y_request.vars.attitude_calculation_thread_global_acc_in_data_y.attitude_calculation_thread_global_acc_in_data_y, mag_in_data_y_request.vars.attitude_calculation_thread_global_mag_in_data_y.attitude_calculation_thread_global_mag_in_data_y, gyro_in_data_y_request.vars.attitude_calculation_thread_global_gyro_in_data_y.attitude_calculation_thread_global_gyro_in_data_y, acc_in_data_z_request.vars.attitude_calculation_thread_global_acc_in_data_z.attitude_calculation_thread_global_acc_in_data_z, mag_in_data_z_request.vars.attitude_calculation_thread_global_mag_in_data_z.attitude_calculation_thread_global_mag_in_data_z, gyro_in_data_z_request.vars.attitude_calculation_thread_global_gyro_in_data_z.attitude_calculation_thread_global_gyro_in_data_z);
    __po_hi_wait_for_next_period (software_attitude_calculation_thread_k);
  }
}


/*!
 * \fn void __po_hi_main_deliver (__po_hi_request_t* request)
 * \brief Used to deliver request to the appropriate ports
 *
 * This function takes a request as argument (\arg request) and calls the 
 * appropriate function for its delivery.To specify which function should be 
 * called, it extracts the receiver entity using the destination port.
 */
void __po_hi_main_deliver 
    (__po_hi_request_t* request)
{
  __po_hi_entity_t entity;

  entity = __po_hi_get_entity_from_global_port (request->port);
  switch (entity)
  {
    case software_accelero_thread_k_entity:
    {
      accelero_thread_deliver (request);

      break;
    }
    case software_magneto_thread_k_entity:
    {
      magneto_thread_deliver (request);

      break;
    }
    case software_gyro_thread_k_entity:
    {
      gyro_thread_deliver (request);

      break;
    }
    case software_attitude_calculation_thread_k_entity:
    {
      attitude_calculation_thread_deliver (request);

      break;
    }
    default:
    {
      break;
    }
  }
}

