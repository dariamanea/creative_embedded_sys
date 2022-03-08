// Use your menus or right-click / control-click and choose "Inspect" > "Console"
console.log("Hello 🌎");


if ("serial" in navigator) {
    // The Web Serial API is supported.
    document.querySelector('button').addEventListener('click', async () => {
        // Prompt user to select any serial port.
        const port = await navigator.serial.requestPort();
        // Wait for the serial port to open.
        await port.open({
            baudRate: 9600
        });
        const textDecoder = new TextDecoderStream();
        const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);
        const reader = textDecoder.readable.getReader();
        // const reader = textDecoder.readable.pipeThrough(new TransformStream(new LineBreakTransformer())).getReader();
        
        // Listen to data coming from the serial device.
        while (true) {
          const { value, done } = await reader.read();
          if (done) {
            // Allow the serial port to be closed later.
            reader.releaseLock();
            break;
          }
          // value is a string.
          
        //   parsedVal = parseInt(value);
          console.log(String(value))
          if (!isNaN(parsedVal)) {
            console.log(parsedVal)
            // counterVal += parseInt(value);
            //add a tiny bit extra to the time to make Tone.js happy
            // synth.triggerAttackRelease((counterVal % 800) + 200, "8n", Tone.now()+counterVal/8000);
          }
        }
    });

}