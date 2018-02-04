# Week 3 - "Space Ship Interface", Ino and ROS

#### Space Ship Interface

Chapter two of the Arduino Projects Book details a very visual project that
teaches the user about using digital inputs and outputs. Pins can not only
be written to, with `digitalWrite`, but also read from, with `digitalRead`.
Throw this in with a few LEDs and a push button, and you can make something
cool out of some very simple code. Here's a video of the whole thing put
together.

[![Space Ship Interface](https://img.youtube.com/vi/fTJKma3hXK4/0.jpg)](http://www.youtube.com/watch?v=fTJKma3hXK4)

## Ino

Using the [ino](http://inotool.org) command line utility:

#### Installation

- Clone the repo. `git clone git://github.com/amperka/ino.git ~`
- Go to the repo. `cd ~/ino`
- Install it. `make install`
    - You'll probably need `sudo` privileges.
- Check installation. `type ino`
    - Should output `ino is /usr/local/bin/ino` or similar.
    - Should not output `ino not found`.

#### Usage

Create a new project hierarchy with `ino init -t blink`. (This will create the
example project `blink`.)

    $ ino init -t blink
    $ tree
        blink/
        |---- src/
        |     `---- sketch.ino
        `---- lib/

Now you can edit the blink program in `sketch.ino`.

When done, compile the program with `ino build`. Upload with `ino upload`. You
may need `sudo` privileges. Ino will find the port for you (on Linux, the
default seems to be `ttyACM0`, on macOS `tty.usbmodem14411`).

#### Removing the need for `sudo` privileges

If you needed `sudo` to run `ino upload`, the port doesn't have proper
permissions. Solve it with

    $ sudo chmod a+rw /dev/ttyACM0

Or whatever the name of your device is.


## Using ROS with Arduino and Ino

I'm using:

- Arduino Uno
- [ROS](http://www.ros.org/about-ros/) Lunar
- Ubuntu 16.04
- `ino` (no IDE)

ROS, the Robot Operating System, is an environment to implement code for
robots. ROS allows you to create multiple processes that communicate and
interact with each other.

ROS has a simple API for allowing different processes to communicate with one
another. ROS Topics allow nodes to publish data readable by "subscriber" nodes.
One of the beginner arduino projects with ROS leverages this Topic structure
to remotely control an LED's state. To see the code, go to the `ros` folder at
the root of this project.

Here's the code for this weeks "blink" project, annotated:

```cpp
// include the arduino-ros library
#include <ros.h>
// include the standard message for emtpy
#include <std_msgs/Empty.h>
// define macro for the output LED's pin
#define LED_PIN 13

ros::NodeHandle nh;

// callback for the subscriber when data comes in
void messageCb(const std_msgs::Empty &toggle_msg) {
    // once you get the message, alternate to the opposite state
    // as the one you're in
    digitalWrite(LED_PIN, HIGH - digitalRead(LED_PIN));
}

// create a subscriber object for the topic "toggle_led" that
// executes the message call-back function when info is sent
ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup() {
    // set the LED as an output
    pinMode(LED_PIN, OUTPUT);
    // initialize the node (connect to ROS)
    nh.initNode();
    // subscribe to the topic
    nh.subscribe(sub);
}

void loop() {
    // keep the ROS node alive
    nh.spinOnce();
    // small delay for sanity
    delay(1);
}
```

To execute it, ROS's Core needs to be running, as well as a python script that
allows communication with the serial device's port. Here's a video of
execution. Each call sends an empty message that executes the callback.

[![asciicast](https://asciinema.org/a/23VJfDLOZO68bpT5URMwLhqfB.png)](https://asciinema.org/a/23VJfDLOZO68bpT5URMwLhqfB)

