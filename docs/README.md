# Language overview

This documentation, which may not be the last of date, tries to define
the grammar of the language.

## Reserved keywords

The following keywords are reserved and can't be used as variable names:

Base functions:
* `exit`
* `help`
* `version`
* `author`
* `license`
* `define`

Mathematical functions:
* `create`
* `derive`
* `add`
* `multiply`
* `print`

Modifiers:
* `@no_extra`
* `@beauty_print`

## Language features

### Modifiers

#### `@no_extra`

Put this on a line, and all following actions won't print the result
on the action on the line.

For example:
```c
$ define poly = create (0 0 1)
POLYNOMIAL: poly = x^2
$ @no_extra
$ define poly2 = create (0 0 1)
$ print (poly2)
POLYNOMIAL: poly2 = x^2
```

If you want to get back this extra later, you may add an additional `false`
after the command.

From the example above:
```c
$ @no_extra
$ define poly = create (0 0 1)
$ @no_extra false
$ define poly2 = create (0 0 1)
POLYNOMIAL: poly2 = x^2
```

#### `@beauty_print`

The base `print` command gives a lot of information, like the name of the
variable printed. But you can use this modifier to change that.

Like the modifier above, it can be reverted using the optionnal `false`
argument.

For example:
```c
$ define poly = create (0 0 1)
POLYNOMIAL: poly = x^2
$ print (poly)
POLYNOMIAL: poly = x^2
$ @beauty_print
$ print (poly)
x^2
$ @beauty_print false
$ print (poly)
POLYNOMIAL: poly = x^2
```

### Base functions

#### exit

In case you are in the REPL and want to quit, you just need to type
`exit` to... exit.

For example:
```c
$ exit
```

#### version, author

In case you want to get the actual version, or some details on the author
(me), you may type exactly `version`  or `author`.

#### license

You may print the license in your program, using the `license` keyword.

The license won't be directly printed, as it is long, but it will
print a link you can follow.

#### help

You may know where this command leads, if you're here, because the `help`
command redirects you to this documentation.

### Mathematical functions

The language proposes a lot of built-in functions to manipulate polynomials.

As of yet, there is still no way to define additional functions, conditionnals
or something else. This is partly intended, as this is not a language
to use, but more of a toy to use for mathematical functions.

Please note than in all the following functions, spaces are important and
can't be put out. This may be a hindrance to some, but this is part of
the language design and enforces a set of rules, like the ones in
mathematics.

#### `define`

This is the keyword to define a variable, and affect it at the same way.

The grammar is like: `$ define [variable-name] = [evaluation]`

Some more information:
* a _valid_ `variable-name` is a suite of characters that respect the
following guidelines:
    * the first letter is either a letter (`a-z` or `A-Z`) or a special
character (`$#_!?-`)
    * the following characters are either a letter (`a-z` or `A-Z`), a digit
(`0-9`) or a special character (`$#_!?-` or `|@`)
    * the last letters may be one or more single quotes (`'`) to act as a prime
(this does not modify a thing, except the simpler perception of `f'`
compared to `f_prime`)
* an `evaluation` is one of the following functions presented later

For example, the following lines are correct:
```c
$ define polynomial = create (0 1 1)
$ define $f = create (1 1 1 0)
$ define $f' = derive ($f)
$ define $f'' = derive ($f')
```

But the following are invalid:
```c
$ def polynomial = create (0 11 1)
$ let polynomial = create (0 1 1)
$ define 'f = create (0 1 1)
$ define @f{ = create (1)
$ f is defined by create (1)
```

If you do not understand why these definitions are invalid, please read one
more time the definition of the grammar.

#### `print`

This may seem strange to put this function at the beginning, but this function
is useful to understand a lot of the functionalities of the language.

Note: this function isn't an evaluation, and can't be used with the `define`
keyword.

Grammar: `print ([variable-name])` or `print string ("[string]")`

The `variable-name` is a valid one, as defined with the `define` keyword. This
variable must have _first_ been defined with the `define` keyword. If the
variable is unknow, you will get an error.

The other option is to print a string with a newline.

For example, the following lines are correct:
```c
$ define p = create (0 1 1)
$ print (p)
$ print string ("The parentheses and quotes are needed.")
$ print string ("I included the define line, as it shows the `print`")
$ print string ("needs an already defined polynomial to print it.")
```

This will produce the following output:
```bash
POLYNOMIAL: p = x^2 + x
POLYNOMIAL: p = x^2 + x
The parentheses and quotes are needed.
I included the define line, as it shows the `print`
needs an already defined polynomial to print it.
```

(the first line is the output from the `define` call)

Using the modifiers, the output can be changed:
```c
$ @beauty_print
$ @no_extra
$ define p = create (0 1 1)
$ print (p)
```
gives the output
```bash
x^2 + x
```
