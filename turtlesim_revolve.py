# To revolve the turtle in a circular manner with turtlesim and ROS.
#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from math import pi
def rotate():
    #starting the node
    rospy.init_node('move_turtle',anonymous=True)
    velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    vel_msg = Twist()

    print("let the rotation begin")
    speed=25 #degrees/sec
    angle=360
    
    angular_speed=speed*2*pi/360 #radians/sec
    radian_angle=angle*2*pi/360

    vel_msg.linear.x=1
    vel_msg.linear.y=0
    vel_msg.linear.z=0
    vel_msg.angular.x=0
    vel_msg.angular.y=0

    vel_msg.angular.z=abs(angular_speed)
    t0=rospy.Time.now().to_sec()
    current_angle=0

    while(current_angle<radian_angle):
        velocity_publisher.publish(vel_msg)
        t1 = rospy.Time.now().to_sec()
        current_angle = angular_speed*(t1-t0)
    vel_msg.angular.z = 0
    vel_msg.linear.x=0
    velocity_publisher.publish(vel_msg)
    rospy.spin()

if __name__ == '__main__':
    try:
        #Testing our function
        rotate()
    except rospy.ROSInterruptException: pass
