#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main(int argc, char** argv)
{
if (argc <= 2) return 1;
double* nums = new double[max(argc - 2, 0)];
bool forward = true;
int count = 0;
double temp;
for (size_t i = 1; i < argc; i++)
{
if (*argv[i] == 'f')
forward = true;
else if (*argv[i] == 'b')
forward = false;
if (isdigit(*argv[i]))
nums[count++] = std::stoi(argv[i]);
}
for (size_t i = 0; i < count - 1; i++)
for (size_t j = 0; j < count - i - 1; j++)
if (((forward) && (nums[j] > nums[j + 1])) || ((!forward) && (nums[j] < nums[j + 1])))
{
temp = nums[j];
nums[j] = nums[j + 1];
nums[j + 1] = temp;
}
for (int i = 0; i < count; i++)
cout << nums[i] << endl;
delete [] nums;
}
