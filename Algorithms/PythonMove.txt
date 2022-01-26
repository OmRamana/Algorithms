#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class ForceMapper(): 
    def __init__(self):
        self.r = rospy.Rate(250) # 250hz
        self.linear_speed = 0.8
        self.angular_speed = 0.8
        self.move_cmd = Twist()
        self.sub = rospy.Subscriber('/scan', LaserScan, self.callBack)
        #self.pub_obs = rospy.Publisher('obstacle', String, queue_size=10)
        self.cmd_pub = rospy.Publisher('cmd_vel_mux/input/navi', Twist, queue_size=1)
        self.start()

    def forward(self):
        self.move_cmd.linear.x = self.linear_speed

    def turn(self):
        self.move_cmd.angular.z = self.angular_speed

    def stop(self):
        self.move_cmd.linear.x = 0

    def default(self, msg):
        size = len(msg.ranges)
        right = msg.ranges[0]
        front = msg.ranges[size/2]
        left = msg.ranges[size-1]
        print("l,f,r: ", left, front, right)


    def behavior1(self, msg):
        size = len(msg.ranges)
        right = msg.ranges[0]
        front = msg.ranges[size/2]
        left = msg.ranges[size-1]
        print("l,f,r: ", left, front, right)
        if (front > 2.5):
            self.forward()
        else:
            self.stop()

    def behavior2(self, msg):
        size = len(msg.ranges)
        right = msg.ranges[0]
        front = msg.ranges[size/2]
        left = msg.ranges[size-1]
        print("l,f,r: ", left, front, right)
        self.turn()
        
    def start(self):
        while not rospy.is_shutdown():
            #self.pub_obs.publish(self.obstacle)
            self.cmd_pub.publish(self.move_cmd)
            self.r.sleep()

    def callBack(self, msg):
        #self.default(msg)
        self.behavior1(msg)
        #self.behavior2(msg)
        pass 


def main():
    rospy.init_node('ForceMapper')
    try:
        force = ForceMapper()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()