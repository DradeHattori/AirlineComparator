Comparator - сравнивает 2 кода авиалиний без лишних символов (0, спецсимволов, пробелов). Работает как с параметрами командной строки так и с консольным вводом. 

Сборка с помощью CMake следующими командами: 

```
mkdir build
cd build
cmake ..
cmake build .
```

Для запуска с параметрами:
```
comparator  airline_1 airline_2 
```

Для запуска с консольным вводом:
```
comparator
```

Вместо comparator - необходимо написать полный или относительный путь до программы
