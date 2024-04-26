# Ascii Chart CLI

A simple, easy to use, highly customizable node.js package, to create charts for your Command Line Interface

## Install

To install the latest package, run `npm i asciichart-cli` in your node.js project's folder

## Usage

First, you have to include the package:

```javascript
const asciichartCli = require('./chart');
```

Than, you have to declare an array, for the chart. Every value must be between 0 and 100, this will tell the program, how large one data should be.

```javascript
//the first column will be 10% of the chart, the second 50%, etc...
var data = [10, 50, 30, 100, 50, 10, 40, 10, 55, 20];
```

Setting up the chart is pretty easy, you can set the the height, by giving a value between 0 and 100, which will make your graph responsive. Also you can set the characters (with colors) used to draw the graph.
Asciichart-cli is using Chalk for coloring, so you should use their color names (link: https://www.npmjs.com/package/chalk). If you don't set a parameter, it'll use the default settings.

```javascript
var chart = new asciichartCli.chart(height, chartCharacter, backgroundCharacter, chartColor, backgroundColor);
var graphData = chart.createGraph(data);
```

And finally, you can turn the graph data into a string like this:

```javascript
var output = chart.drawGraph(graphData);
console.log(output);
```
