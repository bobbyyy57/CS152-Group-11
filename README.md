# CS152-Group-11 Language Specification
## Name - :rofl:
## Extension For Files - .rofl
## Compiler Name - roflCC (The rofl Compiler Collection)
| Language Feature | Code Example |
| ---------------- | ------------ |
| Integer Scalar Variables | :1234: x; :1234: y; :1234: z, avg;
| One-dimensional arrays of integers | 📇 🔢 8️⃣ arrayOfIntegersWithSizeEight; 📇 🔢 5️⃣ arrayOfIntegersWithSizeFive; |
| Assignment Statements | x :heavy_equals_sign: 8; y :heavy_equals_sign: 7; |
| Arithmetic Operators | x ➕ y; x ➖ y; x ✖️ y; x ➗ y;|
| Relational Operators | x▶️y (x greater than y) ; x ◀️ y (x less than y) ; x :heavy_equals_sign: :heavy_equals_sign: y (x equals y) ; x ❗ :heavy_equals_sign: y (x does not equal y) ; | 
| While or Do-While Loops | 🔁[x ◀️ 8] : (do while x is less than 8); | 
| If-then-else statements | 🚦 [x ◀️ 5] : (if x is less than five) 🚥 [x ◀️ 7] : (else if x is less than 7) 🚦 : (else) |
| Read and write statements | 🖥️ x (print x); ⌨️ (Read following variable); |
| Comments | (comment goes here) |
| Functions | 🔢🔣[ 🔢x 🔢y] { (code) }  (function that takes in two ints and returns an int) (function symbol is 🔣) |

##Valid Identifier - Variable names can't contain a ":", as this is used to denote the start and end of a token
##Case Sensitive - Language not case sensitive
##Whitespaces - Whitespaces are ignored

| Symbol In Language | Token Name |
| 🔢 | INTEGER |
| 🔡 | STRING |
| 📇 | ARRAY |
