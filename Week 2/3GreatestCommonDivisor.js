var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

rl.on('line', readLine);

let a, b;
let product;

function readLine (line) {
	if (line !== "\n") {
		let ints = line.toString().split(' ').map(n => +n);
		if (ints[1] > ints[0]) {
			a = ints[1];
			b = ints[0];
		} else {
			a = ints[0];
			b = ints[1];
		}
	}
}

rl.on('close', () => {
	do {
		product = a % b;
		a = b;
		b = product;
	} while (product > 0);

	console.log(a);
});