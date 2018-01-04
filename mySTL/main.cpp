#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::vector;
using std::string;

void print1DVector(const vector<int> &nums) {
	cout << "Start Printing 1D Vector\n";
	for (auto num : nums)
		cout << num << ", ";
	cout << "\n";
	cout << "End Printing 1D Vector\n";
}
void print1DStringVector(const vector<string> &words) {
	cout << "Start Printing 1D String Vector\n";
	for (auto word : words)
		cout << word << ", ";
	cout << "\n";
	cout << "End Printing 1D String Vector\n";
}
//argc = argument count | argv =  argument vector
//argc is the number of string pointed to by argv
int main(int argc, char **argv) {
	vector<int> nums;
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";

	cout << "after modifying capacity\n";
	nums.reserve(5);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";
	print1DVector(nums);

	cout << "after adding elements\n";
	nums.push_back(3);
	nums.push_back(6);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";
	print1DVector(nums);

	cout << "after modifying size\n";
	nums.resize(8,69);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";
	print1DVector(nums);

	vector<string>words;
	cout << "String vector\n";
	words.resize(5,";-)");
	print1DStringVector(words);
	return 0;
}