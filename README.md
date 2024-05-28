# Push-swap Project

![](https://repository-images.githubusercontent.com/755983679/82abacf9-c49d-42fc-a0a9-2c0a12394896)

# Introduction

The Push-swap project is a programming challenge from the Common Core curriculum of the 42 Network, an innovative and renowned coding school with campuses around the world. This project is designed to test students' problem-solving skills, algorithmic thinking, and proficiency in C programming. 


# Project Overview

Here's an overview of what the Push_swap project typically involves:

### Objective

The goal of the Push_swap project is to sort a stack of integers using a limited set of operations. Students need to create two programs:

  * **Mandatory - Push_swap:** This program generates a sequence of operations to sort a stack of integers.
  * **Bonus - Checker:** This program checks if a given sequence of operations successfully sorts the stack.

### Stacks and Operations

The project deals with two stacks named **a** and **b**. Initially, all integers are placed in stack a, and stack b is empty. 
The allowed operations to manipulate these stacks are:

```bash
* sa: Swap the first two elements at the top of stack a.
* sb: Swap the first two elements at the top of stack b.
* ss: sa and sb at the same time.
```
```bash
* pa: Take the first element at the top of b and put it at the top of a.
* pb: Take the first element at the top of a and put it at the top of b.
```
```bash
* ra: Rotate all elements of stack a one position up.
* rb: Rotate all elements of stack b one position up.
* rr: ra and rb at the same time.
```
```bash
* rra: Rotate all elements of stack a one position down.
* rrb: Rotate all elements of stack b one position down.
* rrr: rra and rrb at the same time.
```

### Implementation Details

  * Push_swap program: This program takes the unsorted integers as input and outputs a sequence of operations that will sort the integers in ascending order when applied to stack a.
  * Checker program: This program takes the unsorted integers and a sequence of operations as input. It applies the operations to the integers and checks whether they result in a sorted stack.

### Compilation and Execution

```bash
git clone https://github.com/lassachraf/42_Push-swap.git
```
```bash
cd 42_Phush-swap
```
* For mandatory :
``` bash
make
```
``` bash
./push_swap [list of numbers]
```
* For bonus :
``` bash
make bonus
```
``` bash
./checker [list of numbers]
```

### Evaluation Criteria

  * **Correctness:** The sequence of operations must correctly sort the stack.
  * **Efficiency:** The number of operations used to sort the stack should be minimized. This is crucial for achieving a higher score.
  * **Code Quality:** Adherence to the 42 Network's coding standards and best practices is also evaluated.

### Challenges:

  * Limited Operations: The primary challenge is to sort using a very limited set of operations efficiently.
  * Optimization: Finding the minimal number of operations requires a deep understanding of algorithms and problem-solving skills.

# Learning Outcomes

  * Algorithm Design: Students learn to design efficient algorithms to solve the sorting problem with limited operations.
  * Data Structures: Understanding and manipulating stack data structures are essential.
  * Optimization: Emphasis on optimizing the number of operations helps students practice writing efficient code.
  * Debugging and Testing: Writing and testing the Checker program enhances debugging skills and ensures the correctness of the Push_swap program.

# Project score:

![](https://blog.kakaocdn.net/dn/ccOHbk/btrmXuGtLet/JzUaL05K8W5AgwZqFkKjC0/img.png)

