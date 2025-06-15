#include <iostream>

using namespace std;

int main(){
  int N;
  cout << "Enter the number of rows for the triangle : ";
  cin >> N;

  int** Triangle = new int*[N];

  for(int i = 0; i < N; i++){
    Triangle[i] = new int[i + 1];
  }

  for(int i = 0; i < N; i++){
    int column = 0;
    int value = 0;

    cin >> column >> value;

    for(int j = 0; j < i + 1; j++){
      Triangle[i][j] = 10000; // Initialize the triangle with a large value
    }

    // Assign the value to the specified column in the current row 
    if (column < 0 || column >= i + 1){
      cout << "Column index out of bounds." << endl;
      return 0;
    }

    Triangle[i][column] = value;
  }

  // Print the triangle 
  cout << "The original triangle is: " << endl;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < i + 1; j++){
      cout << Triangle[i][j] << " ";
    }
    cout << endl;
  }

  // Fill the triangle with the sum of the two adjacent numbers below
  bool impossibleToCalculate = true;
  int count = 0;
  while(impossibleToCalculate){
    count++;
    for(int i = 0; i < N - 1; i++){
      for(int j = 0; j < i + 1; j++){
        if(Triangle[i][j] == 10000) continue; // Skip if the current cell is still 10000

        if(Triangle[i + 1][j] == 10000 && Triangle[i + 1][j + 1] != 10000){
          Triangle[i + 1][j] = Triangle[i][j] - Triangle[i + 1][j + 1];
        }else if(Triangle[i + 1][j + 1] == 10000 && Triangle[i + 1][j] != 10000){
          Triangle[i + 1][j + 1] = Triangle[i][j] - Triangle[i + 1][j];
        }
      }
    }

    // Check if any value is still 10000
    for(int i = 0; i < N; i++){
      for(int j = 0; j < i + 1; j++){
        if(Triangle[i][j] == 10000){
          impossibleToCalculate = true;
          break;
        }else{
          impossibleToCalculate = false;
        }
      }
    }
  }

  // Print the filled triangle 
  for (int i = 0; i < N; i++){
    for(int j = 0; j < i + 1; j++){
      cout << Triangle[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
