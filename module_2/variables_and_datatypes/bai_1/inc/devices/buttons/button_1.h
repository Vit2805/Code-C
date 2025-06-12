#ifndef BUTTON_1_H
#define BUTTON_1_H

// Button 1 structure
typedef struct {
    bool isPressed;
}Button1;

// Function declaration
void initButton1();
int isButton1Pressed(Button1* button, int isPressed); 

#endif // BUTTON_1_H