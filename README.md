
# Table of Contents

1.  [Project](#org28da86f)
2.  [Built-in](#org1a88eec)
3.  [Features](#org7d22d86)
4.  [Usage](#org76ac2a0)



<a id="org28da86f"></a>

# Project

Create a simple shell by reproducing some functionnalities of bash.


<a id="org1a88eec"></a>

# Built-in

-   `echo` and it&rsquo;s option &rsquo;-n&rsquo;

-   `cd` with absolute or relative path

-   `pwd` without any options

-   `export` without any options

-   `unset` without any options or arguments

-   `env` without any options or arguments

-   `exit` without any options

-   *&rsquo;;&rsquo;* separates the commands

-   *&rsquo;&rsquo;&rsquo;* and *&rsquo;&ldquo;&rsquo;* work the same as bash except for multiline

-   *&rsquo;<&rsquo;* and *&rsquo;>&rsquo;* and *&rsquo;>>&rsquo;* work the same as bash

-   *&rsquo;|&rsquo;* work the same as bash

-   environment variables followed by *&rsquo;$&rsquo;* work the same as bash

-   *&rsquo;$?&rsquo;* work the same as bash

-   *ctrl-C, ctrl-D and ctrl-\\* display the same result as bash


<a id="org7d22d86"></a>

# Features

-   Prompt

-   Look for the right executable in the PATH environment


<a id="org76ac2a0"></a>

# Usage

`make` to build the project

`make fclean` to clean the project

`./minishell` to run the executable.

