/*
This question was asked by CircleCI, Karat (2021)

Rewrite the following greet function using default parameters or destructured parameters
*/
function greet(name, greeting) {
    name = (typeof name !== 'undefined') ?  name : 'Student';
    greeting = (typeof greeting !== 'undefined') ?  greeting : 'Welcome';

    return `${greeting} ${name}!`;
}

function greet_default_params(name = 'Student', greeting = 'Welcome') {
    return `${greeting} ${name}!`;
}

console.log(greet_default_params()); // Welcome Student!
console.log(greet_default_params('James')); // Welcome James!
console.log(greet_default_params('Richard', 'Howdy')); // Howdy Richard!

function greet_destructured_params([name = 'Student', greeting = 'Welcome']) {
    return `${greeting} ${name}!`;
}

console.log(greet_destructured_params([])); // Welcome Student!
console.log(greet_destructured_params(['James'])); // Welcome James!
console.log(greet_destructured_params(['Richard', 'Howdy'])); // Howdy Richard!

// Given three async methods each with a return value, write a function that merges the results from all three and returns it