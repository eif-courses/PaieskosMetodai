#include <iostream>
#include <vector>
#include <algorithm>


int linearSearch(std::vector<int> &numbers, int searchKey){
  int index = 0;
  for(int n: numbers){
    if(n == searchKey){
      return index;
    }
    index++;
  }
  return -1;
}



int binarySearch(std::vector<int> &numbers, int left, int right, int searchKey){
  // 0 .. numbers.size()-1

  std::sort(numbers.begin(), numbers.end());

  while(left <= right){
    int middle = left + (right - left) / 2;
    if(numbers[middle] == searchKey){
      return middle;
    }
    if(numbers[middle] < searchKey){
      left = middle + 1;
    }else{
      right = middle - 1;
    }
  }
  return -1;
}


int main() {

  std::vector<int> numbers = {82, 58, 45, 112, 554, 15, 1549, 66, 99 , 5454};

  int result = linearSearch(numbers, 1);

  if(result != -1)
    std::cout <<"Indeksas kur rasta: "<< result << "skaicius: " << numbers[result]<< std::endl;
  else{
    std::cout <<"Nepavyko rasti ";
  }

  int binarySearchResult = binarySearch(numbers, 0, numbers.size() -1, 99);

  for(int i: numbers){
    std::cout << i << " ";
  }


  if(binarySearchResult != -1)
    std::cout <<"Indeksas kur rasta: "<< binarySearchResult << "skaicius: " << numbers[binarySearchResult]<< std::endl;
  else{
    std::cout <<"Nepavyko rasti ";
  }




  return 0;
}
