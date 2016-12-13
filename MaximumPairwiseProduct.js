var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

rl.on('line', readLine);

let n, ints;

let lineN = 1;
function readLine (line) {
	if (lineN === 1) {
		n = parseFloat(line, 10);
	}

	if (lineN === 2) {
		ints = line.toString().split(' ');
	}

	lineN++;
}

const getHighest = arr => {
	let highest = 0;
	arr.forEach(n => {
		n = parseFloat(n);
		if (n > highest) {
			highest = n;
		}
	})

	return highest;
}

rl.on('close', () => {
	let firstHighest = getHighest(ints);
	let whereIsFirstHighest = ints.indexOf(firstHighest);
	ints.splice(whereIsFirstHighest, 1);
	let secondHighest = getHighest(ints);

	console.log(firstHighest * secondHighest);
});