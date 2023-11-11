import random from 'random';

function generateRandomArray(size) {
  const array = Array.from({ length: size }, () => random.int(1, size + 1));
  return array;
}

export function generateArrays(sizes) {
  return sizes.map(size => generateRandomArray(size));
}


