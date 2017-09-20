var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

rl.on('line', readLine);

let n;

let lineN = 1;
function readLine (line) {
	if (lineN === 1) {
		n = parseFloat(line, 10);
	}
}

const sequences = {};
const lookup = n => {
	console.log(n);
	if (!sequences[n]) {
		sequences[n] = optimal_steps(n);
	}
	return sequences[n];
}
const optimal_steps = (n) => {
	if (n === 1) {
		return 0;
	}

	let comparisons = [];
	if (n % 3 === 0) {
		comparisons.push(lookup(n / 3));
	} else if (n % 2 === 0) {
		comparisons.push(lookup(n / 2));
	}

	comparisons.push(lookup(n - 1));

	comparisons = comparisons.sort();

	return comparisons[0] + 1;
}

rl.on('close', () => {
	const optimal = optimal_steps(n);
	sequences[n] = optimal;
	const optimal_sequence = [];
	let current = n;
	for (let i = 0; i <= optimal; i++) {
		if (sequences[current * 3]) {
			optimal_sequence.push(current * 3);
			current = current * 3;
		} else if (sequences[current * 2]) {
			optimal_sequence.push(current * 2);
			current = current * 2;
		} else {
			optimal_sequence.push(current + 1);
			current++;
		}
	}
	console.log(optimal);
	console.log(optimal_sequence.join(' '));
});