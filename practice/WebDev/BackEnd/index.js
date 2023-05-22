const express = require("express");
const http = require("http");
const app = express();
const events = require('events');
const eventEmitter = new events.EventEmitter();

// eventEmitter.on('status', (code, msg) => {
//     console.log(`status ${code} and ${msg}`);
// });
// eventEmitter.emit('status', 200, 'ok');

console.log("Hello world!");

app.get('/', (req, res) => {
    res.send("Welcome to Node.js");
})

// eventEmitter.on("check", (msg) => {
//     console.log(msg);
// })
// eventEmitter.emit("check", "Hi, emitting an check event");

app.listen(3100, (req, res) => {
    console.log("listening on port 3100");
})
// http.createServer((req, res) => {
//     console.log("listening on port 3200");
//     console.log(req.url);
//     res.write("Hey,working with http");
//     res.end();
// }).listen(3200);