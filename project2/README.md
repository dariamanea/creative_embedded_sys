
# ESP32 Controlled Sketches

## Daria Manea

The goal of this project was to incorporate hardware as controllers into the creation of digital art. My idea of creating sketches was inspired by my memories of using Paint and having a lot of fun with that as a young child. Since this is my first creative project involving hardware controllers, I wanted a simple project and was remembered how simple interactions with software such as creating doodles can be very entertaining. The joystick made sense as a way to control the motion of the cursor, the potentiometer seemed a good way to control the size of the "brush" (in this case the size of the circles) and the button was just a fun addition that I made it as a way to illuminate the background like a pink flashlight. 

 After running the file project2.ino on the ESP32, I ran the file script.js to receive the data from the hardware connected to the ESP32 (the joystick, button, and potentiometer) and turn it into parameters for the sketches. The sketches were made with the help of the library p5.js. 

 For the hardware part of this project, I used solderless wires to connect the joystick and potentiometer and I used soldering to connect the button to the ESP32's header. For the enclosing, I used a cardboard box in which I cut holes which allowed the three pieces of hardware and the USBC connector to stick out. 

 ![Screen Shot 2022-03-09 at 9 16 42 PM](https://user-images.githubusercontent.com/44726789/157576768-2820834f-b31c-4030-a310-ad869dba5998.png)
<img width="1440" alt="Screen Shot 2022-03-09 at 9 16 35 PM" src="https://user-images.githubusercontent.com/44726789/157576781-20bd8d3a-fc03-4d1c-b329-3add774a99bd.png">
