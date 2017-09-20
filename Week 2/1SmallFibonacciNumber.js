var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

let n;
let first = 1;
let second = 1;

rl.on('line', line => {
	if (line !== "\n") {
		n = parseInt(line);

		if (n < 2) {
			console.log(n);
			process.exit();
		}

		if (n === 2) {
			console.log(1);
			process.exit();
		}
	}	
});

rl.on('close', () => {
	for (let i = 3; i <= n; i++) {
		let j = first;
		first = second;
		second = first + j;
	}

	console.log(second);
});