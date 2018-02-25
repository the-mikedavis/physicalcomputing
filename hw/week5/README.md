# Light Theremin

Theremins are a cool tool to distort and meddle with noise with your hands. You can build one really
quickly and easily with Arduino.

[![Light Theremin demonstration](http://img.youtube.com/vi/tS8esebYFrs/0.jpg)](http://www.youtube.com/watch?v=tS8esebYFrs "Light Theremin")

A photoresistor measures the amount of light hitting it. It then takes that reading and uses it to
modify the tone the piezo speaker is outputting. Since you can intuitively block out the light with
your hand, you can create music very easily!

# Hour Glass

Arduino has a built-in time function, `millis()`, that gives the time since start. Millis is really useful
for all sorts of projects, and the easiest to see is an hour glass. Just keep track of time and be able to
start over.

[![Hour glass demonstration](http://img.youtube.com/vi/aUnoXNlcmt0/0.jpg)](http://www.youtube.com/watch?v=aUnoXNlcmt0 "Hour glass")

I've modified the code to change 60 minutes into 6 seconds so you can see the shifts. Every ten minutes,
when properly configured, the hour glass will light up one of the LEDs. Once you get to an hour, just shake
the board to register the tilt reader, and start all over again.
