#include <vector>
#include <iostream>
#include <string>
#include "Vector.h"

using std::cout;
using std::vector;
using std::string;

struct Node {
	int data;
	Node *next;
};
template <typename T>
void print1DVector(T &nums) {
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
void testing() {
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
	nums.resize(8, 69);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";
	print1DVector(nums);

	vector<string>words;
	cout << "String vector\n";
	words.resize(5, ";-)");
	print1DStringVector(words);

	vector<Node>nodes;
	cout << "Node vector\n";
	nodes.resize(5);
	cout << nodes.at(1).next << "\n";
}
void testing2() {
	/*
	Vector<string>nums1;
	nums1.pushBack("3");
	nums1.pushBack("15");
	nums1.pushBack("7");
	cout << "//////////////nums1//////////////\n";
	for (size_t i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << ", ";
	cout << "\n";
	//cout << "size=" << nums1.size() << "\n";
	//cout << "capacity=" << nums1.capacity() << "\n";
	nums1.clear();
	for (size_t i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << ", ";
	cout << "\n";
	Vector<int>temp(15,100);
	for (size_t i = 0; i < temp.size(); ++i)
		cout << temp[i] << ", ";
	cout << "\n";
	cout << "size=" << temp.size() << "\n";
	cout << "capacity=" << temp.capacity() << "\n";*/
	/*	
	Vector<int>nums2;
	nums2.pushBack(10);
	nums2.pushBack(50);
	nums2.pushBack(38);
	cout << "//////////////nums2//////////////\n";
	for (size_t i = 0; i < nums2.size(); ++i)
		cout << nums2[i] << ", ";
	cout << "\n";
	cout << "//////////////swap//////////////\n";
	nums1.swap(nums2);
	cout << "//////////////nums1//////////////\n";
	for (size_t i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << ", ";
	cout << "\n";

	cout << "//////////////nums2//////////////\n";
	for (size_t i = 0; i < nums2.size(); ++i)
		cout << nums2[i] << ", ";
	cout << "\n";

	vector<int>temp;
	temp.push_back(51);
	temp.push_back(8);
	cout << "size=" << temp.size() << "\n";
	cout << "capacity=" << temp.capacity() << "\n";
	temp.reserve(1000);
	temp.clear();
	cout << "size=" << temp.size() << "\n";
	cout << "capacity=" << temp.capacity() << "\n";*/
	/*
	vector<int>nums;
	nums.push_back(3);
	nums.push_back(18);
	nums.push_back(7);
	print1DVector(nums);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";
	nums.assign(2, 100);
	print1DVector(nums);
	cout << "size=" << nums.size() << "\n";
	cout << "capacity=" << nums.capacity() << "\n\n";

	Vector<int>nums2;
	nums2.pushBack(3);
	nums2.pushBack(18);
	nums2.pushBack(7);
	for (size_t i = 0; i < nums2.size(); ++i)
		cout << nums2[i] << ", ";
	cout << "\n";
	//print1DVector(nums);
	cout << "size=" << nums2.size() << "\n";
	cout << "capacity=" << nums2.capacity() << "\n\n";
	nums2.assign(2, 100);
	//print1DVector(nums);
	for (size_t i = 0; i < nums2.size(); ++i)
		cout << nums2[i] << ", ";
	cout << "\n";
	cout << "size=" << nums2.size() << "\n";
	cout << "capacity=" << nums2.capacity() << "\n\n";*/
	
}
void testingIterators() {
	Vector<int>nums;
	nums.pushBack(10);
	nums.pushBack(3);
	nums.pushBack(8);
	nums.pushBack(1);
	nums.pushBack(16);

	for (Vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
		cout << *it << ", ";
	cout << "\n";

	for (Vector<int>::reverseConstIterator it = nums.crbegin(); it != nums.crend(); ++it)
		cout << *it << ", ";
	cout << "\n";

	cout <<"nums.front()=" << nums.front() << "\n";
	cout << "nums.back()=" << nums.back() << "\n";
	cout << "nums.at(2)=" << nums.at(2) << "\n";
	cout << "nums[2]=" << nums[2] << "\n";
	cout << "nums.empty()=" << nums.empty() << "\n";
	cout << "nums.capacity()=" << nums.capacity() << "\n";
	cout << "nums.size()=" << nums.size() << "\n";
	cout << "nums.assign(3,100)=\n";
	nums.assign(3, 100);
	cout << "Start Printing 1D Vector\n";
	for (auto num : nums)
		cout << num << ", ";
	cout << "\n";
	cout << "End Printing 1D Vector\n";
	cout << "nums.capacity()=" << nums.capacity() << "\n";
	cout << "nums.size()=" << nums.size() << "\n";
}
Vector<int> dummy() {
	Vector<int>temp;
	temp.pushBack(2);
	return temp;
}
void testingMoveSemantics() {
	//Vector<int>nums1 = dummy();
	//nums1 = dummy();
	Vector<int>nums1;
	Vector<int>nums2;
	nums1 = nums2;
}
void testingIterators2() {
	Vector<int>nums1;
	nums1.pushBack(52);
	nums1.pushBack(7);
	nums1.pushBack(32);
	nums1.pushBack(17);
	nums1.pushBack(84);
	print1DVector(nums1);

	Vector<int>nums2;
	auto start = nums1.begin()+2;
	auto end = nums1.end()-1;
	try {
		nums2.assign(start, end);
	}
	catch (std::out_of_range e) {
		cout << e.what() << "\n";
	}
	print1DVector(nums2);
}
//argc = argument count | argv =  argument vector
//argc is the number of string pointed to by argv
int main(int argc, char **argv) {
	//Vector<int>nums;
	//nums.pushBack(2);
	//nums.pushBack(5);
	//cout << nums.size() << "\n";

	//Vector<int>nums2(Vector<int>(2, 5));
	//nums2 = Vector<int>(2, 5);
	//cout << nums.size() << "\n";
	testingIterators2();

	return 0;
}