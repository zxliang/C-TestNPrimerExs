// testing c++ property
#include "CppPrimerHeader.h"

void test1()
{
  int sum = 0, value = 0;
  while (cin >> value)
    sum += value;
  cout << "Sum is: " << sum << endl;
  return;
}

// 1.4.4
void test2()
{
    // currVal is the number we're counting; we'll read new values into val
    int currVal = 0, val = 0;
    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;  // store the count for the current value we're processing
        while (std::cin >> val) { // read the remaining numbers
            if (val == currVal)   // if the values are the same
                ++cnt;            // add 1 to cnt
            else { // otherwise, print the count for the previous value
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;    // remember the new value
                cnt = 1;          // reset the counter
            }
        }  // while loop ends here
        // remember to print the count for the last value in the file
        std::cout << currVal <<  " occurs "
                  << cnt << " times" << std::endl;
    } // outermost if statement ends here
    return;
}

void test3()
{
  unordered_map<std::string,std::string> mymap;
  mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

  cout << "mymap contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    cout << " " << it->first << ":" << it->second;
  cout << endl;

  unordered_map<int,int> container1;
  container1[10] = 10;
  container1[9]++;
  container1[8]--;
  for (auto& x: container1) cout << "" << x.first << ":" << x.second << endl;
}

void test4()
{
  int i, n;
  int *p;
  cout << "# of numbers to be typed: " << endl;
  cin >> n;
  p = new (nothrow) int[n];
  if (p == nullptr)
	cout << "Error: memory could not be allocated!" << endl;
  else {
	for (i = 0; i < n; i++) {
	  cout << "Enter number: ";
	  // cin >> *(p + i);
	  cin >> p[i];
	}
	cout << "You have entered: ";
	for (i = 0; i < n; i++) {
	  // cout << *(p + i) << ", ";
	  cout << p[i] << ", ";
	}
	delete[] p;
  }
}
