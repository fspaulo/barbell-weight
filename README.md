# barbell-weight
### The objective of this program is represent the weight plates in a barbell.

- The weight plates to be used are: [25, 20, 15, 10, 5, 2.5, 2, 1.5, 1, 0.5] *Kilograms (kg)*;
- The only plate that can be stacked more than once is the 25kg. The rest are for closing the required weight;
- The order of the weight plates will always be from the largest (heaviest) to the smallest;
- So each time there is a weight change, you will need to check the top of the stack and adjust accordingly;
  stacking the new plate, or unstacking the plate until the highest number fits;


- **_Example:_** 
  - if the barbell has the weights [25, 20, 2.5, 0.5] – adding 48, passing to 49,
    you will need to remove the 0.5 plate and put in a 1.5 plate [25, 20, 2.5, 1.5]. Going to 50, it will be [25, 25].
