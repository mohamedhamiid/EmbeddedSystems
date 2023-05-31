# Real Time Clock (RTC)
*For Video, Please keep your eye on the mouse to see what I click*

## Description
### It has 2 modes : Clock + Stopwatch (I call it Timer in the simulation)
### - Clock Mode : 
You can set time hours , minutes and seconds.
### - Timer (Stopwatch) Mode : 
Every 1 second it increases.
- You can switch from mode to other using keys mentioned in LCD.
- Also , You can reset Timer (Stopwatch).

## What I used ?
- ATMEGA32
- 6x 7segments
- Keypad

## Peripherals used
- DIO --> is used for LCD , Keypad and 7 segments
- Timer 0 --> is used in Overflow mode and setting the start of counting to result an interrupt every 0.5ms , TO perform multiplexing 7 segments display
, As every 5ms seconds , an interrupt occurs and next 7 segment is turned on and data displayed on it , and the previous one is turned off
- Timer 1 --> is used in CTC mode and the clock prescaler to result an interrupt every 1 second to increase seconds , minutes and hours
