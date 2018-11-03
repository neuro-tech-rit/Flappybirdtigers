#include <stdio.h>
#include <Mouse.h>

//@author Hillary
int min = 0;
int max = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(A5, INPUT);
    Mouse.begin();
}

void loop() {
    int x = analogRead(A5);
    if(x < min){
        min = x;
    }
    if(x > max){
        max = x;
    }
    x = map(x, min, max, 0, 100);
    if (x > 30)
    {
        Mouse.click(MOUSE_LEFT);
    }
    Serial.println(x);
    delay(50);
}
