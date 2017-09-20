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
		ints = ints.map(parseFloat);
	}

	lineN++;
}

const count_sort = arr => {
	const count = {};
	const threshold = n / 2;

	for (ele of arr) {
		if (!count[ele]) {
			count[ele] = 0;
		}

		if (++count[ele] > threshold) {
			return 1;
		}
	}

	return 0;
}

rl.on('close', () => {
	console.log(count_sort(ints));
});