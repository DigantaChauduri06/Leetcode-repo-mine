function Merge(array: number[], low: number, mid: number, high: number) {
  // const arr1 = array.slice(low, mid); // [1,3,4,6]
  // const arr2 = array.slice(mid); // [2,4,6,4,9]
    const s1 = mid - low + 1, s2 = high - mid;
    const arr1 =  new Array(s1)
    const arr2 =  new Array(s2)
    for (let i = 0;i < s1;i+=1) {
        arr1[i] = array[i+low]
    }
    for (let i = 0;i < s2;i+=1) {
        arr2[i] = array[i+mid+1]
    }
  let i = 0,
    j = 0,
    k = low;
  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) {
      array[k] = arr1[i];
      i += 1;
      k += 1;
    } else {
      array[k] = arr2[j];
      j += 1;
      k += 1;
    }
  }
  while (i < arr1.length) {
    array[k] = arr1[i];
    i += 1;
    k += 1;
  }

  while (j < arr2.length) {
    array[k] = arr2[j];
    j += 1;
    k += 1;
  }
}

function MergeSortHelper(array: number[], low: number, high: number) {
  if (low >= high) return;
  let mid = low + Math.floor((high - low) / 2);
  MergeSortHelper(array, low, mid);
  MergeSortHelper(array, mid + 1, high);
  Merge(array, low, mid, high);
}
function sortArray(nums: number[]): number[] {
    MergeSortHelper(nums, 0, nums.length-1)
    return nums
};