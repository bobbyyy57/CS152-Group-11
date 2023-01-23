# CS152-Group-11 Language Specification
## Name - :rofl:
## Extension For Files - .rofl
## Compiler Name - roflCC (The rofl Compiler Collection)
| Language Feature | Code Example |
| ---------------- | ------------ |
| Integer Scalar Variables | :1234: x; :1234: y; :1234: z, avg;
| One-dimensional arrays of integers | 📇 🔢 8️⃣ arrayOfIntegersWithSizeEight; 📇 🔢 5️⃣ arrayOfIntegersWithSizeFive; |
| Assignment Statements | x 👉 8; y 👉 7; |
| Arithmetic Operators | x ➕ y; x ➖ y; x ✖️ y; x ➗ y;|
| Relational Operators | x▶️y (x greater than y) ; x ◀️ y (x less than y) ; x 👉 👉 y (x equals y) ; x ❗ 👉 y (x does not equal y) ; | 
| While or Do-While Loops | 🔁[x ◀️ 8] : (do while x is less than 8); | 
| If-then-else statements | 🚦 [x ◀️ 5] {} (if x is less than five) 🚥 [x ◀️ 7] {} (else if x is less than 7) 🚦 {} (else) |
| Read and write statements | 🖥️ x (print x); ⌨️ (Read following variable); |
| Comments | (comment goes here) |
| Functions | 🔢🔣[ 🔢x 🔢y] { (code) }  (function that takes in two ints and returns an int) (function symbol is 🔣) |

##Valid Identifier - Variable names can't contain a ":", as this is used to denote the start and end of a token
##Case Sensitive - Language not case sensitive
##Whitespaces - Whitespaces are ignored

| Code | Symbol In Language | Token Name |
| ---- | ------------------ | ---------- |
| `:1234:` | 🔢 | INTEGER |
| `:abcd:` | 🔡 | STRING |
| `:card_index:` | 📇 | ARRAY |
| `:one:` | :one: | ONE |
| `:two:` | 2️⃣ | TWO |
| `:three:` | 3️⃣ | THREE |
| `:four:` | 4️⃣ | FOUR |
| `:five:` | 5️⃣ | FIVE |
| `:six:` | 6️⃣ | SIX |
| `:seven:` | 7️⃣ | SEVEN |
| `:eight:` | 8️⃣ | EIGHT |
| `:nine:` | 9️⃣ | NINE |
| `:symbols:` | 🔣 | FUNCTION |
| `:heavy_plus_sign:` | ➕ | PLUS |
| `:heavy_minus_sign:` | ➖ | MINUS |
| `:heavy_multiplication_x:` | ✖️ | MULTIPLICATION |
| `:heavy_division_sign:` | ➗ | DIVISION |
| `:point_right` | 👉 | EQUAL |
| `:arrow_forward:` | ▶️ | GREATER_THAN |
| `:arrow_backward:` | ◀️ | LESS_THAN |
| `:exclamation:` | ❗ | NOT |
| `:repeat:` | 🔁 | WHILE |
| `:vertical_traffic_light:` | 🚦 | IF |
| `:traffic_light:` | 🚥 | ELSE |
| `:desktop_computer:` | 🖥️ | READ |
| `:keyboard:` | ⌨️ | WRITE |
| `:desktop_computer:` | 🖥️ | READ |
| `{` | { | LEFT_CURLY |
| `}` | } | RIGHT_CURLY |
| `[` | [ | LEFT_SQUARE |
| `]` | ] | RIGHT_SQUARE |
| `(` | ( | LEFT_PARENTHESIS |
| `)` | ) | RIGHT_PARENTHESIS |
| `:` | : | COLON |
| `;` | ; | SEMICOLON |

