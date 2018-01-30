# Physical Computing

Computing with physical machines and human interactions.

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
default example project `blink`.)

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
