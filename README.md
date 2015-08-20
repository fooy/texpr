a simple expression implemented by bison(C++) and flex


compile:
    make

demo:
```bash
$ ./texpr 'int1'
ret : 123
$ ./texpr 'int1 + 2.1 == 125.1 && 5.1/2 == 2.5'
ret : FALSE
$ ./texpr '2 * int1 / 2.0 '
ret : 123.000000
$ ./texpr 'print( str2 == "456")'
TRUE 
ret : 1
$ ./texpr 'int1 + str2 != "123456"? "equal" : STRLEN(str2)==0?3*7: "return" '
ret : "return"
$ ./texpr '1 + 2 * 3 & 8'
ret : 0
$ ./texpr 'TRIM("  " + this.is.array[1] ) + " ok"+ ( STRLEN("hello")+10 )'
ret : "789 ok15"

```
