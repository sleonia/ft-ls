ft_ls
> What it is?

A recoding of the **Unix** command `ls`.  
This project is about discovering a sub-system of functions of the system's **API**, the associated **data structures**, **sort algorithm**, as well as **memory allocation** and **data management**.

> How to build?
```
mkdir build
cd build
cmake ..
make
./ft_ls ls [-Rrlatgm1fi] [file ...]
```

> How to read documentation?
```
brew install doxygen
doxygen
open doxygen/html/index.html
```
---
The behavior of the program is almost identical to `ls`, only without some flags. However, the original `ls` contains a number of undefined behavior, so you can use for clarification
```
man ls
```
> Authors  
[me](https://github.com/sleonia)  
[Mcluckinson](https://github.com/Mcluckinson/)
