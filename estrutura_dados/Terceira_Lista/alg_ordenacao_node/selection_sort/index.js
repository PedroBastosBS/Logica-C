import {performance} from 'perf_hooks'
import {generateArrays} from '../utils/gerador_array.js'

function swap(arr, xp, yp) {
    const temp = arr[xp];
    arr[xp] = arr[yp];
    arr[yp] = temp;
  }
  
  function selectionSort(array) {
    const n = array.length;
  
    for (let i = 0; i < n - 1; i++) {
      let min_idx = i;
      for (let j = i + 1; j < n; j++) {
        if (array[j] < array[min_idx]) {
          min_idx = j;
        }
      }
  
      swap(array, min_idx, i);
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
  selectionSort(array1);
  const end1 = performance.now(); 

  const start2 = performance.now(); 
  selectionSort(array2);
  const end2 = performance.now(); 

  const start3 = performance.now(); 
  selectionSort(array3);
  const end3 = performance.now(); 

  const start4 = performance.now(); 
  selectionSort(array4);
  const end4 = performance.now(); 

  const start5 = performance.now(); 
  selectionSort(array5);
  const end5 = performance.now(); 



  console.log(`Time executation1: ${end1 - start1} milissegundos`);
  console.log(`Time executation2: ${end2 - start2} milissegundos`);
  console.log(`Time executation3: ${end3 - start3} milissegundos`);
  console.log(`Time executation4: ${end4 - start4} milissegundos`);
  console.log(`Time executation5: ${end5 - start5} milissegundos`);


  