// -*- C++ -*-
/*!
 * @file  RTMAdapter.h
 * @brief RTM / C language Adapter
 * @date  $Date$
 *
 * $Id$
 */

#ifndef RTMADAPTER_H
#define RTMADAPTER_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

int do_nothing_callback(int id);

using namespace RTC;

/*!
 * @class RTMAdapter
 * @brief RTM / C language Adapter
 *
 */
class RTMAdapter
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  RTMAdapter(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~RTMAdapter();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>
	 
  // <rtc-template block="private_operation">
  
  // </rtc-template>
	 int(*on_finalize_callback)(int);
	 int(*on_startup_callback)(int);
	 int(*on_shutdown_callback)(int);
	 int(*on_activated_callback)(int);
	 int(*on_deactivated_callback)(int);
	 int(*on_execute_callback)(int);
	 int(*on_aborting_callback)(int);
	 int(*on_error_callback)(int);
	 int(*on_reset_callback)(int);
	 int(*on_state_update_callback)(int);
	 int(*on_rate_changed_callback)(int);

	 void init_callbacks() {
		 on_finalize_callback = do_nothing_callback;
		 on_startup_callback = do_nothing_callback;
		 on_shutdown_callback = do_nothing_callback;
		 on_activated_callback = do_nothing_callback;
		 on_deactivated_callback = do_nothing_callback;
		 on_execute_callback = do_nothing_callback;
		 on_aborting_callback = do_nothing_callback;
		 on_error_callback = do_nothing_callback;
		 on_reset_callback = do_nothing_callback;
		 on_state_update_callback = do_nothing_callback;
		 on_rate_changed_callback = do_nothing_callback;
	 }

 public:
	 void onFinalize_listen(int(*callback)(int)) {
		 on_finalize_callback = callback;
	 }

	 void onStartUp_listen(int(*callback)(int)) {
		 on_startup_callback = callback;
	 }

	 void onShutdown_listen(int(*callback)(int)) {
		 on_shutdown_callback = callback;
	 }

	 void onActivated_listen(int(*callback)(int)) {
		 on_activated_callback = callback;
	 }

	 void onDeactivated_listen(int(*callback)(int)) {
		 on_deactivated_callback = callback;
	 }

	 void onExecute_listen(int(*callback)(int)) {
		 on_execute_callback = callback;
	 }

	 void onAborting_listen(int(*callback)(int)) {
		 on_aborting_callback = callback;
	 }

	 void onError_listen(int(*callback)(int)) {
		 on_error_callback = callback;
	 }

	 void onReset_listen(int(*callback)(int)) {
		 on_reset_callback = callback;
	 }

	 void onStateUpdate_listen(int(*callback)(int)) {
		 on_state_update_callback = callback;
	 }

	 void onRateChanged_listen(int(*callback)(int)) {
		 on_rate_changed_callback = callback;
	 }
};


extern "C"
{
  DLL_EXPORT void RTMAdapterInit(RTC::Manager* manager);
};

#endif // RTMADAPTER_H
