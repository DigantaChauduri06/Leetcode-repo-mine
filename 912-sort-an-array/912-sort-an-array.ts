function SelectionSort(array: number[]) {
  for (let i = 0; i < array.length; i++) {
    let swappedIdx = i;
    let minIdx = i;
    let minVal = array[i];
    for (let j = i + 1; j < array.length; j++) {
      if (minVal > array[j]) {
        minVal = array[j];
        minIdx = j;
      }
    }
    let tmp = array[swappedIdx]
    array[swappedIdx] = array[minIdx]
    array[minIdx] = tmp
  }
}
function sortArray(nums: number[]): number[] {
    SelectionSort(nums)
    return nums
};