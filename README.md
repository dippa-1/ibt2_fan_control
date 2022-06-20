# IBT2 Motor Control
PWM control for BTS7960 (IBT-2) H-Bridge on Arduino Pro Micro with a potentiometer (one direction only)

I use this to build a fan with a brushed DC Motor, speed-controlled by a potentiometer.
It runs the PWM at 25kHz, which is the specified maximum for the h-bridge. 
This reduces high pitch noise and is quieter than the standard 1kHz or 500Hz PWM.
