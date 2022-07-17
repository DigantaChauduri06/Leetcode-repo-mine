function InsertionSort(array: number[]) {
  for (let i = 0; i < array.length; i++) {
    let key = array[i];
    let j = i - 1;
    for (j; j >= 0 && (array[j] > key); j -= 1) {
        array[j+1] = array[j];
    }
     array[j+1] = key;
  }
}
function sortArray(nums: number[]): number[] {
    InsertionSort(nums)
    return nums
};