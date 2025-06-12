# 🔍 Binary Search Analyzer (C++)

A console C++ application that runs statistical tests on **binary search** using randomly generated sorted arrays. It calculates the **average number of comparisons** needed to find elements and writes the results to a file.

## 🚀 Features

- Performs binary search on sorted unique arrays
- Measures average comparisons over 1000 trials per array size
- Outputs data to `binarysearch.dat` for graphing/analysis
- Includes basic bubble sort and data generation

## 💡 Concepts Used

- Binary search algorithm
- Bubble sort
- Array manipulation
- Random number generation
- File output for analysis
- Algorithm performance evaluation

## 📂 Project Structure

📁 binary-search-analyzer/

  └── main.cpp # Main program file

## 📊 Output Example

Data is saved in this format:  
10 3.212  
20 4.998  
...

You can plot this using tools like Python (matplotlib), Excel, or Gnuplot.

## 🛠️ How to Run

1. Compile the program:
```bash
g++ main.cpp -o analyzer
./analyzer
```
2. Results will be saved in binarysearch.dat.

## 👤 Author
**Mark Viediernikov**  
Computer Science Student
