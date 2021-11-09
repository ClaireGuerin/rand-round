# Random rounding
Random rounding of floating-point numbers with probability of ceiling vs flooring proportional to decimal. For Xiaoyan's code.

## Examples

- `7.5` becomes `7` (floored) with 50% chance, and becomes `8` (ceiled) with 50% chance.
- `6.6` becomes `6` (floored) with 40% chance, and becomes `7` (ceiled) with 60% chance.
- `-2.3` becomes `-2` (floored) with 30% chance, and becomes `-3` (ceiled) with 70% chance.

## How to use

`src/Round.hpp` contains the function `randround::round`, which takes as arguments the value to be rounded stochastically, and the random number generator.

`main.cpp` is an example use of that function. It feeds it the `std::default_random_engine` and calls it multiple times (10'000) on different values (`7.5`, `6.6`, `-2.3`). It then prints the percentage of flooring versus ceiling in each case.

## Result

Random rounding of 7.5:  
 7 ************ 50.06%  
 8 ************ 49.94%  
Random rounding of 6.6:  
 6 ********* 39.46%  
 7 *************** 60.54%  
Random rounding of -2.3:  
-3 ******* 30.17%  
-2 ***************** 69.83%  
