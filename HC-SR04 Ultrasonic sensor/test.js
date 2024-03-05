const express = require('express');
const app = express();
const port = 3000;

const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline')

const comPort1 = new SerialPort({
    path: "/dev/ttyUSB0",
    baudRate: 9600,
    dataBits: 8,
    stopBits: 1,
    parity: 'none',
});

const parser = comPort1.pipe(new ReadlineParser({ delimiter: '\r\n' }))

parser.on("data", function (data) {
    console.log(data);
});

app.listen(port, function () {
    console.log(`Example app listening on port ${port}!`);
});
