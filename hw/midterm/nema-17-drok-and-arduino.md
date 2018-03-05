# Controlling a Nema 17 with Arduino and a Drok Controller

The documentation out there on the combination of all three of these parts is
pretty sparse, and for no good reason.

The Nema 17 is a good quality stepper motor, fitting for all sorts of motion
related projects.

Drok controllers are straightforward motor controllers that perfectly interface
between Arduinos and motors.

![All Three](https://i.imgur.com/9PlzImH.jpg)

The most annoying part of building this setup is knowing which wires go to
which. If you mess up your wiring, you probably won't fry the motor or the
controller, but you'll have a hard time figuring out if your code is faulty
or your components.

### Connecting the Motor to the Controller

The controller should be set up like this:

![Top View of Controller](https://i.imgur.com/NssYl7R.jpg)

You can see some small labels on the front lip. Looking under the motor you'll
find the others. Here's the mapping if your motor comes with red, green,
yellow, and blue wires:

Nema Wires | Drok Ports
-----------|-----------
Red        | Out 1
Green      | Out 2
Yellow     | Out 3
Blue       | Out 4

And that's it. Now the motor is connected to the controller. Next up is the
power.

### Hooking up the Right Power Supply

You'll need a 12 volt power supply. Cut off the tip and strip down the wires.
You should have a red positive lead and a blue ground lead. On the bottom of
the controller you'll find a `+12V` label and a `GND` label. Hook up the red
to the corresponding `+12V` hookup and blue to `GND`. Use a small screwdriver
to secure the leads.

In addition to the power supply's ground lead, **you also need to hook up a
connection to the Arduino's groud**. They must share a common ground. Simply
connect a wire to the same hookup as the power supply's blue lead. Connect that
to the breadboard's negative strip and connect another wire to one of Arduino's
ground pins.

In the picture above, the power supply is the two wires (blue and red) coming
out of the larger black wire.

### Connecting the Arduino

![Arduino wiring](https://i.imgur.com/pPlYTOp.jpg)

From here, hooking up the Arduino is pretty straightforward. I continuously
use the same wire colors and each corresponds to the Nema's wire colors. You'll
need 4 female to female wires, 4 male to male pins, and 4 male to male wires.
You can exclude either of the 4 male to male collections, but having multiple
wires allows you to better organize the board and make connections to buttons
and switches later.

Similar to as we saw above, the wiring is:

Female wires | Drok Ports | Arduino Ports
-------------|------------|--------------
Red          | IN1        | 11
Green        | IN2        | 10
Yellow       | IN3        | 9
Blue         | IN4        | 8

And make sure to remember to hook up Arduino's ground to the controller.

### Controlling the Motor with Code

Now everything's hooked up. We don't need very complicated code to run a
stepper. In fact, it's built in as an example. Here's the
`stepper > stepper_stepOnce` example code:

```c++
/*
   Stepper Motor Control - one revolution

   This program drives a unipolar or bipolar stepper motor.
   The motor is attached to digital pins 8 - 11 of the Arduino.

   The motor should revolve one revolution in one direction, then
   one revolution in the other direction.


   Created 11 Mar. 2007
   Modified 30 Nov. 2009
   by Tom Igoe

 */

//  stepper library, including the object
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
```

So you can see that adding a new stepper is as easy as listing its pins.

```c++
Stepper newStepper (200, 8, 9, 10, 11);
```

Setting its speed is straightforward.

```c++
newStepper.setSpeed(60); //  one rps
```

And you can make it single-step with...

```c++
newStepper.step(1);
```

So you have very fine control over how much you want to spin. Also, we know
that the Nema 17 has 200 steps per rotation, so you're rotation almost 2
degrees with every step (exactly `1.8` degrees).
