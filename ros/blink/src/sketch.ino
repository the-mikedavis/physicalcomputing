#include <ros.h>
#include <std_msgs/Empty.h>
#define LED_PIN 13

ros::NodeHandle nh;

void messageCb(const std_msgs::Empty &toggle_msg) {
    digitalWrite(LED_PIN, HIGH - digitalRead(LED_PIN)); //   toggle the LED
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    nh.initNode();
    nh.subscribe(sub);
}

void loop() {
    nh.spinOnce();
    delay(1);
}
