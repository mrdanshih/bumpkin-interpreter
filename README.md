# bumpkin_interpreter
A simple programming language interpreter written in C++ for a small subset of the BASIC programming language, called Bumpkin.

The interpreter supports the following commands:

| Command     | Operation |
|-------------|-----------|
| RUN         | Runs a given Bumpkin program file |
| TRACE       | Traces a given Bumpkin program file (prints the lines being executed) |
| INTERPRET   | Accepts a series of lines representing a Bumpkin program file in the console, and executes it. |
| EXIT        | Exit the interpreter |

### Example Run
```
> RUN basic_prog.txt 
3
3
-10
3
-7
13
0
> TRACE basic_prog.txt 
||| 1 | LET A 3
||| 2 | PRINT A
3
||| 3 | LET B A
||| 4 | PRINT B
3
||| 5 | LET A -10
||| 6 | LET C B
||| 7 | ADD C A
||| 8 | PRINT A
-10
||| 9 | PRINT B
3
||| 10 | PRINT C
-7
||| 11 | LET D B
||| 12 | SUB D A
||| 13 | PRINT D
13
||| 14 | DIV D 99
||| 15 | PRINT D
0
||| 16 | .
> INTERPRET
READY. Enter Bumpkin code line by line, finish with a . character
LET FOO -10
LET BAR 5
GOSUB MYSTERY
GOSUB PRINTVARS
END
MYSTERY: DIV FOO -1
         MULT FOO BAR
         SUB BAR 1
         GOSUB PRINTVARS             
         IF BAR > 0 THEN MYSTERY
         RETURN
PRINTVARS: PRINT FOO
           PRINT BAR
           RETURN
.
50
4
-200
3
600
2
-1200
1
1200
0
1200
0
> 
```
### The Bumpkin language
Bumpkin programs consist of statements, one per line. All programs end with a . indicating the end of the Bumpkin program.
Lines have line numbers associated with them (starting with 1) and optionally, a label preceeding them.
Example:
```
        LET A 3
        PRINT A
        GOSUB CHUNK
        PRINT A
        PRINT B
        GOTO FINAL
CHUNK:  LET A 4
        LET B 6
        RETURN
FINAL:  PRINT A
        .
```
The following is a summary of supported statements in the Bumpkin language. In the repo, there are a few sample programs demonstrating these statements.
### Supported Statements
<table class="normal">
  <tr class="top">
    <td>Statement</td>
    <td>Description</td>
  </tr>
  <tr>
    <td>LET <i>var</i> <i>value</i></td>
    <td>Changes the value of the variable <i>var</i> to the given <i>value</i>, which will either be an integer constant or the name of another variable.</td>
  </tr>
  <tr>
    <td>PRINT <i>value</i></td>
    <td>Prints the given <i>value</i> to the console; the value will be either an integer constant or the name of a variable.</td>
  </tr>
  <tr>
    <td>ADD <i>var</i> <i>value</i></td>
    <td>Adds the given <i>value</i> to the value of the variable <i>var</i>, where the value will be either an integer constant or the name of another variable.</td>
  </tr>
  <tr>
    <td>SUB <i>var</i> <i>value</i></td>
    <td>Subtracts the given <i>value</i> to the value of the variable <i>var</i>, where the value will be either an integer constant or the name of another variable.</td>
  </tr>
  <tr>
    <td>MULT <i>var</i> <i>value</i></td>
    <td>Multiplies the given <i>value</i> to the value of the variable <i>var</i>, where the value will be either an integer constant or the name of another variable.</td>
  </tr>
  <tr>
    <td>DIV <i>var</i> <i>value</i></td>
    <td>Divides the given <i>value</i> to the value of the variable <i>var</i>, where the value will be either an integer constant or the name of another variable.</td>
  </tr>
  <tr>
    <td>GOTO <i>line</i></td>
    <td>Jumps execution of the program to the given <i>line</i> (which will be specified as either a line number or a label).</td>
  </tr>
  <tr>
    <td>IF&nbsp;<i>value1</i>&nbsp;<i>op</i>&nbsp;<i>value2</i>&nbsp;THEN&nbsp;<i>line</i></td>
    <td>Compares the value <i>value1</i> to the value <i>value2</i> using the relational operator <i>op</i> (=, &lt;&gt;, &lt;, &lt;=, &gt;, &gt;=).  <i>value1</i> and <i>value2</i> will either be the value of a variable or an integer constant.  If the comparison is true, jumps execution of the program to the given <i>line</i> (which will be specified either as a line number or a label).  If not, this statement has no effect.</td>
  </tr>
  <tr>
    <td>GOSUB <i>line</i></td>
    <td>Temporarily jumps to the given <i>line</i> (which will be specified as either a line number or a label).  A RETURN statement will cause execution to jump back to the line following the GOSUB.</td>
  </tr>
  <tr>
    <td>RETURN</td>
    <td>Jumps execution of the program back to the line following the most recently-executed GOSUB statement.</td>
  </tr>
  <tr>
    <td>END</td>
    <td>Ends the program immediately.</td>
  </tr>
  <tr>
    <td>.</td>
    <td>Special marker that indicates the end of the program text.  Behaves as an END statement when encountered.</td>
  </tr>
</table>






