# GNL

### Description
May it be a file, stdin, or even later a network connection, I will always need a way to read content line by line

***
### Function


| Function name  | get_next_line |
| ------------- | ------------- |
| Prototype  | `int get_next_line(int fd, char **line;`  |
| Parameters  | <ul><li>file descriptor for reading</li><li>The value of what has been read</li></ul>|
| Return value  | <ul><li>1 :  A line has been read</li><li>0 :  EOF has been reached</li><li>-1 :  An error happened</li></ul>|
| External functs.  | read, malloc, free  |
