// Use your menus or right-click / control-click and choose "Inspect" > "Console"
console.log("Hello 🌎");


// Audio file 
var audio = new Audio('under_stars.mp3');
let ellipseSize = 60;

function setup() {
    createCanvas(1200, 1200);
  }
  
  function draw(x, y) {
    
    if (mouseIsPressed) {
      fill(0);
    } else {
      fill(255);
    }
    // 80 and 80 for elipseSize
    ellipse(mouseX, mouseY, ellipseSize, ellipseSize);
  }

if ("serial" in navigator) {
    // The Web Serial API is supported.
    document.querySelector('button').addEventListener('click', async () => {
        // Prompt user to select any serial port.
        const port = await navigator.serial.requestPort();
        // Wait for the serial port to open.
        await port.open({
            baudRate: 115200,
            bufferSize : 2048
        });

        const textDecoder = new TextDecoderStream();
        const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);
        const reader = textDecoder.readable.getReader();

        // Listen to data coming from the serial device.
        while (true) {
        const { value, done } = await reader.read();
        if (done) {
            reader.releaseLock();
            break;
        }
        // value is a string.

        console.log(value);


        if( String(value).trim() == "b0"){
            // audio.play();
            document.body.style.background = "pink"; 
        }

        if( String(value).trim() == "b1"){
            // audio.play();
            document.body.style.background = "black"; 
        }

        // potentiometers go from 0 to 4095

        if( String(value).trim() == "x"){
        }

        if( String(value).trim() == "y"){
            
        }

        if( String(value.substring(0,1)).trim() == "p"){
            console.log("i received p value")
            console.log(value)
            ellipseSize = (parseInt(String(value.substring(1)).trim())/4095)*100
            console.log(ellipseSize)
        }


        }
    });

}