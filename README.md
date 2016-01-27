ft_ros_publisher
===============

Force-Torque ROS publisher for the WALK-MAN robot.
It is a GYM module that publishes each 100ms the wrench stamped msg from WALK-MAN F-T sensors (Left arm F-T, Right arm F-T-, Left leg F-T and Right leg F-T).

How to launch
=============

```
ft_ros_publisher --from <CONFIG.ini>
```

where <config.ini> is your installed GYM configuration file in ft_publisher/app/conf/ 
By default ft_ros_publisher_initial_config.ini is used.
