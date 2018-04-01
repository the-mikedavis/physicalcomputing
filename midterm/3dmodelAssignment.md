# A Robot Arm Controller

The controller for the robot arm isn't particularly flashy. It's not filled
with a bunch of functionality. Its main function is to ensure that the
potentiometers (the twisty-things) don't pop out and cause a short circuit.

When the potentiometers were on the breadboard (the prototype controller),
they would commonly pop out. This would confuse the program, which thought
that the user had moved the knob all the way to 0 (causing a joint to move).
Here's the prototype controller:

![Prototype](https://i.imgur.com/Wmz3WLh.jpg?1)

As you can see, it's nothing more than a breadboard with cardstock on top.
It's also not clear exactly how to use the knobs. Do they correspond to
absolute positions? Do they drive deltas? In addition, the wires come out in
a really ugly looking way. The biggest problem though, was loose
potentiometers.

The solution was to come up with a casing that would perfectly hold them in.
I wanted to glue them to a board and solder in some wires, making it
impossible for them to come out.

The next consideration was: "what's a natural way to control something like
this? I decided a vertical controller that could rest in the palm like a phone
would be the perfect shape.

I measured out the dimensions of the potentiometer and threw everything into
Onshape. Here's what I came up with:

![Isometric View](https://i.imgur.com/FTNX8ue.jpg)

![Front View](https://i.imgur.com/vDRY2Ns.jpg)

![Back View](https://i.imgur.com/5BU99U1.jpg)

The potentiometers each have slots one inch away from one another. The design
is thin so it's not a waste of materials. The back has a groove in it to feed
out the wires. Each potentiometer slot has a circle cut into it which is for
the turning part of it. The turning part comes through the device and has a
moving part on the bottom that twists as the user twists. I figured that any
attempt to glue in the potentiometer would lock the twistability because
this circle would be glued in too. The compromise was to cut it its own hole.
Each of the three rectangles in each slot is for a leg of the potentiometer.
The right two rectangles are ground and power. The left leg is the output
line, which is fed to the Arduino.

I then exported the CAD sketch to an STL file and printed it with an
Ultimaker. Here's the printing:

![Printing](https://i.imgur.com/hVgmTCT.jpg)

Here's the output:

![Front View](https://i.imgur.com/K2Cm6tV.jpg)

![Back View](https://i.imgur.com/Ns8Cm6X.jpg)

It's a bit blocky in some areas. A good solution would be to print with a
finer headed print core. The jaggedness is fine, however, since any tightness
in the holes makes the pins stay in better.

Here's the controller with the pins in and soldered:

![Wired](https://i.imgur.com/maxVn9L.jpg)

It's a bit bulky. The wiring took a lot more room than I expected.

It's got a ground wire (black) and a 5V wire (red), as well as three white
wires for analog inputs (A0, A1, A2).

If I were to do it again, I'd like to create a snappable or glueable backing
that covers up the wires.
