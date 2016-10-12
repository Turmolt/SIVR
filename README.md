# SIVR
Sam's Integrated Virtual Reality

Sam Gates Capstone Project
Computer Science
University of Maine

Requires Virtual Reality Peripheral Network library to be linked to the project.

VRPN Wiki:
https://github.com/vrpn/vrpn/wiki

VRPN Creating a new Device Class Tutorial:
https://github.com/vrpn/vrpn/wiki/Creating-a-new-device-class

```
USING IN UNITY:
Set up server with desired VR Purposes and devices selected and enabled
Launch Server
Import SIVR Unity Package into Unity project
Place Manager Object into scene
Access purpose data through code such as "SIVR.Head.Rotation" or "SIVR.Hands.Position"


EXAMPLE SIVR DEVICE CONFIGURATION FILE (Intersense Cube):

VRPN_Name: Tracker0         (NAME OF DEVICE ON VRPN SERVER)
Tracker_Type: Tracker       (TYPE OF DEVICE ON VRPN SERVER)
Channels: 7                 (NUMBER OF CHANNELS IT RETURNS)
Returns[Rotation,Position,Both,None]: Rotation (TYPE OF DATA DEVICE RETURNS)
Buttons: 0                  (NUMBER OF BUTTONS DEVICE HAS)
Rotation_Channels(X,Y,Z,W): (-2,3,-1,4) (MAPPING X TO NEGATIVE OF 2nd CHANNEL RETURNED, ETC)
Position_Channels(X,Y,Z,Scale): (1,2,3,4)
```
