#include <yarp/os/all.h>
#include <GYM/control_module.hpp>
#include <cstdlib>

#include "ft_ros_publisher_module.hpp"

// default module period
#define MODULE_PERIOD 1000 //[millisec]

int main(int argc, char* argv[])
{
    // initialize ros node
    ros::init(argc, argv, "ft_ros_publisher");
    // yarp network declaration and check
    yarp::os::Network yarp;
    if(!yarp.checkNetwork()){
        std::cerr <<"yarpserver not running - run yarpserver"<< std::endl;
        exit(EXIT_FAILURE);
    }
    // yarp network initialization
    yarp.init();

    // create rf
    yarp::os::ResourceFinder rf;
    rf.setVerbose(true);
    // set ft_ros_publisher_initial_config.ini as default
    // to specify another config file, run with this arg: --from your_config_file.ini 
    rf.setDefaultConfigFile( "ft_ros_publisher_initial_config.ini" ); 
    rf.setDefaultContext( "ft_ros_publisher" );  
    rf.configure(argc, argv);
    // create my module
    ft_ros_publisher_module ft_ros_publisher_mod = ft_ros_publisher_module( argc, argv, "ft_ros_publisher", MODULE_PERIOD, rf );
    
    // run the module
    ft_ros_publisher_mod.runModule( rf );
    
    // yarp network deinitialization
    yarp.fini();
    
    exit(EXIT_SUCCESS);
}
