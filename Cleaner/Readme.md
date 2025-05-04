Cleaner - очищает 2 списка авиакомпаний от дублирующих значений в параллельных потоках и выводит в 2-х новых файлах.

Файлы читаются и записываются в папке resourcefiles. 

Для запуска необходимо собрать с помощью CMake следующими командами: 

```
mkdir build
cd build
cmake ..https://github.com/DradeHattori/AirlineComparator/blob/main/Cleaner/Readme.txt
cmake build .
```

Для запуска с параметрами: 
```
comparator airline_1 airline_2 
```

Для запуска с консольным вводом:
```
comparator 
```

Вместо comparator - необходимо написать полный или относительный путь до программы
