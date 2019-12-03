/**
 * BSD 3-Clause License
 *
 * @copyright (c) 2019, Umang Rastogi Naman Gupta
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file 	object_detection.h
 * @author 	Umang Rastogi 	- Driver
 * @author 	Naman Gupta 	- Navigator
 * @brief 	Library header file to implement object detection
 * @detail 	Deploys template matching to detect object in the bot's world
 */

#ifndef INCLUDE_OBJECT_DETECTION_OBJECT_DETECTION_H_
#define INCLUDE_OBJECT_DETECTION_OBJECT_DETECTION_H_

#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/image_encodings.h"
#include "image_transport/image_transport.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class ObjectDectection {
 private:
  /// Define the main access point to communications with the ROS system
  ros::NodeHandle nh;
  /// Define a publisher object to publish velocities for the robot
  ros::Publisher publishLocation;
  /// Define a subscriber object to data of the laser sensor
  ros::Subscriber subscibeImages;
  /// Declare publishing rate
  float publishingRate;
  /// Store copy of the ros image converted into cv image
  cv::Mat convertedImage;
  /// Define object coordinates
  cv::Rect objectLocation;

 public:
	/**
  * @brief Constructor for object detection class
  * @param none
  * @return a constructor has no return
  */
  ObjectDectection();

  /**
  * @brief Destructor for object detection class
  * @param none
  * @return a destrcutor has no return
  */
  ~ObjectDectection();

  /**
  * @brief Callback function for image data
  * @param image data from camera node
  * @return void
  * @detail Convert ROS image message to CV image
  */
  void convertImage(const sensor_msgs::Image::ConstPtr& imageData);

  /**
  * @brief Method to implement template matching
  * @param none
  * @return void
  */
  bool templateMatching(cv::Mat cvImage);

  /**
  * @brief Method to get location of object in the turtlebot world
  * @param none
  * @return void
  */
  cv::Rect getObjectLocation();
};

#endif  // INCLUDE_OBJECT_DETECTION_OBJECT_DETECTION_H_