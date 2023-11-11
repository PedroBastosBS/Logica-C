import {performance} from 'perf_hooks'
import {generateArrays} from '../utils/gerador_array.js'

function insertionSort(array) {
    const n = array.length;
  
    for (let i = 1; i < n; i++) {
      const key = array[i];
      let j = i - 1;
  
      while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j = j - 1;
      }
  
      array[j + 1] = key;
    }
  }
  
  function showArray(array) {
    for (let i = 0; i < array.length; i++) {
      process.stdout.write(`${array[i]} `);
    }
    process.stdout.write('\n');
  }
  
  const array1 = generateArrays([101]);
  const array2= generateArrays([1001]);
  const array3 = generateArrays([10001]);
  const array4 = generateArrays([100001]);
  const array5 = generateArrays([10000001]);
  
  const start1 = performance.now(); 
  insertionSort(array1);
  const end1 = performance.now(); 

  const start2 = performance.now(); 
  insertionSort(array2);
  const end2 = performance.now(); 

  const start3 = performance.now(); 
  insertionSort(array3);
  const end3 = performance.now(); 

  const start4 = performance.now(); 
  insertionSort(array4);
  const end4 = performance.now(); 

  const start5 = performance.now(); 
  insertionSort(array5);
  const end5 = performance.now(); 

  console.log(`Time executation1: ${end1 - start1} milissegundos`);
  console.log(`Time executation2: ${end2 - start2} milissegundos`);
  console.log(`Time executation3: ${end3 - start3} milissegundos`);
  console.log(`Time executation4: ${end4 - start4} milissegundos`);
  console.log(`Time executation5: ${end5 - start5} milissegundos`);