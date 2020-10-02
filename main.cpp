#include <ros/ros.h>
#include "Generated/API.h"
#include "Generated/BaseLayer.h"


int main(int argc, char **argv) {
  // initialize ros
  ros::init(argc, argv, "hello");
  ros::NodeHandle nh;            
  ros::Rate rate(1);             

  // initialize rtcop
  RTCOP::Framework::Instance->Initialize();

	// instantiate class Hello
	baselayer::Hello* hello = RTCOP::copnew<baselayer::Hello>();

  ROS_INFO_STREAM("Hello World!");
  rate.sleep();                   

	// activate EnglishLayer
	RTCOP::activate(RTCOP::Generated::LayerID::English);
	hello->Print();

	// activate JapaneseLayer
	RTCOP::deactivate(RTCOP::Generated::LayerID::English);
	RTCOP::activate(RTCOP::Generated::LayerID::Japanese);
	hello->Print();

	// Helloのdelete
	delete hello;

	// RTCOPの終了処理
	RTCOP::Framework::Instance->Finalize();
}