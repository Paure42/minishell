
# Table of Contents

1.  [Project](#orga753e53)
2.  [Built-in](#org7c63e9d)
3.  [Features](#org26eb46d)
4.  [Usage](#orgf012f67)



<a id="orga753e53"></a>

# Project

Create a simple shell by reproducing some functionnalities of bash.


<a id="org7c63e9d"></a>

# Built-in

-   `echo` and it&rsquo;s option &rsquo;-n&rsquo;

-   `cd` with absolute or relative path

-   `pwd` without any options

-   `export` without any options

-   `unset` without any options or arguments

-   `env` without any options or arguments

-   `exit` without any options

-   &rsquo;*;*&rsquo; separates the commands

-   &rsquo;*&rsquo;*&rsquo; and &rsquo;*&ldquo;*&rsquo; work the same as bash except for multiline

-   &rsquo;*<*&rsquo; and &rsquo;*>* and &rsquo;*>>*&rsquo; work the same as bash

-   &rsquo;*|*&rsquo; work the same as bash

-   environment variables followed by &rsquo;*$*&rsquo; work the same as bash

-   &rsquo;*$?*&rsquo; work the same as bash

-   *ctrl-C, ctrl-D and ctrl-\\* display the same result as bash


<a id="org26eb46d"></a>

# Features

-   Prompt

-   Look for the right executable in the PATH environment


<a id="orgf012f67"></a>

# Usage

`make` to build the project
`make fclean` to clean the project
`./minishell` to run the executable.

