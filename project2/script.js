// Use your menus or right-click / control-click and choose "Inspect" > "Console"
console.log("Hello 🌎");

function fetchStream() {
    const reader = stream.getReader();
    let charsReceived = 0;
  
    // read() returns a promise that resolves
    // when a value has been received
    reader.read().then(function processText({ done, value }) {
      // Result objects contain two properties:
      // done  - true if the stream has already given you all its data.
      // value - some data. Always undefined when done is true.
      if (done) {
        console.log("Stream complete");
        para.textContent = value;
        return;
      }
  
      // value for fetch streams is a Uint8Array
      charsReceived += value.length;
      const chunk = value;
      let listItem = document.createElement('li');
      listItem.textContent = 'Received ' + charsReceived + ' characters so far. Current chunk = ' + chunk;
      list2.appendChild(listItem);
  
      result += chunk;
  
      // Read some more, and call this function again
      return reader.read().then(processText);
    });
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

        // const textDecoder = new TextDecoderStream();
        // const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);

        // while (port.readable) {
        //     const reader = textDecoder.readable.getReader();
          
        //     try {
        //       while (true) {
        //         const { value, done } = await reader.read();
        //         if (done) {
        //           // Allow the serial port to be closed later.
        //           reader.releaseLock();
        //           break;
        //         }
        //         if (value) {
        //           console.log(value);
        //         }
        //       }
        //     } catch (error) {
        //       // TODO: Handle non-fatal read error.
        //     }
        //   }
        // With transform streams.

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
}

const textEncoder = new TextEncoderStream();
const writableStreamClosed = textEncoder.readable.pipeTo(port.writable);

reader.cancel();
await readableStreamClosed.catch(() => { /* Ignore the error */ });

writer.close();
await writableStreamClosed;

await port.close();

       
    });

}