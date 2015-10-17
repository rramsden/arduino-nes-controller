#include "NESController.h"

NESController controller(11, 12, 9);
 
void setup() {
    Serial.begin(9600);
}
 
void loop() {
    controller.read();

    if (controller.pressed(RIGHT)) {
        Serial.println("RIGHT");
    }
    if (controller.pressed(LEFT)) {
        Serial.println("LEFT");
    }
    if (controller.pressed(UP)) {
        Serial.println("UP");
    }
    if (controller.pressed(DOWN)) {
        Serial.println("DOWN");
    }
    if (controller.pressed(SELECT)) {
        Serial.println("SELECT");
    }
    if (controller.pressed(START)) {
        Serial.println("START");
    }
    if (controller.pressed(BUTTON_A)) {
        Serial.println("BUTTON_A");
    }
    if (controller.pressed(BUTTON_B)) {
        Serial.println("BUTTON_B");
    }

    delay(100);
}
