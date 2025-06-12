#ifndef BUTTON_2_H
#define BUTTON_2_H

// Button 2 structure
typedef struct {
    int isPressed;
}Button2;

// Function declaration
void initButton2();
int isButton2Pressed(Button2* button, int isPressed);

#endif // BUTTON_2_H