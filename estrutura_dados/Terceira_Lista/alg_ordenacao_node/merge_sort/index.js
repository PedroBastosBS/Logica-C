import {performance} from 'perf_hooks'
import {generateArrays} from '../utils/gerador_array.js'


function merge(arr, l, m, r) {
    const n1 = m - l + 1;
    const n2 = r - m;
  
    const L = new Array(n1);
    const R = new Array(n2);
  
    for (let i = 0; i < n1; i++) {
      L[i] = arr[l + i];
    }
  
    for (let j = 0; j < n2; j++) {
      R[j] = arr[m + 1 + j];
    }
  
    let i = 0;
    let j = 0;
    let k = l;
  
    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }
  
    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }
  
    while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
    }
  }
  
  function mergeSort(arr, l, r) {
    if (l < r) {
      const m = Math.floor(l + (r - l) / 2);
  
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
  
      merge(arr, l, m, r);
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
  console.log(array5);
  const arr_size1 = array1.length;
  const arr_size2 = array2.length;
  const arr_size3 = array3.length;
  const arr_size4 = array4.length;
  const arr_size5 = array5.length;
  
  const start1 = performance.now(); 
  mergeSort(array1, 0, arr_size1 - 1);
  const end1 = performance.now(); 

  const start2 = performance.now(); 
  mergeSort(array2, 0, arr_size2 - 1);
  const end2 = performance.now(); 

  const start3 = performance.now(); 
  mergeSort(array3, 0, arr_size3 - 1);
  const end3 = performance.now(); 

  const start4 = performance.now(); 
  mergeSort(array4, 0, arr_size4 - 1);
  const end4 = performance.now(); 

  const start5 = performance.now(); 
  mergeSort(array5, 0, arr_size5 - 1);
  const end5 = performance.now(); 

  console.log(`Time executation1: ${end1 - start1} milissegundos`);
  console.log(`Time executation2: ${end2 - start2} milissegundos`);
  console.log(`Time executation3: ${end3 - start3} milissegundos`);
  console.log(`Time executation4: ${end4 - start4} milissegundos`);
  console.log(`Time executation5: ${end5 - start5} milissegundos`);

