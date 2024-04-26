const chalk = require('chalk');

const screenHeight = process.stdout.rows;

class chart {
	constructor(heightPercentage = 100, chartCharacter = 'o', backgroundCharacter = ' ', chartColor = 'cyan', backgroundColor = 'black') {
		this.height = (heightPercentage / 100) * screenHeight;
		this.chartCharacter = chartCharacter;
		this.backgroundCharacter = backgroundCharacter;
		this.chartColor = chartColor;
		this.backgroundColor = backgroundColor;
	}

	createLine(percentage) {
		let output = [];

		let maxHeight = this.height * (percentage / 100);

		for (let i = this.height; i > 0; i--) {
			if (i < maxHeight) {
				output.push(true);
			} else if (i >= maxHeight) {
				output.push(false);
			}
		}
		return output;
	}
	createGraph(data) {
		let output = [];
		for (let i = 0; i < data.length; i++) {
			output.push(this.createLine(data[i]));
		}
		return output;
	}

	drawGraph(graphData) {
		let output = '';
		for (let x = 0; x < graphData[0].length; x++) {
			for (let i = 0; i < graphData.length; i++) {
				if (graphData[i][x] == true) {
					output += chalk[this.chartColor](this.chartCharacter);
				} else {
					output += chalk[this.backgroundColor](this.backgroundCharacter);
				}

				if (i == graphData.length - 1) {
					output += '\n';
				}
			}
		}
		return output;
	}
}

module.exports.chart = chart;
