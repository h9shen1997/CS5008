# Lab 6: Testing with Google Test suite
## CS 5008: Spring 2022

This lab walks through setting up and utilizing the Google Test framework for C and C++. 

The details are in the lab write-up, but here's an overview: 

* Run ```make``` to build the program and install the Google library. 
* Run ```make test``` to run the test suite. 

Now, go through the code in ```example1.c``` and ```test_example.cc``` to 
find instructions on what to change. An easy way to find everything is 
to use the following command: 

```
grep STEP *.c *.cc
```

### STEP0
Running ```make all``` and ```./test_suite``` and below is the output after running ```./test_suite```:
```
haotianshen@haotians-mbp lab6 % ./test_suite
[==========] Running 4 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from Foobar
[ RUN      ] Foobar.SomeFunction
[       OK ] Foobar.SomeFunction (0 ms)
[----------] 1 test from Foobar (0 ms total)

[----------] 2 tests from Example1
[ RUN      ] Example1.SumTwoNumbers
[       OK ] Example1.SumTwoNumbers (0 ms)
[ RUN      ] Example1.MultiplyTwoNumbers
[       OK ] Example1.MultiplyTwoNumbers (0 ms)
[----------] 2 tests from Example1 (0 ms total)

[----------] 1 test from NEW_FUNCTION
[ RUN      ] NEW_FUNCTION.STRING_PREFIX
test_example1.cc:68: Failure
Value of: StringStartsWith("foo2", "foo2bar")
  Actual: true
Expected: false
got to this point
[  FAILED  ] NEW_FUNCTION.STRING_PREFIX (0 ms)
[----------] 1 test from NEW_FUNCTION (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 3 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] NEW_FUNCTION.STRING_PREFIX

 1 FAILED TEST
```
The parameters of the TEST function is conactenated with a . in the output to represent the function within the test/test suite we are testing.


### STEP1
I have changed num_one to 2 and num_two to 3. Below is the new output:
```
haotianshen@haotians-mbp lab6 % ./test_suite
[==========] Running 4 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from Foobar
[ RUN      ] Foobar.SomeFunction
[       OK ] Foobar.SomeFunction (0 ms)
[----------] 1 test from Foobar (0 ms total)

[----------] 2 tests from Example1
[ RUN      ] Example1.SumTwoNumbers
test_example1.cc:40: Failure
      Expected: res
      Which is: 5
To be equal to: 9
[  FAILED  ] Example1.SumTwoNumbers (0 ms)
[ RUN      ] Example1.MultiplyTwoNumbers
[       OK ] Example1.MultiplyTwoNumbers (0 ms)
[----------] 2 tests from Example1 (0 ms total)

[----------] 1 test from NEW_FUNCTION
[ RUN      ] NEW_FUNCTION.STRING_PREFIX
got to this point
[       OK ] NEW_FUNCTION.STRING_PREFIX (0 ms)
[----------] 1 test from NEW_FUNCTION (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 3 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] Example1.SumTwoNumbers

 1 FAILED TEST
```
The test has failed because the expected result is 2 + 3 = 5, instead of the previous 9. We can change the second parameter in the EXPECT_EQ to 5, and the test will pass again.

### STEP2
I have changed the expected value to 15, and below is the new output:
```
haotianshen@haotians-mbp lab6 % ./test_suite
[==========] Running 4 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from Foobar
[ RUN      ] Foobar.SomeFunction
[       OK ] Foobar.SomeFunction (0 ms)
[----------] 1 test from Foobar (0 ms total)

[----------] 2 tests from Example1
[ RUN      ] Example1.SumTwoNumbers
[       OK ] Example1.SumTwoNumbers (0 ms)
[ RUN      ] Example1.MultiplyTwoNumbers
test_example1.cc:51: Failure
      Expected: res
      Which is: 20
To be equal to: 15
[  FAILED  ] Example1.MultiplyTwoNumbers (0 ms)
[----------] 2 tests from Example1 (0 ms total)

[----------] 1 test from NEW_FUNCTION
[ RUN      ] NEW_FUNCTION.STRING_PREFIX
got to this point
[       OK ] NEW_FUNCTION.STRING_PREFIX (0 ms)
[----------] 1 test from NEW_FUNCTION (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 3 test cases ran. (1 ms total)
[  PASSED  ] 3 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] Example1.MultiplyTwoNumbers

 1 FAILED TEST
```
GoogleTest showed the name of the test failed and pointed out the line this error occurred in the code, which is test_example1.cc line 51. It also showed the expected result with the actual result.

### STEP3
I have added a function ReverseString, which reverse the given string and return a new copy of the reversed string. See example1.h line 32 for details.

### STEP4
See example1.c line 61 for details.

### STEP5
See test_example1.cc line 71 for details of test. Four test cases have all passed and no memory leak. The final output is as below:
```
haotianshen@haotians-mbp lab6 % ./test_suite
[==========] Running 5 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from Foobar
[ RUN      ] Foobar.SomeFunction
[       OK ] Foobar.SomeFunction (0 ms)
[----------] 1 test from Foobar (0 ms total)

[----------] 2 tests from Example1
[ RUN      ] Example1.SumTwoNumbers
[       OK ] Example1.SumTwoNumbers (0 ms)
[ RUN      ] Example1.MultiplyTwoNumbers
[       OK ] Example1.MultiplyTwoNumbers (0 ms)
[----------] 2 tests from Example1 (0 ms total)

[----------] 2 tests from NEW_FUNCTION
[ RUN      ] NEW_FUNCTION.STRING_PREFIX
[       OK ] NEW_FUNCTION.STRING_PREFIX (0 ms)
[ RUN      ] NEW_FUNCTION.REVERSE_STRING
[       OK ] NEW_FUNCTION.REVERSE_STRING (0 ms)
[----------] 2 tests from NEW_FUNCTION (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 5 tests.
```

### Who did I work with?
Nobody.

### How long did this take you?
40 minutes.