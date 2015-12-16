#ifndef ft_ros_publisher_THREAD_H_
#define ft_ros_publisher_THREAD_H_

#include <GYM/control_thread.hpp>

#include <geometry_msgs/WrenchStamped.h>
#include <ros/ros.h>

/**
 * @brief ft_ros_publisher control thread
 * 
 **/
class ft_ros_publisher_thread : public control_thread
{
private:   
    
        yarp::sig::Vector ft_reading;
        ros::NodeHandle ft_node;
        
        std::map<std::string, ros::Publisher> ft_reference_to_publisher;
        std::map< ros::Publisher, geometry_msgs::WrenchStamped> ft_publisher_to_msg;
        
        /**
         * @brief fill the ROS message
         * 
         * @return void
         */
        void fill_ros_msg();
        void publish_ros_msg();
public:
    
    /**
     * @brief constructor
     * 
     * @param module_prefix the prefix of the module
     * @param rf resource finderce
     * @param ph param helper
     */
     ft_ros_publisher_thread( std::string module_prefix, yarp::os::ResourceFinder rf, std::shared_ptr<paramHelp::ParamHelperServer> ph );
    
    
    /**
     * @brief ft_ros_publisher control thread initialization
     * 
     * @return true on succes, false otherwise
     */
    virtual bool custom_init();
    
    /**
     * @brief ft_ros_publisher control thread main loop
     * 
     */
    virtual void run();
    
};

#endif
