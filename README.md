# Digital-Gungroo
IDD Final Project

All our work and photos in [Google Drive](https://drive.google.com/drive/folders/1AlLCML_3bFY2mgS-XThAkAVHnjg3Gx6r?usp=sharing).

This project was inspired by the traditional ghungroos often used in forms of Indian classical dance. These are anklets that are traditionally covered in large bells, and are used to add percussive sounds to the dancers footwork. It is also an essential part of the performers' costumes, so we knew going into this that the design would be very important. As dancers, Ananya and Meera have used these often, and wanted to bring a digital dimension to the traditional art form. 
![Traditional Ghungroo](/images/Ghungroo.jpg]

## Design
We began creating several iterations of paper prototypes, and we explored creating living hinges on paper and cardboard, as shown below. We were aiming to use this material as the prototype anklet. 
![Prototype 1](/images/FirstAttempt.jpg)
![Prototype 2[(/images/SecondAttempt.jpg)

After playing around with more versions of living hinges, we found one that worked for us, and was able to support the first version of our circuit:
![Prototype 3](/images/ThirdAttempt_1.jpg)
![Prototype 3 Worn](/images/ThirdAttempt_2.jpg)

## Circuit
For the first step for our circuit, we created a form of a pedometer using the accelerometer. We used the acceleration measured on the y axis to determine whether someone was taking a footstep. Below is an image of the circuit:
![First Circuit](/images/AccelerometerCircuit.jpg)

From here, we created a bash script to run every time a footstep was detected, and play the sound of the ghungroo bells. Below is a video of our first working prototype with sound:/
[See Video Here](https://drive.google.com/open?id=1kgregFIQAMCG6QkecJbtPY6cUl8rYSMW)

We then began working with light, and wanted to create three layers of lights that would respond to movements on the different axes. Below is a video using the LEDs in combination with the accelerometer:
[See Video Here](https://drive.google.com/file/d/1_J5kBKLptu_eg036MyOKKOaFNdn7jq2I/view?usp=sharing)

We are currently working with the HC-05 bluetooth modules and an LED lightstrip to combine thesee individual working elements into one coherent design. 
