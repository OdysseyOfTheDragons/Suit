# Suit 💼

An interpreted language to play with polynomials.

The brand new mathematical language. One you will love.

## Language features

* Easily create polynomials
* Derive your polynomials
* Evaluate your polynomials
* Multiply, add...
* List your polynomials
* Load `.suit`  file to evaluate (as a standalone program)

## Language style

1. Create a polynomial
```c
$ define polynomial = create (0 1 2)
POLYNOMIAL: polynomial = 2x^2 + x
```
2. Derive
```c
$ derive (polynomial)
POLYNOMIAL: () = 4x + 1
$ define holynomial = derive (derive (polynomial))
POLYNOMIAL: holynomial = 4
```

3. Print
```c
$ print (holynomial)
POLYNOMIAL: holynomial = 4
```

5. Multiply/add...
```c
$ add (create (2 2 2)) (create (3 2 1 0))
POLYNOMIAL: 3x^2 + 4x + 5
$ multiply (create (2 2 2)) (multiply (create (1)) (create (2)))
POLYNOMIAL: 4x^2 + 4x + 4
```

7. List your polynomials
8. Chain instructions

## Flexibility

You don't like the `POLYNOMIAL: ...`  text each time you execute an action?

No worries, it can be easily configured through special commands:

* `@no_extra`: Disables the `POLYNOMIAL: ...` on each action
* `@beauty_print`: Changes the print output format from
  `POLYNOMIAL: polynomial = x^2 + 2` to `x^2 + 2`

## Contributions

We do accept contributions from you all, but under conditions.

1. Is the contribution relevant?
2. Does it follow the spirit of the language?
3. Is it *your* code, and not some copied code?
4. Does it improve the already existing code?

If it answers all these questions with "*yes*", then you can contribute
using the following:

* Fork the project
* Create your branch (`git checkout -b feature/AddingWhat`)
* Commit your changes (`git commit -m "Add feature AddingWhat"`)
* Push your branch (`git push origin feature/AddingWhat`)
* Open a pull request
