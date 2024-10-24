// TYPES, VALUES, AND VARIABLES

// 3.1 Overview and Definitions

// 3.2.6 Dates and Times

let timestamp = Date.now();     // The current time as a timestamp (a number)
let now = new Date();           // The current time as a Date object.
let ms = now.getTime();         // Convert to a millisecond timestamp.
let iso = now.toISOString();    // Convert to a string in standard format.

console.log(timestamp);
console.log(now);
console.log(ms);
console.log(iso);

// 3.3.1 String Literals
""      // The empty string: it has zero characters
'testing'
"3.14"
'name="myform"'
"Wouldn't you prefer O'Reilly's book?"
"τ is the ratio of a circle's circumference to its radius"
`"She said 'hi'", he said.`