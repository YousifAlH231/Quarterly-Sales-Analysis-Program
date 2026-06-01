

#include <iostream>

#include <iomanip>

using namespace std;

const int ROWS = 4;

const int COLS = 3;

void calculateQuarterlyAverages(double data[ROWS][COLS]);

void printMenu();

void findYearlyMaxMinSales(double data[ROWS][COLS], double& maxSales, double& minSales);

void calculateYearlyAverage(double data[ROWS][COLS]);

void printArray(double data[ROWS][COLS]);



int main()

{

  double salesData[ROWS][COLS] = {0};

  double maxSales, minSales;

  while (true) {

    printMenu();

    int choice;

    cout << "Enter your choice: ";

    cin >> choice;

     

    switch (choice) {

      case 1: {

        cout << "Enter quarterly sales data:" << endl;

        for (int i = 0; i < ROWS; i++) {

          cout << "Quarter " << i + 1 << ":" << endl;

          for (int j = 0; j < COLS; j++) {

            cout << "Enter sales for month " << j + 1 << ": ";

            cin >> salesData[i][j];

          }

        }

        break;

      }

      case 2: {

        calculateQuarterlyAverages(salesData);

        break;

      }

      case 3: {

        calculateYearlyAverage(salesData);

        break;

      }

      case 4: {

        findYearlyMaxMinSales(salesData, maxSales, minSales);

        cout << "Maximum sales in the year: " << maxSales << endl;

        cout << "Minimum sales in the year: " << minSales << endl;

        break;

      }

      case 5: {

        printArray(salesData);

        break;

      }

      case 6: {

        cout << "Exiting program." << endl;

        return 0;

      }

      default:

        cout << "Invalid choice. Please enter a number between 1 and 6." << endl;

    }

  }

  return 0;

}



void printMenu(){

  cout<<"Menu:" << endl;

  cout<<"1. Enter quarterly sales data " << endl;

  cout<<"2. Calculate quarterly averages " << endl;

  cout<<"3. Calculate yearly averages " << endl;

  cout<<"4. Find yearly maximum and minimum sales " << endl;

  cout<<"5. Print sales data " << endl;

  cout<<"6. Exit \n";

}

void calculateQuarterlyAverages(double data[ROWS][COLS]){

  cout<<"Quarterly averages: ";

  for(int i = 0 ; i < ROWS ; i++){

    float value = 0 ;

    for(int j = 0 ; j < COLS ; j++){

      value = value + data[i][j];

    }

    double avg = value / COLS;

    cout<< fixed << setprecision(2) << avg << " ";

  }

  cout<<endl;

}

void calculateYearlyAverage(double data[ROWS][COLS]){

  cout<<"Yearly average: ";

  double result = 0;

  for( int i = 0 ; i < ROWS ; i++){

    for(int j = 0 ; j < COLS ; j++){

      result = result + data[i][j];

    }

  }

  double totalyear = result / (ROWS*COLS);

  cout<< totalyear << endl;

}

void findYearlyMaxMinSales(double data[ROWS][COLS], double& maxSales, double& minSales){

  maxSales = data[0][0];

  minSales = data[0][0];

  for( int i = 0 ; i < ROWS ; i++){

    for( int j = 0 ; j < COLS ; j++){

      if(maxSales < data[i][j]){

        maxSales = data[i][j];

      }

      if(minSales > data[i][j]){

        minSales = data[i][j];

      }

    }

  }

}

void printArray(double data[ROWS][COLS]){

  cout<<"Sales data: ";

  cout<< fixed << setprecision(0);

  for(int i = 0 ; i < ROWS ; i++){

    cout<<"\nQuarter " << i + 1 <<": ";

    for(int j = 0 ; j < COLS ; j++){

      cout<< setw(6) << data[i][j];

    }

  }

  cout<<endl;

}

