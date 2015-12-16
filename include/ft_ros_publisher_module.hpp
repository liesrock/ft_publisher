#ifndef ft_ros_publisher_MODULE_HPP_
#define ft_ros_publisher_MODULE_HPP_

#include <GYM/control_module.hpp>

#include "ft_ros_publisher_thread.h"
#include "ft_ros_publisher_constants.h"

/**
 * @brief ft_ros_publisher module derived from control_module
 * 
 * @author 
 */
class ft_ros_publisher_module : public control_module<ft_ros_publisher_thread> {
public:
    
    /**
     * @brief constructor: do nothing but construct the superclass
     * 
     */
    ft_ros_publisher_module(    int argc, 
                               char* argv[],
                               std::string module_prefix, 
                               int module_period, 
                               yarp::os::ResourceFinder rf ) : control_module<ft_ros_publisher_thread>(  argc, 
                                                                                            		argv, 
                                                                                            		module_prefix, 
                                                                                            		module_period,
                                                                                            		rf )
    {
    }
    
    /**
     * @brief overriden function to specify the custom params for the param helper
     * 
     * @return a vector of the custom params for the param helper
     */
    virtual std::vector< paramHelp::ParamProxyInterface* > custom_get_ph_parameters() 
    {
	// TODO: function skeleton
        std::vector<paramHelp::ParamProxyInterface *> custom_params;
        return custom_params;
    }
    
    
};

#endif
