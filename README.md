# LinkedListSet
# Description
This project is an implementation of a set using a singly linked list in C++. It supports basic set operations such as insertion, deletion, union, difference, and intersection. The set is represented by the LinkedListSet class, which manages nodes containing integer values.

# Instructions

# Inputs
The operations performed on the LinkedListSet are:

Insertion of elements.
Deletion of elements.
Set union with another LinkedListSet.
Set difference with another LinkedListSet.
Set intersection with another LinkedListSet.

# Functions
LinkedListSet(): Constructor that initializes an empty set.
operator+=: Performs the union of two sets.
operator-: Deletes a value from the set.
operator+: Inserts a value into the set.
operator-=: Performs the difference between two sets.
operator&=: Performs the intersection between two sets.
display(): Displays the set.
doesContains(): Checks if a value is present in the set.
# Example Usage
int main() {
    // Example usage
    LinkedListSet set1;
    set1 + 1 + 2 + 3 + 17; // Insertion
    set1.display(); // Output: LinkedListSet{1, 2, 3, 17, }

    set1 - 2; // Deletion --> {1,3,17}
    set1.display(); // Output: LinkedListSet{1, 3, 17, }

    LinkedListSet set2;
    set2 + 3 + 4 + 5;
    set2.display(); // Output: LinkedListSet{3, 4, 5, }

    set2 += set1 + 7 + 3 + 19; // Insertion with multiple right-hand values
    set2.display(); // Output: LinkedListSet{1, 3, 4, 5, 7, 17, 19, }

    LinkedListSet set3;
    set3 + 3 + 4 + 7 + 17 + 41;
    set3.display(); // Output: LinkedListSet{3, 4, 7, 17, 41, }

    LinkedListSet set4;
    set4 + 41 + 37 + 7 + 19 + 41;
    set4.display(); // Output: LinkedListSet{7, 19, 37, 41, }

    // Set Union
    set1 += set2;
    set1.display(); // Output: LinkedListSet{1, 3, 4, 5, 7, 17, 19, }

    // Set Difference
    set1 -= set3;
    set1.display(); // Output: LinkedListSet{1, 5, 19, }

    // Set Intersection
    set1 &= set4;
    set1.display(); // Output: LinkedListSet{19, }

    return 0;
}
# Files
bartu.arslan.cpp: Contains the implementation of the LinkedListSet class and the main function.
# How to Run
1. Ensure you have a C++ compiler installed (e.g., g++, Visual Studio, XCode).
2. Compile the code:
   g++ bartu.arslan.cpp -o LinkedListSet
3. Run the compiled program:
   ./LinkedListSet

# Author
Yağız Bartu Arslan
Junior Computer Engineering Student at Sabanci University

# Date
17.12.2023
