# Zortrax Robotic Arm

![Zortrax](https://cdn.instructables.com/FCM/S2XY/IFZQT9YQ/FCMS2XYIFZQT9YQ.LARGE.jpg)

Zortrax holds a number of 3D models for robots and manuals to help build them.
I want to build their flagship robotic arm, gear it up with motors, and get it
moving around. I also want to create an interface to control the arm from a
computer and possibly, with human input. Imagine that a human could control the
arm with their arm. This could be pretty fun.

For basic testing and control, I intend to hook up a motor or two to some
potentiometers and buttons to show what kind of precision I have in the
control.

## Building it

Building the arm will require some intermediate wiring skills, mostly involving
using stepper motors with motor sheilds, as well as some 3D printing skills.
The arm can't really be bought (or at least, that's not the intention). All the
3D models exist and are ready to be printed by the maker themself.

Here's a list of the parts (most of which are already printed).

- [x] Arm-1-gear
- [x] Arm-1-lower
- [x] Arm-2
- [x] Arm-3
- [x] Base-gear
- [x] Side-cover-arm-L
- [x] Side-cover-arm-R
- [x] Side-cover-base-L
- [x] Side-cover-base-R
- [x] Side-lid-arm-L
- [x] Side-lid-arm-R
- [x] Small-gear
- [x] Support
- [x] Toothed-ring
- [x] Vertical-axis-gear
- [x] Arm-1-upper
- [x] Base (reprint with water-soluble method)
- [x] Grasper-1
- [x] Grasper-2
- [x] Grasper-body
- [x] Grasper-holder
- [x] Ring (possibly reprint)

Those are just the 3D printable parts. Then the builder needs some electronic
parts like Nema 17 motors. To see the other parts, check out the
[manual](http://www.zortrax.com/downloads/ROBOTIC_MANUAL.pdf).

After the printing, putting it together is pretty simple. The manual covers
most of it. The hard part is the motors. The manual isn't very specific. It
says "Nema 17"'s, which covers a rather broad range. I used
[these](https://www.amazon.com/dp/B0716S32G4/ref=sspa_dk_detail_0?psc=1&pd_rd_i=B0716S32G4&pd_rd_wg=XS8DR&pd_rd_r=K9WZXZAZBAC3TSGRY72M&pd_rd_w=a5LAO). It
seems like every motor I tried, however, had the same problem. Wiring them
up in parallel caused a power problem. The motors would be unresponsive or
not strong enough. Other times they would shudder. It was only one or two
of the three motors at a time, however. I've still yet to solve this problem.

To see how I wired individual Nema's and put the controller together, check
out `3dmodelAssignment.md` and `nema-17-drok-and-arduino.md`.
