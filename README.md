Homework 2 – Floating Point Overflow Detector

Course: CS3339 – Computer Architecture  

Semester: Fall 2025  

Due: October 24, 2025  



---



###### &nbsp;Team Members

\- Bryce Gill   



---



###### &nbsp;Description

This program detects floating-point overflow when adding a loop increment value to a loop bound.  

It also prints out the IEEE 754 binary representation of both floating-point inputs.  



The program is written in C++ and uses the <bitset> class to convert floats to their IEEE 754 binary form.



---



###### How to Compile

Open a terminal in the directory containing the source file and run:



g++ -o fp\_overflow\_detector fp\_overflow\_detector.cpp



###### How to Run 

In the same Directory, run: 



./fp\_overflow\_detector <loop\_bound> <loop\_counter>



Example:

./fp\_overflow\_detector 1.0e38 1.0e30





