# No-Internet-Game-Robot
This robot plays Chrome's No Internet Dinosaur game by detecting the obstacles using an LDR and accordingly pressing the spacebar to make the dinosaur jump at the right time.

You can see this project in action [here](https://drive.google.com/file/d/1Ta62XcDXiYmHwIdTKOA_czHm0ljc0NhB/view?usp=sharing)!

This is a common beginner's project with one key improvement:
1. The LDR is placed at the edge of the screen rather than on it right in front of the dinosaur. 
2. This leads to the code having to construct a queue that stores the timings of all incoming obstacles and the position of the servo is always a function of how much time has elapsed for the obstacle in the beginning of the queue. 
3. The code also has to dynamically speed up the servo's response and reduce it's backward stroke as the time progresses since the game naturally also speeds up.  

The functions that the code performs are:
* Running a time-loop and in each iteration it;
  * Takes a reading from the LDR and the current time
  * Adds a time-value element to a queue if there is an obstacle
  * Decrements all elements of the queue
  * Updates the angle of the servo to advance or retreat in according to how close the next obstacle is
  * Pops elements off the queue after they are exhausted
* Decreases the value of time-value alements as the game speeds up
* Resests initial time after no obstacles are encountered for some time

Further improvements might include:
* Serial output by a false keyboard to mimic the pressing of a spacebar
* Creating an easily installabale unit for the robot
* Automatically adjusting setup arbitrary constants in a calibration step

This project is GPL-3.0 Liscenced to Aditya Nair under GogiPuttar
