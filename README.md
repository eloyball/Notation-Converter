# Notation Converter
This GitHub repository hosts a C++ project aimed at implementing a Deque (Double-Ended Queue) and utilizing it to create a versatile mathematical notation converter. The project supports three common notations: Postfix (Reverse Polish), Infix (standard notation), and Prefix (Polish). The converter can seamlessly transform expressions from one notation to another, with input strings containing standard arithmetic operators, operands denoted by letters, and round parentheses (only in infix expressions).
# Example Usage
### Postfix to Infix:
- Input: "c d / a b * r r * / *"
- Output: Infix: ((c / d) * ((a * b) / (r * r)))
### Postfix to Prefix:
- Input: "c d / a b * r r * / *"
- Output: Prefix: * / c d / * a b * r r
### Prefix to Infix:
- Input: "* + A B - C D"
- Output: Infix: ((A + B) * (C - D))
### Prefix to Postfix:
- Input: "* + A B - C D"
- Output: Postfix: A B + C D - *
### Infix to Postfix:
- Input: "((a / f) ((a * b) / (r * r)))"
- Output: Postfix: a f / a b * r r * /
### Infix to Prefix:
- Input: "((a / f) ((a * b) / (r * r)))"
- Output: Prefix: / a f / * a b * r r
