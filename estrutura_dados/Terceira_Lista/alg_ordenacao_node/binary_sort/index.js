import {performance} from 'perf_hooks'
import {generateArrays} from '../utils/gerador_array.js'

function binarySearch(a, item, low, high) {
    if (high <= low)
      return item > a[low] ? low + 1 : low;
  
    const mid = Math.floor((low + high) / 2);
  
    if (item === a[mid])
      return mid + 1;
  
    if (item > a[mid])
      return binarySearch(a, item, mid + 1, high);
  
    return binarySearch(a, item, low, mid - 1);
  }
  
  function binarySort(a) {
    const n = a.length;
  
    for (let i = 1; i < n; ++i) {
      let j = i - 1;
      const selected = a[i];
      const loc = binarySearch(a, selected, 0, j);
  
      while (j >= loc) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = selected;
    }
  }
  
  const array1 = generateArrays([101]);
  const array2= generateArrays([1001]);
  const array3 = generateArrays([10001]);
  const array4 = generateArrays([100001]);
  const array5 = generateArrays([10000001]);
  console.log(array5)
  const start1 = performance.now(); 
  binarySort(array1);
  const end1 = performance.now(); 

  const start2 = performance.now(); 
  binarySort(array2);
  const end2 = performance.now(); 

  const start3 = performance.now(); 
  binarySort(array3);
  const end3 = performance.now(); 

  const start4 = performance.now(); 
  binarySort(array4);
  const end4 = performance.now(); 

  const start5 = performance.now(); 
  binarySort(array5);
  const end5 = performance.now(); 

  console.log(`Time executation1: ${end1 - start1} milissegundos`);
  console.log(`Time executation2: ${end2 - start2} milissegundos`);
  console.log(`Time executation3: ${end3 - start3} milissegundos`);
  console.log(`Time executation4: ${end4 - start4} milissegundos`);
  console.log(`Time executation5: ${end5 - start5} milissegundos`);