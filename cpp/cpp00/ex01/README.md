	
```

    int input;
    
    if (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid input." << std::endl;
    }

```

If cin doesn't receive an int it returns 0 and then the codeblock gets executed. 

cin.clear clears the error flag on cin (so cin may be used again).

cin.ignore will clear/ignore 10000 chars(or bits/bytes?) from the buffer and skip to a newline. 
If input is more then 10000 chars it will give another parsing failure.


```

    std::cout << std::setfill(' ') << std::setw(10);

```

std::setfill sets the fill character for the whatever you point it to. Default is ' ' so this code is not necessary. 
std::setw() sets the width of whatever you point it to. 
