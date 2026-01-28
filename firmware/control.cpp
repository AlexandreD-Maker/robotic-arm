#include "control.h"
#include "mode_switching.h"

uint8_t motorAngle[NUMBER_MOTOR];
String userInput[NUMBER_MOTOR];

uint8_t potPin[NUMBER_MOTOR] = {
    BASE_POT_PIN,
    SHOULDER_POT_PIN,
    ELBOW_POT_PIN,
    WRIST_POT_PIN,
    GRIPPER_POT_PIN
};

void readPot() {
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
        motorAngle[i] = map(analogRead(potPin[i]), 0, 1023, 0, 180);
    }
}

void readUserInput() {

    // Set all element of userInput to empty string
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
      userInput[i] = "";
    }

    // Getting user input and parsing it
    String received_data = Serial.readStringUntil("\n");
    received_data.trim();

    uint8_t word_counter = 0;
    // Ensure user input is 5 arguments max
    if(word_counter < NUMBER_MOTOR) { 
        for(char c : received_data) {
        
            if(!isSpace(c)) {
              userInput[word_counter] += c;
            }

            else {
                word_counter++;
            }
        }
    }
    for(uint8_t i = 0; i < NUMBER_MOTOR; i++) {
        // If user entered "-" or no value, the current angle doesn't change
        if(userInput[i] == "-" || userInput[i] == "") { 
            userAngle[i] = userAngle[i];
        }
        // Ensure the angle is between 0 and 180°
        else if(userInput[i].toInt() <= 180 && readUserInput[i] >= 0) {
            userAngle[i] = userInput[i].toInt();
        }
    }
    
}