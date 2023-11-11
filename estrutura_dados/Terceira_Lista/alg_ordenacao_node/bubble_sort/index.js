import {performance} from 'perf_hooks'
import {generateArrays} from '../utils/gerador_array.js'

function swap(arr, i, j) {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  
  function bubbleSort(arr) {
    const n = arr.length;
  
    for (let i = 0; i < n - 1; i++) {
      for (let j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr, j, j + 1);
        }
      }
    }
  }
  
  function printArray(arr) {
    for (let i = 0; i < arr.length; i++) {
      process.stdout.write(`${arr[i]} `);
    }
    process.stdout.write('\n');
  }
  
  
  const array1 = generateArrays([101]);
  const array2= generateArrays([1001]);
  const array3 = generateArrays([10001]);
  const array4 = generateArrays([100001]);
  const array5 = generateArrays([10000001]);
  
  const start1 = performance.now(); 
  bubbleSort(array1);
  const end1 = performance.now(); 

  const start2 = performance.now(); 
  bubbleSort(array2);
  const end2 = performance.now(); 

  const start3 = performance.now(); 
  bubbleSort(array3);
  const end3 = performance.now(); 

  const start4 = performance.now(); 
  bubbleSort(array4);
  const end4 = performance.now(); 

  const start5 = performance.now(); 
  bubbleSort(array5);
  const end5 = performance.now(); 

  console.log(`Time executation1: ${end1 - start1} milissegundos`);
  console.log(`Time executation2: ${end2 - start2} milissegundos`);
  console.log(`Time executation3: ${end3 - start3} milissegundos`);
  console.log(`Time executation4: ${end4 - start4} milissegundos`);
  console.log(`Time executation5: ${end5 - start5} milissegundos`);