### Cloud Lamp with Lightning Effect



Materials Used: 

- Esp32 
- HC-SR04 Ultrasonic Distance sensor
- WS2812 LEDs strip
- 10 in paper lantern 
- Polyfil Polyester Fiber Fill 
- Wires, Glue


## The Technical Process

To code this project, I used the Freenove WS2812 LEDs library for ESP32s to program the lights and the lighting pattern. In order to use the HC-SR04 ultrasonic distance sensor, I followed the tutorial from the freenove tutorial from Chapter 21 on Ultrasonic Ranging.  The tutorial simply would print to the Serial Monitor the distance from an object to the ultrasonic sensor. I modified it by adding an if statement which triggered the lightning pattern for the LEDs if the distance was less than 50cm. 

## The Creative Process and Making the Encasing

My inspiration for this project came from Instagram artists who shared pictures of their room decor which had cloud-shaped lanterns hanging from ceilings. I wanted to make those cloud lanterns myself, but instead of having them with warm light, I wanted to create something more like a storm cloud. Since I also wanted to incorporate tech into the project, I got the idea of using a distance sensor that would trigger a "lighting" pattern in the cloud lamp. 

I wanted to make the cloud lantern very full, so I glued a lot of the polyester filling around the paper lantern in irregular patterns. It was challenging having the filling stay in place while transporting the lamp around, so some of its original shape was distorted. After having the encasing done, I tucked in the ESP32, motion sensor, and LEDs inside the paper lantern and made sure that the distance sensor was pointing downwards from the bottom of the encasing. 


## Demo 


https://www.youtube.com/watch?v=Z6gP5VoEBrk&feature=emb_title 
https://blogger.googleusercontent.com/img/a/AVvXsEgjSdY28JEfAhfgz6VKYb6ldSY373NMH78ISY04Bjmdafllo3FcSXOze36wZtKg5b3-IkE0WVMghR8KoSiTWiLDPjBv1zF_IKBb0J-WsLyCal5titrpjkC5WSaYeJa6iT68QWf_AeF1r5j8QIHa-rBRoKterxC1EOq330L3s3V_LAF0mLJnGKhDxztqGg
https://blogger.googleusercontent.com/img/a/AVvXsEhY-dL2A0dVm0ySFrpYH7nvFIXOcyn3PIhoYja3od9mjVEL3jmZfj9l5E3lJYQ4lDHqM5RTutWan7DLiJ5SzR9CxeyYUBZcEdE9zvAHiVDzuzU3KN7T8rwRgTBLvZ_TqvGnLTRSrSgLRI3gShnBPfiqkoSZf_Hg--5raRDurwkzjP9SgBujVnQbnHjOCg
