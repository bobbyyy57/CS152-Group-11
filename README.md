# CS152-Group-11 Language Specification
## Name - :rofl:
## Extension For Files - .rofl
## Compiler Name - roflCC (The rofl Compiler Collection)
| Language Feature | Code Example |Markdown Example |
| ---------------- | ------------ | --------------- |
| Integer Scalar Variables | `:1234:` x; `:1234:` y; `:1234:` z, avg; |:1234: x; :1234: y; :1234: z, avg;
| One-dimensional arrays of integers | `:card_index:` `:1234:` `:five:` arrayOfIntegersWithSizeEight; <br />`:card_index:` `:1234:` `:five:` arrayOfIntegersWithSizeFive; | 📇 🔢 8️⃣ arrayOfIntegersWithSizeEight; <br /> 📇 🔢 5️⃣ arrayOfIntegersWithSizeFive; |
| Assignment Statements | x `:point_right:` 8; <br /> y `:point_right:` 7; |x 👉 8; <br /> y 👉 7; |
| Arithmetic Operators | x `:heavy_plus_sign:` y; <br /> x `:heavy_minus_sign:` y; <br /> x `:heavy_multiplication_x:` y; <br /> x `:heavy_division_sign:` y; | x ➕ y; <br /> x ➖ y; <br /> x ✖️ y; <br /> x ➗ y;|
| Relational Operators | x `:arrow_forward:`y (x greater than y) ; <br /> x `:arrow_backward:` y (x less than y) ;  <br /> x `:point_right:` `:point_right:` y (x equals y) ; <br /> x `:exclamantion:` `:point_right:` y (x does not equal y) ; | x▶️y (x greater than y) ; <br /> x ◀️ y (x less than y) ; <br /> x 👉 👉 y (x equals y) ; <br /> x ❗👉 y (x does not equal y) ; | 
| While or Do-While Loops | `:repeat:`[x `:arrow_backward:` 8] : {} <br />(do while x is less than 8) |  🔁[x ◀️ 8] : (do while x is less than 8) | 
| If-then-else statements | `:vertical_traffic_light:` [x `:arrow_backward:` 5] {} <br />(if x is less than five) <br /> `:traffic_light:` [x `:arrow_backward:` 7] {} <br /> (else if x is less than 7) <br /> `:vertical_traffic_light:` {} (else) |🚦 [x ◀️ 5] {} (if x is less than five) <br /> 🚥 [x ◀️ 7] {} (else if x is less than 7) <br />🚦 {} (else) |
| Read and write statements | `:desktop_computer:` x (print x); <br /> `:keyboard:` (Read following variable); | 🖥️ x (print x); <br /> ⌨️ (Read following variable); |
| Comments | `(comment goes here)` | `(comment goes here)` |
| Functions | `:1234:` `:symbols:`[ `:1234:`x `:1234:`y] <br /> (function that takes in two ints and returns an int) (function symbol is `:symbols:` )| 🔢🔣[ 🔢x 🔢y] { (code) } <br /> (function that takes in two ints and returns an int) (function symbol is 🔣) |

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
| `{` | { | LEFT_CURLY |
| `}` | } | RIGHT_CURLY |
| `[` | [ | LEFT_SQUARE |
| `]` | ] | RIGHT_SQUARE |
| `(` | ( | LEFT_PARENTHESIS |
| `)` | ) | RIGHT_PARENTHESIS |
| `:` | : | COLON |
| `;` | ; | SEMICOLON |

