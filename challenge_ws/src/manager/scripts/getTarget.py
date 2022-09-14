#!/usr/bin/env python
from geometry_msgs.msg import Pose
from manager.srv import getTarget,getTargetResponse
import rospy

def definePose(x,y,z,ox,oy,oz,q):
    p = Pose()
    p.position.x = x
    p.position.y = y
    p.position.z = z
    p.orientation.x = ox 
    p.orientation.y = oy
    p.orientation.z = oz
    p.orientation.w = q
    return p

TARGETS_DICT = {
    'Arduino'  : definePose(1,1,1,0,0,0,0),
    'Puente H' : definePose(0,1,1,0,0,0,0),
    'Motor'    : definePose(1,1,2,0,0,0,0),
    'LED'      : definePose(0,1,2,0,0,0,0),
}

def handle_getTarget(req):
    return getTargetResponse(TARGETS_DICT[req.name])

def getTarget_server():
    rospy.init_node('getTarget_server')
    s = rospy.Service('getTarget', getTarget, handle_getTarget)
    rospy.spin()

if __name__ == "__main__":
    getTarget_server()