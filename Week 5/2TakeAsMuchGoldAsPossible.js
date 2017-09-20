var readline = require('readline');

process.stdin.setEncoding('utf8');
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
});

rl.on('line', readLine);

let capacity, items;

let lineN = 1;
function readLine (line) {
	if (lineN === 1) {
		capacity = parseInt(line.toString().split(' ')[0]);
	}

	if (lineN === 2) {
		items = line.toString().split(' ');
		items = items.map(parseFloat);
	}

	lineN++;
}

let weights = [];
let construct_lookup = (capacity, items) => {
	for (let i = 1; i <= items.length; i++) {
		for (let c = 0; c <= capacity; c++) {
			let currentItem = items[i - 1];
			let usingNow = 0;
			let notUsingNow = weights[i - 1][c];

			if (currentItem <= c) {
				usingNow = 	weights[i - 1][c - currentItem] + currentItem;
			}

			weights[i][c] = usingNow > notUsingNow ? usingNow : notUsingNow;
		}
	}

	return weights[items.length][capacity];
}


let oldLookup = (capacity, items) => {
	if (!weights[`${capacity}.${items}`]) {
		weights[`${capacity}.${items}`] = optimal_weight(capacity, items);
	}

	return weights[`${capacity}.${items}`];
}
const optimal_weight = (capacity, items) => {
	if (items.length === 0 || capacity <= 0) {
		return 0;
	}

	let currentItem = items[items.length - 1];

	let notUsingNow = oldLookup(capacity, items.slice(0, -1))

	if (currentItem <= capacity) {
		let usingNow = oldLookup(capacity - currentItem, items.slice(0, -1)) + currentItem;
		return usingNow > notUsingNow ? usingNow : notUsingNow;
	}

	return notUsingNow;
}

rl.on('close', () => {
	// FUCKING JAVASCRIPT .FILL COPIES THE ARRAY REFERENCE,
	// SO THAT WHEN I FILL UP THE FIRST ROW, ALL SUBSEQUENT ROWS GET THE SAME VALUE
	// FUCK.
	for (let i = 0; i <= items.length; i++) {
		weights[i] = new Array(capacity + 1).fill(0);
	}
	console.log(construct_lookup(capacity, items));

});