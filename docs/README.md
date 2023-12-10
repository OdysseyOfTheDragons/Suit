# Language overview

This documentation, which may not be the last of date, tries to define
the grammar of the language.

## Reserved keywords

The following keywords are reserved and can't be used as variable names:

Base functions:
* exit
* help
* version
* author
* license
* define

Mathematical functions:
* create
* derive
* add
* multiply
* print

Modifiers:
* @no\_extra
* @beauty\_print

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
