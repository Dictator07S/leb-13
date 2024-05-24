//
// Created by Dictator07S on 5/24/2024.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
using namespace std;
struct Node {
 double data;
 Node* next;
};
Node* insert(Node* head, double data) {
 Node* newNode = new Node;
 newNode->data = data;
 newNode->next = head;
 return newNode;
}
void printList(Node* head) {
 while (head != nullptr) {
 cout << head->data << " ";
 head = head->next;
 }
 cout << endl;
}
Node* merge(Node* head1, Node* head2) {
 Node* mergedHead = nullptr;
 if (head1 == nullptr) return head2;
 if (head2 == nullptr) return head1;
 while (head1 && head2) {
 if (head1->data <= head2->data) {
 mergedHead = insert(mergedHead, head1->data);
 head1 = head1->next;
 } else {
 mergedHead = insert(mergedHead, head2->data);
 head2 = head2->next;
 }
 }
 mergedHead = insert(mergedHead, head1 ? head1->data : head2->data);
 return mergedHead;
}
int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
 std::queue<int> studentQueue;
 std::stack<int> sandwichStack;
 // Initialize the queue and stack
 for (int student : students) {
 studentQueue.push(student);
 }
 for (int sandwich : sandwiches) {
 sandwichStack.push(sandwich);
 }
 // Process sandwiches until all students are served or no more sandwiches left
 while (!studentQueue.empty() && !sandwichStack.empty()) {
 int currentStudent = studentQueue.front();
 int topSandwich = sandwichStack.top();
 if (currentStudent == topSandwich) {
 studentQueue.pop();
 sandwichStack.pop();
 } else {
 studentQueue.pop();
 studentQueue.push(currentStudent);
 }
 }
 // Return the number of students who couldn't eat
 return studentQueue.size();
}
int removeAndCount(std::vector<int>& nums, int val) {
 int count = 0;
 int replacement = -1; // Value to replace removed elements
 for (int& num : nums) {
 if (num == val) {
 num = replacement;
 } else {
 count++;
 }
 }
 return count;
}
void cleanNumbers(std::vector<std::string>& vec) {
 std::vector<std::string> result;
 for (const std::string& word : vec) {
 bool containsDigit = false;
 for (char c : word) {
 if (std::isdigit(c)) {
 containsDigit = true;
 break;
 }
 }
 if (!containsDigit) {
 result.push_back(word);
 }
 }
 vec = result; // Replace the original vector with the cleaned one
}
int main() {
 std::cout <<"Problem_1"<< std::endl;
 std::vector<double> vec;
 vec.push_back(3.14);
 vec.push_back(2.718);
 vec.push_back(1.618);
 std::cout << "Printing vector elements using iterators:\n";
 for (auto it = vec.begin(); it != vec.end(); ++it) {
 std::cout << *it << " ";
 }
 std::cout << std::endl;
 std::cout<< "Problem_2"<<std:: endl;
 std::vector<double> vec_2;
 double input;
 std::cout << "Enter elements (separate by spaces, type 'q' to quit): ";
 // Read elements until 'q' is entered
 while (std::cin >> input) {
 vec_2.push_back(input);
 }
 if (vec.empty()) {
 std::cout << "Vector is empty. No elements to print.\n";
 } else {
 // Print the first and last elements
 std::cout << std::fixed << std::setprecision(2) << vec_2.front() << " " <<
vec_2.back() << std::endl;
 }
 std::cout << "Problem_3"<< std:: endl;
 std::vector<int> vec_3;
 vec_3.assign({1, 2, 3, 4, 5, 6, 7, 8});
 if (!vec_3.empty()) {
 vec_3.erase(vec_3.begin() + 3);
 vec_3.erase(vec_3.begin() + 1, vec_3.begin() + 3);
 std::cout << "Updated vector: ";
 for (int num : vec_3) {
 std::cout << num << " ";
 }
 std::cout << std::endl;
 } else {
 std::cout << "Vector is empty." << std::endl;
 }
 std::cout<<"Problem_4"<< std::endl;
 int n;
 std::cout << "Enter the size of the square matrix (n x n): ";
 std::cin >> n;
 std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0.0));
 std::cout << "Enter " << n * n << " elements for the matrix: ";
 auto it = matrix.begin();
 for (; it != matrix.end(); ++it) {
 auto inner_it = it->begin();
 for (; inner_it != it->end(); ++inner_it) {
 std::cin >> *inner_it;
 }
 }
 std::cout << "Output:" << std::endl;
 for (const auto& row : matrix) {
 for (const auto& element : row) {
 std::cout << element << " ";
 }
 std::cout << std::endl;
 }
 std::cout<<"Problem_5"<<std::endl;
 // Create the three linked lists
 Node* head1 = nullptr;
 head1 = insert(head1, 6.7);
 head1 = insert(head1, 4.5);
 head1 = insert(head1, 3.3);
 Node* head2 = nullptr;
 head2 = insert(head2, 3);
 head2 = insert(head2, 2);
 head2 = insert(head2, 1);
 Node* head3 = nullptr;
 head3 = insert(head3, 10.3);
 head3 = insert(head3, 9.5);
 head3 = insert(head3, 8);
 // Merge the three lists
 Node* mergedHead = merge(merge(head1, head2), head3);
 // Print the merged list
 cout << "Merged list: ";
 printList(mergedHead);
 cout<< "Problem_6"<< endl;
 // 1.
 forward_list<int> myList;
 cout << "Initial list: ";
 for (int value : myList) {
 cout << value << " ";
 }
 cout << endl;
 // 2
 try {
 auto it = myList.begin();
 ++it; // Attempt to move to the second element (which doesn't exist)
 myList.erase_after(it);
 cout << "After erase_after (empty list): ";
 } catch (const out_of_range& e) {
 cerr << "Error: " << e.what() << endl;
 }
 for (int value : myList) {
 cout << value << " ";
 }
 cout << endl;
 // 3
 myList.push_front(5);
 cout << "After push_front(5): ";
 for (int value : myList) {
 cout << value << " ";
 }
 cout << endl;
 // 4.
 myList.emplace_front(2);
 cout << "After emplace_front(2): ";
 for (int value : myList) {
 cout << value << " ";
 }
 cout << endl;
 // 5
 myList.pop_front();
 cout << "After pop_front(): ";
 for (int value : myList) {
 cout << value << " ";
 }
 cout << endl;
 // 7. Insert a value using emplace_after() (requires an iterator)
 myList.insert_after(myList.end(), 7); // Insert 7 at the end
 cout << "After insert_after(end(), 7): ";
 for (int value : myList) {
 cout << value << " ";
 }
 cout <<"Problem_7"<< endl;
 // 1
 std::deque<int> myDeque;
 // 2
 myDeque.push_back(5);
 // 3
 myDeque.push_front(7);
 // 4. Insert a value 10 from the end - push_back()
 myDeque.push_back(10);
 // 5
 myDeque.push_front(20);
 // 6
 std::cout << "Elements in deque: ";
 for (int num : myDeque) {
 std::cout << num << " ";
 }
 std::cout << std::endl;
 // 7
 std::cout << "Size of deque: " << myDeque.size() << std::endl;
