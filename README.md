# CS452 Project 1

Name: Gage Wilson
Term: Spring 2025

## Overview
This is a basic implementation of a circular doubly linked list with a sentinel node written in C. It has some of the basic operations and basic functionality has been tested.

## Reflection
It's been a long time since I've written any C code. I hadn't written any C since Spring 2023 when I took CS 253, so it took me a little bit to get used to writing in C again. Although after completing this project I remembered how much I enjoyed writing in C and I'm excited to tackle the future projects in this course. Low level stuff is really interesting to me, despite how difficult I've heard that this course is, I'm really excited to learn more low level concepts.

There wasn't anything in particular that was super difficult for this project other than just getting used to C again. After I implemented some of the easier functions, it all started to come back to me and then I was able to wrap up the project relatively quickly. I did run into some issues with compiling and running on Windows and WSL, but I found it's easier to just write C on a Linux system, which is what I will be using for the rest of the projects in this course.

## Building

To build the source files run this command in the root folder of the project directory
```bash
make
```

## Testing

To compile the suite of tests to test the circular doubly linked list functionality, run this command in the root of the project directory

```bash
make check
```

## Clean

To clean up the compiled files, run this command in the root of the project directory:

```bash
make clean
```

## Install Dependencies

In order to use git send-mail you need to run the following command:

```bash
make install-deps
```
