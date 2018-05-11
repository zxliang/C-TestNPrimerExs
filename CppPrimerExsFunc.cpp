// functions to C++ Primer exercise solutions
#include "CppPrimerHeader.h"
#include "Sales_item.h"

// Exercise 1.10
void ex1_10()
{
  int l=10;
  while (l >= 0)  {
    cout << l << " ";
    --l;
  }
  cout << endl;
}

// Exercise 1.11
void PrintIntLowHigh(int lo, int hi)
{
  if (lo >= hi)
  {
    PrintIntLowHigh(hi, lo);
    return;
  }
  for (int i=lo; i<=hi; i++)
    cout << i << " ";

  cout << endl;
  return;
}

void ex1_11()
{
  cout << "Please enter two integers: " << endl;
  int a=0, b=0;
  cin >> a >> b ;
  PrintIntLowHigh(a, b);
}

// Exercise 1.16
void ex1_16()
{
  int sum = 0, value = 0;
  for (int value; cin >> value; sum += value);
  cout << "Sum is: " << sum << endl;
  return;
}

// Exercise 1.20
void ex1_20()
{
  for(Sales_item item; cin >> item; cout << item << endl);
  return;
}

// Exercise 1.21
void ex1_21()
{
  Sales_item item1, item2;
  cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    cout << item1 + item2 << endl;
  } else
    cerr << "Different ISBN number" << endl;
  return;
}

// Exercise 1.22()
int ex1_22()
{
  Sales_item total;
  if (cin >> total) {
    Sales_item trans;
    while (cin >> trans) {
      if (total.isbn() == trans.isbn())
        total += trans;
      else {
        cout << total << endl;
		total = trans;
      }
    }
    cout << total << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}

// Exercise 1.23
void ex1_23()
{
  Sales_item curItem, preItem;
  if (cin >> preItem) {
	int cnt = 1;
	while (cin >> curItem) {
	  if (curItem.isbn() == preItem.isbn()) {
		cnt++;
	  } else {
		cout << preItem.isbn() << " occur: " << cnt << " times." << endl;
		preItem = curItem;
		cnt = 1;
	  }
	}
	cout << preItem.isbn() << " occur: " << cnt << " times." << endl;
  }

}

// Exercise 1.25
int ex1_25()
{
  Sales_item total;
  if (cin >> total) {
	Sales_item trans;
	while (cin >> trans) {
	  if (total.isbn() == trans.isbn())
		total += trans;
	  else {
		cout << total << endl;
		total = trans;
	  }
	}
	cout << total << endl;
  }
  else {
	cerr << "No data?!" << endl;
	return -1;
  }
}