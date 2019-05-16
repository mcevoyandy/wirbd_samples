#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

if __name__ == '__main__':

    rospy.init_node('servo_cmd_pub')
    servo_cmd_pub = rospy.Publisher('servo_cmd', Int32, queue_size=0)

    print("Press 'w' to move servo forward")
    print("Press 's' to move servo backward")
    print("Press 'q' to quit")
    get_command = ' '
    servo_cmd = 0

    while get_command != 'q'and not rospy.is_shutdown():
        get_command = raw_input()

        if (get_command == 'w'):
            servo_cmd += 10
            print('moving servo forward to %i' % servo_cmd)
            servo_cmd_pub.publish(servo_cmd)
        elif (get_command == 's'):
            servo_cmd -= 10
            print('moving servo backward to %i' % servo_cmd)
            servo_cmd_pub.publish(servo_cmd)
        elif (get_command == 'q'):
            print('quitting')
        else:
            print('bad command')
