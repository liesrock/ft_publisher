#include <yarp/os/all.h>

#include "ft_ros_publisher_thread.h"
#include "ft_ros_publisher_constants.h"

ft_ros_publisher_thread::ft_ros_publisher_thread(   std::string module_prefix, 
                                                    yarp::os::ResourceFinder rf, 
                                                    std::shared_ptr< paramHelp::ParamHelperServer > ph) :
    control_thread( module_prefix, rf, ph )
{
    // initialize the map from ft_ref to the related publisher
    ft_reference_to_publisher["r_leg_ft"] = ft_node.advertise<geometry_msgs::WrenchStamped>( "ft/r_leg_ft", 100 );
    ft_reference_to_publisher["l_leg_ft"] = ft_node.advertise<geometry_msgs::WrenchStamped>( "ft/l_leg_ft", 100 );
    ft_reference_to_publisher["r_arm_ft"] = ft_node.advertise<geometry_msgs::WrenchStamped>( "ft/r_arm_ft", 100 );
    ft_reference_to_publisher["l_arm_ft"] = ft_node.advertise<geometry_msgs::WrenchStamped>( "ft/l_arm_ft", 100 );

    // initialize the map from the publisher to the related msg
    for(auto ft : ft_reference_to_publisher) {
        geometry_msgs::WrenchStamped ft_msg;
        ft_msg.header.frame_id = std::string(ft.first);
        ft_publisher_to_msg[ft.second] = ft_msg;
    }

}

bool ft_ros_publisher_thread::custom_init()
{
    // TODO: skeleton function   
    return true;
}

void ft_ros_publisher_thread::fill_ros_msg()
{
    for(auto ft : ft_reference_to_publisher) {
        robot.senseftSensor(ft.first, ft_reading);
        ft_publisher_to_msg.at(ft.second).wrench.force.x = ft_reading[0];
        ft_publisher_to_msg.at(ft.second).wrench.force.y = ft_reading[1];
        ft_publisher_to_msg.at(ft.second).wrench.force.z = ft_reading[2];
        ft_publisher_to_msg.at(ft.second).wrench.torque.x = ft_reading[3];
        ft_publisher_to_msg.at(ft.second).wrench.torque.y = ft_reading[4];
        ft_publisher_to_msg.at(ft.second).wrench.torque.z = ft_reading[5];
    }

}

void ft_ros_publisher_thread::publish_ros_msg()
{
    ros::Time t = ros::Time::now();
    for(auto ft : ft_publisher_to_msg) {
        ft.second.header.stamp = t;
        ft.first.publish(ft.second);
    }
}



void ft_ros_publisher_thread::run()
{  
    fill_ros_msg();
    publish_ros_msg();
}    