// 8
 if (myDeque.size() >= 3) {
 std::cout << "Third element of deque: " << myDeque[2] << std::endl;
 } else {
 std::cout << "Deque doesn't have a third element." << std::endl;
 }
// 9
 if (!myDeque.empty()) {
 std::cout << "First element of deque: " << myDeque.front() << std::endl;
 std::cout << "Last element of deque: " << myDeque.back() << std::endl;
 } else {
 std::cout << "Deque is empty." << std::endl;
 }
// 10
 if (!myDeque.empty()) {
 myDeque.pop_front();
 myDeque.pop_back();
 std::cout << "Elements in deque after deletion: ";
 for (int num : myDeque) {
 std::cout << num << " ";
 }
 std::cout << std::endl;
 } else {
 std::cout << "Deque is empty after deletion." << std::endl;
 }
 cout<<"Problem_8"<< endl;
 std::vector<int> students = {1, 1, 0, 0};
 std::vector<int> sandwiches = {0, 1, 0, 1};
 int result = countStudents(students, sandwiches);
 std::cout << "Output: " << result << std::endl;
 cout << "Problem_9"<<endl;
 int n_1, val;
 std::cout << "Enter the number of elements in the vector: ";
 std::cin >> n;
 std::vector<int> nums(n_1);
 std::cout << "Enter the elements of the vector: ";
 for (int i = 0; i < n_1; ++i) {
 std::cin >> nums[i];
 }
 std::cout << "Enter the value to remove: ";
 std::cin >> val;
 int remaining = removeAndCount(nums, val);
 std::cout << "Output: ";
 for (int num : nums) {
 if (num != -1) {
 std::cout << num << " ";
 }
 }
 std::cout << std::endl;
 std::cout << "Number of elements remaining: " << remaining << std::endl;
 cout <<"Problem_10" <<endl;
 int n_2;
 std::cout << "Enter the number of words: ";
 std::cin >> n_2;
 std::vector<std::string> words(n_2);
 std::cout << "Enter the words: ";
 for (int i = 0; i < n_2; ++i) {
 std::cin >> words[i];
 }
 cleanNumbers(words);
 std::cout << "Output: ";
 for (const std::string& word : words) {
 std::cout << word << " ";
 }
 std::cout << std::endl;
 return 0;
}